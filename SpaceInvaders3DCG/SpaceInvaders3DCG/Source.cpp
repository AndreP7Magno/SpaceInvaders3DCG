#include "stdafx.h"
#include "GL\glew.h"
#include "GL\freeglut.h"
#include <iostream>
#include "alien.h"
#include "bala.h"
#include "escreve.h"
#include "nave.h"
#include "ponto.h"

#pragma region Variáveis Globais

bala Bala[5];
alien Alien[20];
nave Nave;
ponto Ponto;

int contador = 0;
int naveAtingida;
int atingidos;
int nivel = 1;
int tela = 0;
bool direita;
bool avancar;
bool desce;
double camY = 2.0;
double camZ = 7.0;
bool pause = false;

#pragma endregion

void Inicio() {
	for (int i = 0; i < 5; i++) {
		Bala[i] = bala();
	}
	for (int i = 0; i < 20; i++) {
		Alien[i] = alien(Alien[i]); // Coloca cada alien e suas propriedades em uma posição do vetor
		Alien[i].atingido = Alien[i].desenhaAlien = false; // Desenha o alien, colocando a condição de NÃO atingido
		Alien[i].posicaoX = -0.75;
		Alien[i].posicaoY = 0.25;
		Alien[i].posicaoZ = -3.0;
	}

	nave(Nave);
	distribuiAlien(Alien);
	naveAtingida = 0, atingidos = 0;
	direita, desce = true;
	avancar = false;
	Ponto.pontoXEsq = Alien[0].posicaoX;
	Ponto.pontoXDir = Alien[4].posicaoX;
}

void Visualizacao() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (tela == 1)
		gluPerspective(30, 1, 1, 100);
	else
		glOrtho(-3, 3, -3, 3, 1, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.5, camY, camZ, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//gluLookAt(0.5, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // Teste camera lateral
}

void DesenhaCena(void) {
	// Limpa a janela com a cor especificada como cor de fundo
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	// Para habilitar a transparência
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel(GL_FLAT);

	//Funcao de visualizacao 3D
	Visualizacao();

	if (tela == 0) {
		Inicio();
		EscreveBV();
		EscreveIniciar();
		EscreveFechar();
		EscreveCreditos();
	}

	if (tela == 1) {
		desenhaNave(Nave);
		//manipulação da bala
		for (int i = 0; i < 5; i++) { //movimento da bala
			if (Bala[i].foiAtirada) {
				if (Bala[i].translacaoZ < -3.5) {
					Bala[i].foiAtirada = false;
					Bala[i].translacaoZ = 0.0;
				}
				else {
					desenhaBala(Bala[i]);
					Bala[i].translacaoZ -= 0.1;
				}
			}
		}

		if (nivel == 3) {
			//movimento em y alien
			for (int i = 0; i < 20; i++) {
				if (desce) {
					Alien[i].posicaoY -= 0.05;
				}
				else {
					Alien[i].posicaoY += 0.05;
				}
			}
		}

		//desenha o alien
		for (int i = 0; i < 20; i++) {
			if (Alien[i].atingido == false)
				desenhaAlien(Alien[i]);
		}

		//movimento do alien em x
		for (int i = 0; i < 20; i++) {
			if (nivel == 1) {
				if (direita) {
					Alien[i].posicaoX += 0.05;
				}
				else {
					Alien[i].posicaoX -= 0.05;
				}
			}
			if (nivel == 2 || nivel == 3) { // manipula nivel
				if (direita) {
					Alien[i].posicaoX += 0.1;
				}
				else {
					Alien[i].posicaoX -= 0.1;
				}
			}
		}

		//movimento em z do alien
		if (avancar == true) {
			for (int i = 0; i < 20; i++) {
				Alien[i].posicaoZ += 0.1;
			}
			avancar = false;
		}

		//manipulação da direção dos pontos de colisão dos aliens com a parede
		if (direita) {
			Ponto.pontoXEsq += 0.1;
			Ponto.pontoXDir += 0.1;
		}
		else
		{
			Ponto.pontoXEsq -= 0.1;
			Ponto.pontoXDir -= 0.1;
		}

		EscrevePontuacaoGeral(contador);
		if (naveAtingida == 1) {//condição da derrota
			tela = 2;
			naveAtingida = 0;
		}
		if (atingidos == 20) {//condição da vitória
			tela = 3;
			atingidos = 0;
		}
	}

	if (tela == 2) {//tela de derrota
		Inicio();
		EscrevePontuacaoGeral(contador);
		EscrevePerdedor();
		EscreveMenuAuxiliar();
	}

	if (tela == 3) {//tela de vitória
		EscrevePontuacaoGeral(contador);
		Inicio();
		if (nivel != 3) {
			EscreveGanhador();
			EscreveMenuAuxiliar2();
		}
		if (nivel == 3) {
			EscreveMenuAuxiliar();
			EscreveMenuFinal();
		}
	}
	glPopMatrix();
	glutSwapBuffers();
}

void Anima(int valor) {
	// Para todos niveis
	if (Ponto.pontoXDir >= 3.2) { //Limita a parede no lado direito
		direita = false;
		avancar = true; //flag pra dizer que vai avançar
	}
	else if (Ponto.pontoXEsq <= -3.4) { //Limita a parede no lado esquerdo
		direita = true;
		avancar = true;
	}

	// Para o nivel 3
	if (Alien[0].posicaoY >= 1.0) {
		desce = true;
	}
	else if (Alien[0].posicaoY <= -1.5) {
		desce = false;
	}

	//colisão alien com a nave e com as balas
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 20; j++) {
			if (0.04 + Alien[j].posicaoZ >= 0 && Alien[j].atingido == false) { //confirma se usuário perdeu o jogo vendo se os aliens chegaram no destino deles;
				naveAtingida = 1;
			}
			if (Bala[i].foiAtirada == true) {
				if (0.2 + Bala[i].translacaoZ >= 0.0 + Alien[j].posicaoZ && 0 + Bala[i].translacaoZ <= 0.04 + Alien[j].posicaoZ) {
					if (0.0125 + Bala[i].translacaoX >= -0.48 + Alien[j].posicaoX && -0.0125 + Bala[i].translacaoX <= -0.02 + Alien[j].posicaoX) {
						if (0.0125 + Bala[i].translacaoY >= 0.38 + Alien[j].posicaoY && -0.0125 + Bala[i].translacaoY <= 0.7 + Alien[j].posicaoY) {
							Alien[j].posicaoX += 100;
							contador += 100;
							atingidos++;
							Bala[i] = bala();
						}
					}
				}
			}
		}
	}

	if (!pause)
		glutPostRedisplay();
	glutTimerFunc(50, Anima, 1);
}

void TeclasDirecionais(int tecla, int x, int y) {
	if (!pause) {
		if (tela == 1) {
			if (tecla == GLUT_KEY_RIGHT) {
				if (Nave.posicaoNaveX <= 1.7)
					Nave.posicaoNaveX += 0.1;
			}
			if (tecla == GLUT_KEY_LEFT) {
				if (Nave.posicaoNaveX >= -1.7)
					Nave.posicaoNaveX -= 0.1;
			}

			if (tecla == GLUT_KEY_UP) {
				if (Nave.posicaoNaveY <= 1.7)
					Nave.posicaoNaveY += 0.1;
			}

			if (tecla == GLUT_KEY_DOWN) {
				if (Nave.posicaoNaveY >= -1.7)
					Nave.posicaoNaveY -= 0.1;
			}
		}
		glutPostRedisplay();
	}
}

void Teclas(unsigned char tecla, int x, int y) {

	// Muda a camera no eixo Z
	if (!pause) {
		if (tela == 1) {
			if (tecla == 97) //A
				camZ = camZ - 0.3;
			else if (tecla == 68 || tecla == 100) //D
				camZ = camZ + 0.3;
			else if (tecla == 119) //W
				camY = camY + 0.3;
			else if (tecla == 115) //S
				camY = camY - 0.3;
		}
	}

	if (tela == 0 || tela == 2 || tela == 3) {
		if (tecla == 122 || tecla == 90) {
			if (tela == 2 || tela == 0 || nivel == 3) {
				contador = 0;
			}

			if (tela == 2)
				nivel = 1;
			if (tela == 3 && nivel == 2) {
				nivel = 3;
			}
			if (tela == 3 && nivel == 1) {
				nivel = 2;
			}

			tela = 1;
		}
		if (tecla == 120 || tecla == 88) { //Se apertar X sai
			exit(0);
		}
	}
	else { //Verifica os tiros
		if (tecla == 32 && !pause) { //Se apertar Espaço atira
			for (int i = 0; i < 5; i++) {
				if (Bala[i].foiAtirada == false) {
					Bala[i].foiAtirada = true;
					Bala[i].translacaoX = Nave.posicaoNaveX; //Bala sai da mesma posição que a nave
					Bala[i].translacaoY = Nave.posicaoNaveY;
					break;
				}

			}
		}
	}

	if (!pause && tecla == 99)
		pause = tecla = 99;
	else if (pause && tecla != 99)
		pause = true;
	else if (tecla == 99)
		pause = false;

	if (!pause)
		glutPostRedisplay();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	// Indica que deve ser usado um unico buffer para armazenamento da imagem e representacao de cores RGB
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 600) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - 600) / 2);
	glutCreateWindow("Space Invaders 3D");

	glutSpecialFunc(TeclasDirecionais);
	glutKeyboardFunc(Teclas);
	glutDisplayFunc(DesenhaCena);
	glutTimerFunc(50, Anima, 1);

	glutMainLoop();
	return 0;
}
