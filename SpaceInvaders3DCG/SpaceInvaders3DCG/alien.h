#pragma once
#include "stdafx.h"
#include "GL\glew.h"
#include "GL\freeglut.h"
#include <iostream>

class alien {
public:
	alien();

	bool atingido;
	bool desenhaAlien;
	float posicaoX;
	float posicaoY;
	float posicaoZ;
};

alien::alien()
{
	// valores iniciais para os aliens
	atingido = desenhaAlien = false;
	posicaoX = -0.75;
	posicaoY = 0.25;
	posicaoZ = -3.0;
}

void distribuiAlien(alien *a) {
	float transx = a[0].posicaoX;
	float transy = a[0].posicaoY;
	float aux = transx;
	//manipulando os x e y iniciais dos aliens
	for (int i = 0; i < 20; i++) {
		if (transx >= 1.75) {
			transx = aux;
			transy += -0.5;
			a[i].atingido = false;
		}

		if (a[i].atingido == false) {
			if (i == 0) {
				transx = a[i].posicaoX;
				transy = a[i].posicaoY;
			}
			else {
				a[i].posicaoX = transx;
				a[i].posicaoY = transy;
			}
			transx += 0.5;
		}
	}
}


#pragma region Desenhos

void pontaAntenaEsquerda(alien a) {

	glColor3f(0.0, 1.0, 0.6);

	//parte da frente
	glBegin(GL_QUADS);
	glVertex3f(-0.4 + a.posicaoX, 0.7 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.36 + a.posicaoX, 0.7 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.36 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.4 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//parte de trás
	glBegin(GL_QUADS);
	glVertex3f(-0.4 + a.posicaoX, 0.7 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.36 + a.posicaoX, 0.7 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.36 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.4 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.0);
	glEnd();

	//parte de cima
	glBegin(GL_QUADS);
	glVertex3f(-0.4 + a.posicaoX, 0.7 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.36 + a.posicaoX, 0.7 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.36 + a.posicaoX, 0.7 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.4 + a.posicaoX, 0.7 + a.posicaoY, a.posicaoZ + 0.0);
	glEnd();

	//baixo
	glBegin(GL_QUADS);
	glVertex3f(-0.4 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.36 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.36 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.4 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.0);
	glEnd();

	//esquerda
	glBegin(GL_QUADS);
	glVertex3f(-0.36 + a.posicaoX, 0.7 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.36 + a.posicaoX, 0.7 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.36 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.36 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.0);
	glEnd();

	//direita
	glBegin(GL_QUADS);
	glVertex3f(-0.4 + a.posicaoX, 0.7 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.4 + a.posicaoX, 0.7 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.4 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.4 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.0);
	glEnd();
}

void baseAntenaEsquerda(alien a) {
	
	glColor3f(0.0, 1.0, 0.6);
	
	//frente
	glBegin(GL_QUADS);
	glVertex3f(-0.36 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.36 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.32 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.32 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//trás
	glBegin(GL_QUADS);
	glVertex3f(-0.36 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.36 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.32 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.32 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.0);
	glEnd();

	//cima
	glBegin(GL_QUADS);
	glVertex3f(-0.36 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.36 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.32 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.32 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//baixo
	glBegin(GL_QUADS);
	glVertex3f(-0.36 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.36 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.32 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.32 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//direita
	glBegin(GL_QUADS);
	glVertex3f(-0.36 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.36 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.36 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.36 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//esquerda
	glBegin(GL_QUADS);
	glVertex3f(-0.32 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.32 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.32 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.32 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();
}

void corpo(alien a) {

	glColor3f(0.0, 1.0, 0.6);

	//frente
	glBegin(GL_QUADS);
	glVertex3f(-0.4 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.1 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.1 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.4 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//trás
	glBegin(GL_QUADS);
	glVertex3f(-0.4 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.1 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.1 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.4 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.0);
	glEnd();

	//cima
	glBegin(GL_QUADS);
	glVertex3f(-0.4 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.1 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.1 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.4 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//baixo
	glBegin(GL_QUADS);
	glVertex3f(-0.4 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.1 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.1 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.4 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//esquerda
	glBegin(GL_QUADS);
	glVertex3f(-0.4 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.4 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.4 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.4 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//direita
	glBegin(GL_QUADS);
	glVertex3f(-0.1 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.1 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.1 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.1 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();
}

void baixoCorpoDireito(alien a) {

	glColor3f(0.0, 1.0, 0.6);

	//frente
	glBegin(GL_QUADS);
	glVertex3f(-0.1 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.14 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.14 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.1 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//trás
	glBegin(GL_QUADS);
	glVertex3f(-0.1 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.14 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.14 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.1 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.0);
	glEnd();

	//cima
	glBegin(GL_QUADS);
	glVertex3f(-0.1 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.14 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.14 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.1 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//baixo
	glBegin(GL_QUADS);
	glVertex3f(-0.1 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.14 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.14 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.1 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//esquerda
	glBegin(GL_QUADS);
	glVertex3f(-0.1 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.1 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.1 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.1 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//direita
	glBegin(GL_QUADS);
	glVertex3f(-0.14 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.14 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.14 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.14 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();
}

void baixoCorpoEsquerdo(alien a) {
	
	glColor3f(0.0, 1.0, 0.6);

	//frente
	glBegin(GL_QUADS);
	glVertex3f(-0.4 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.36 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.36 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.4 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//tras
	glBegin(GL_QUADS);
	glVertex3f(-0.4 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.36 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.36 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.4 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//cima
	glBegin(GL_QUADS);
	glVertex3f(-0.4 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.36 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.36 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.4 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//baixo
	glBegin(GL_QUADS);
	glVertex3f(-0.4 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.36 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.36 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.4 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//esq
	glBegin(GL_QUADS);
	glVertex3f(-0.4 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.36 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.36 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.4 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//dir
	glBegin(GL_QUADS);
	glVertex3f(-0.4 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.36 + a.posicaoX, 0.46 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.36 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.4 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();
}

void baseAntenaDireita(alien a) {
	glColor3f(0.0, 1.0, 0.6);

	//frente
	glBegin(GL_QUADS);
	glVertex3f(-0.18 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.14 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.14 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.18 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//tras
	glBegin(GL_QUADS);
	glVertex3f(-0.18 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.14 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.14 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.18 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.0);
	glEnd();

	//cima
	glBegin(GL_QUADS);
	glVertex3f(-0.18 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.14 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.14 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.18 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//baixo
	glBegin(GL_QUADS);
	glVertex3f(-0.18 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.14 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.14 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.18 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.0);
	glEnd();

	//esquerda
	glBegin(GL_QUADS);
	glVertex3f(-0.18 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.18 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.18 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.18 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//direita
	glBegin(GL_QUADS);
	glVertex3f(-0.14 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.14 + a.posicaoX, 0.62 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.14 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.14 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();
}

void pontaAntenaDireita(alien a) {
	
	glColor3f(0.0, 1.0, 0.6);

	//frente
	glBegin(GL_QUADS);
	glVertex3f(-0.14 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.14 + a.posicaoX, 0.7 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.1 + a.posicaoX, 0.7 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.1 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//tras
	glBegin(GL_QUADS);
	glVertex3f(-0.14 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.14 + a.posicaoX, 0.7 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.1 + a.posicaoX, 0.7 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.1 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.0);
	glEnd();

	//cima
	glBegin(GL_QUADS);
	glVertex3f(-0.14 + a.posicaoX, 0.7 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.14 + a.posicaoX, 0.7 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.1 + a.posicaoX, 0.7 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.1 + a.posicaoX, 0.7 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//baixo
	glBegin(GL_QUADS);
	glVertex3f(-0.14 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.14 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.1 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.1 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//esquerda
	glBegin(GL_QUADS);
	glVertex3f(-0.1 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.1 + a.posicaoX, 0.7 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.1 + a.posicaoX, 0.7 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.1 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//direita
	glBegin(GL_QUADS);
	glVertex3f(-0.14 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.14 + a.posicaoX, 0.7 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.14 + a.posicaoX, 0.7 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.14 + a.posicaoX, 0.66 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();
}

void peEsquerdo(alien a) {

	glColor3f(0.0, 1.0, 0.6);

	//frente
	glBegin(GL_QUADS);
	glVertex3f(-0.36 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.28 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.28 + a.posicaoX, 0.38 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.36 + a.posicaoX, 0.38 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//tras
	glBegin(GL_QUADS);
	glVertex3f(-0.36 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.28 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.28 + a.posicaoX, 0.38 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.36 + a.posicaoX, 0.38 + a.posicaoY, a.posicaoZ + 0.0);
	glEnd();

	//cima
	glBegin(GL_QUADS);
	glVertex3f(-0.36 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.28 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.28 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.36 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//baixo
	glBegin(GL_QUADS);
	glVertex3f(-0.36 + a.posicaoX, 0.38 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.28 + a.posicaoX, 0.38 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.28 + a.posicaoX, 0.38 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.36 + a.posicaoX, 0.38 + a.posicaoY, a.posicaoZ + 0.0);
	glEnd();

	//esquerda
	glBegin(GL_QUADS);
	glVertex3f(-0.36 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.36 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.36 + a.posicaoX, 0.38 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.36 + a.posicaoX, 0.38 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//direita
	glBegin(GL_QUADS);
	glVertex3f(-0.28 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.28 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.28 + a.posicaoX, 0.38 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.28 + a.posicaoX, 0.38 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();
}

void peDireito(alien a) {

	glColor3f(0.0, 1.0, 0.6);

	//frente
	glBegin(GL_QUADS);
	glVertex3f(-0.14 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.14 + a.posicaoX, 0.38 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.22 + a.posicaoX, 0.38 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.22 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//tras
	glBegin(GL_QUADS);
	glVertex3f(-0.14 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.14 + a.posicaoX, 0.38 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.22 + a.posicaoX, 0.38 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.22 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//cima
	glBegin(GL_QUADS);
	glVertex3f(-0.14 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.14 + a.posicaoX, 0.38 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.22 + a.posicaoX, 0.38 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.22 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//baixo
	glBegin(GL_QUADS);
	glVertex3f(-0.14 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.14 + a.posicaoX, 0.38 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.22 + a.posicaoX, 0.38 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.22 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//esquerda
	glBegin(GL_QUADS);
	glVertex3f(-0.14 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.14 + a.posicaoX, 0.38 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.22 + a.posicaoX, 0.38 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.22 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//direita
	glBegin(GL_QUADS);
	glVertex3f(-0.14 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.14 + a.posicaoX, 0.38 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.22 + a.posicaoX, 0.38 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.22 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();
}

void ombroEsquerdo(alien a) {
	
	glColor3f(0.0, 1.0, 0.6);

	//frente
	glBegin(GL_QUADS);
	glVertex3f(-0.4 + a.posicaoX, 0.58 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.44 + a.posicaoX, 0.58 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.44 + a.posicaoX, 0.50 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.4 + a.posicaoX, 0.50 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//tras
	glBegin(GL_QUADS);
	glVertex3f(-0.4 + a.posicaoX, 0.58 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.44 + a.posicaoX, 0.58 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.44 + a.posicaoX, 0.50 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.4 + a.posicaoX, 0.50 + a.posicaoY, a.posicaoZ + 0.0);
	glEnd();

	//cima
	glBegin(GL_QUADS);
	glVertex3f(-0.4 + a.posicaoX, 0.58 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.44 + a.posicaoX, 0.58 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.44 + a.posicaoX, 0.58 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.4 + a.posicaoX, 0.58 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//baixo
	glBegin(GL_QUADS);
	glVertex3f(-0.4 + a.posicaoX, 0.50 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.44 + a.posicaoX, 0.50 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.44 + a.posicaoX, 0.50 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.4 + a.posicaoX, 0.50 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//esquerda
	glBegin(GL_QUADS);
	glVertex3f(-0.44 + a.posicaoX, 0.58 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.44 + a.posicaoX, 0.58 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.44 + a.posicaoX, 0.50 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.44 + a.posicaoX, 0.50 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//direita
	glBegin(GL_QUADS);
	glVertex3f(-0.4 + a.posicaoX, 0.58 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.4 + a.posicaoX, 0.58 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.4 + a.posicaoX, 0.50 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.4 + a.posicaoX, 0.50 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();
}

void ombroDireito(alien a) {

	glColor3f(0.0, 1.0, 0.6);

	//frente
	glBegin(GL_QUADS);
	glVertex3f(-0.1 + a.posicaoX, 0.58 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.1 + a.posicaoX, 0.50 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.06 + a.posicaoX, 0.50 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.06 + a.posicaoX, 0.58 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//tras
	glBegin(GL_QUADS);
	glVertex3f(-0.1 + a.posicaoX, 0.58 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.1 + a.posicaoX, 0.50 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.06 + a.posicaoX, 0.50 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.06 + a.posicaoX, 0.58 + a.posicaoY, a.posicaoZ + 0.0);
	glEnd();

	//cima
	glBegin(GL_QUADS);
	glVertex3f(-0.1 + a.posicaoX, 0.58 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.1 + a.posicaoX, 0.58 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.06 + a.posicaoX, 0.58 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.06 + a.posicaoX, 0.58 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//baixo
	glBegin(GL_QUADS);
	glVertex3f(-0.1 + a.posicaoX, 0.5 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.1 + a.posicaoX, 0.5 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.06 + a.posicaoX, 0.5 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.06 + a.posicaoX, 0.5 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//esquerda
	glBegin(GL_QUADS);
	glVertex3f(-0.1 + a.posicaoX, 0.58 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.1 + a.posicaoX, 0.50 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.1 + a.posicaoX, 0.50 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.1 + a.posicaoX, 0.58 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//direita
	glBegin(GL_QUADS);
	glVertex3f(-0.06 + a.posicaoX, 0.58 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.06 + a.posicaoX, 0.50 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.06 + a.posicaoX, 0.50 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.06 + a.posicaoX, 0.58 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();
}

void bracoEsquerdo(alien a) {

	glColor3f(0.0, 1.0, 0.6);

	//frente
	glBegin(GL_QUADS);
	glVertex3f(-0.44 + a.posicaoX, 0.54 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.48 + a.posicaoX, 0.54 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.48 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.44 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//tras
	glBegin(GL_QUADS);
	glVertex3f(-0.44 + a.posicaoX, 0.54 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.48 + a.posicaoX, 0.54 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.48 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.44 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.0);
	glEnd();

	//cima
	glBegin(GL_QUADS);
	glVertex3f(-0.44 + a.posicaoX, 0.54 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.48 + a.posicaoX, 0.54 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.48 + a.posicaoX, 0.54 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.44 + a.posicaoX, 0.54 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//baixo
	glBegin(GL_QUADS);
	glVertex3f(-0.44 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.48 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.48 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.44 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//esquerda
	glBegin(GL_QUADS);
	glVertex3f(-0.48 + a.posicaoX, 0.54 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.48 + a.posicaoX, 0.54 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.48 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.48 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//direita
	glBegin(GL_QUADS);
	glVertex3f(-0.44 + a.posicaoX, 0.54 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.44 + a.posicaoX, 0.54 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.44 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.44 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();
}

void bracoDireito(alien a) {

	glColor3f(0.0, 1.0, 0.6);

	//frente
	glBegin(GL_QUADS);
	glVertex3f(-0.06 + a.posicaoX, 0.54 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.06 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.02 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.02 + a.posicaoX, 0.54 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//tras
	glBegin(GL_QUADS);
	glVertex3f(-0.06 + a.posicaoX, 0.54 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.06 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.02 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.02 + a.posicaoX, 0.54 + a.posicaoY, a.posicaoZ + 0.0);
	glEnd();

	//cima
	glBegin(GL_QUADS);
	glVertex3f(-0.06 + a.posicaoX, 0.54 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.06 + a.posicaoX, 0.54 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.02 + a.posicaoX, 0.54 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.02 + a.posicaoX, 0.54 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//baixo
	glBegin(GL_QUADS);
	glVertex3f(-0.06 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.06 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.02 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.02 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//esquerda
	glBegin(GL_QUADS);
	glVertex3f(-0.06 + a.posicaoX, 0.54 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.06 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.06 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.06 + a.posicaoX, 0.54 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();

	//direita
	glBegin(GL_QUADS);
	glVertex3f(-0.02 + a.posicaoX, 0.54 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.02 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.0);
	glVertex3f(-0.02 + a.posicaoX, 0.42 + a.posicaoY, a.posicaoZ + 0.04);
	glVertex3f(-0.02 + a.posicaoX, 0.54 + a.posicaoY, a.posicaoZ + 0.04);
	glEnd();
}

void olhoEsquerdo(alien a) {
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(-0.36 + a.posicaoX, 0.58 + a.posicaoY, a.posicaoZ + 0.05);
	glVertex3f(-0.36 + a.posicaoX, 0.54 + a.posicaoY, a.posicaoZ + 0.05);
	glVertex3f(-0.32 + a.posicaoX, 0.54 + a.posicaoY, a.posicaoZ + 0.05);
	glVertex3f(-0.32 + a.posicaoX, 0.58 + a.posicaoY, a.posicaoZ + 0.05);
	glEnd();
}

void olhoDireito(alien a) {
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(-0.18 + a.posicaoX, 0.54 + a.posicaoY, a.posicaoZ + 0.05);
	glVertex3f(-0.14 + a.posicaoX, 0.54 + a.posicaoY, a.posicaoZ + 0.05);
	glVertex3f(-0.14 + a.posicaoX, 0.58 + a.posicaoY, a.posicaoZ + 0.05);
	glVertex3f(-0.18 + a.posicaoX, 0.58 + a.posicaoY, a.posicaoZ + 0.05);
	glEnd();
}

#pragma endregion

void desenhaAlien(alien a) {
	pontaAntenaEsquerda(a);
	baseAntenaEsquerda(a);
	corpo(a);
	baixoCorpoDireito(a);
	baixoCorpoEsquerdo(a);
	baseAntenaDireita(a);
	pontaAntenaDireita(a);
	peEsquerdo(a);
	peDireito(a);
	ombroEsquerdo(a);
	ombroDireito(a);
	bracoEsquerdo(a);
	bracoDireito(a);
	olhoEsquerdo(a);
	olhoDireito(a);
}