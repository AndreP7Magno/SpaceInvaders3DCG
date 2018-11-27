#pragma once
#include "stdafx.h"
#include "GL\glew.h"
#include "GL\freeglut.h"
#include <iostream>

class escreve {
public:
};

void EscrevePontuacaoGeral(int cont) {
	char texto[12] = "Pontuacao: ";
	char textoPontuacao[20];

	sprintf_s(textoPontuacao, "%d", cont);

	glColor3ub(255, 255, 255);
	glRasterPos3f(1.0, -2.0, 0.0);

	for (int k = 0; k <= strlen(texto); k++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, texto[k]);

	for (int k = 0; k <= strlen(textoPontuacao); k++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, textoPontuacao[k]);
}

void EscrevePerdedor() {
	char texto[11] = "PERDEU!";
	
	glColor3ub(254, 255, 255);
	glRasterPos3f(-0.5, 1.0, 0.0);

	for (int k = 0; k <= strlen(texto); k++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, texto[k]);
}

void EscreveGanhador() {
	char texto[8] = "GANHOU!";

	glColor3ub(255, 255, 255);
	glRasterPos3f(-0.5, 1.0, 0.0);

	for (int k = 0; k <= strlen(texto); k++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, texto[k]);
}

void EscreveMenuFinal() {
	char texto[50] = "PARABENS! Voce zerou o jogo";

	glColor3ub(255, 255, 255);
	glRasterPos3f(-0.5, 1.0, 0.0);

	for (int k = 0; k <= strlen(texto); k++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, texto[k]);
}

void EscreveMenuAuxiliar() {
	char texto[50] = "Aperte Z para Reiniciar ou X para Fechar";

	glColor3ub(255, 255, 255);
	glRasterPos3f(-2.0, -0.7, 0.0);

	for (int k = 0; k <= strlen(texto); k++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, texto[k]);
}

void EscreveMenuAuxiliar2() {
	char texto[150] = "Aperte Z para ir ao proximo nivel ou X para Fechar";

	glColor3ub(255, 255, 255);
	glRasterPos3f(-2.0, -0.7, 0.0);

	for (int k = 0; k <= strlen(texto); k++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, texto[k]);

}

void EscreveBV() {
	char texto[50] = "BEM VINDO AO SPACE INVADERS 3D";

	glColor3ub(255, 255, 255);
	glRasterPos3f(-1.5, 1.5, 0.0);

	for (int k = 0; k <= strlen(texto); k++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, texto[k]);

}

void EscreveIniciar() {
	char texto[50] = "Z --- INICIAR O JOGO";

	glColor3ub(255, 255, 255);
	glRasterPos3f(-1.5, -0.2, 0.0);

	for (int k = 0; k <= strlen(texto); k++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, texto[k]);

}
void EscreveFechar() {
	char texto[50] = "X --- FECHAR O JOGO";

	glColor3ub(255, 255, 255);
	glRasterPos3f(-1.5, -0.6, 0.0);

	for (int k = 0; k <= strlen(texto); k++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, texto[k]);

}

void creditos() {
	char texto[150] = "Criadores: Andre Magno e William Hoffmann";

	glColor3ub(255, 255, 255);
	glRasterPos3f(-2.0, -3.0, 0.0);

	for (int k = 0; k <= strlen(texto); k++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, texto[k]);
}