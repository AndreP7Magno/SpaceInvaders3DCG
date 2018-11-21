#pragma once
#pragma once
#include "stdafx.h"
#include "GL\glew.h"
#include "GL\freeglut.h"
#include <iostream>

class bala
{
public:
	bala();

	bool foiAtirada;
	bool atingiu;
	double translacaoX;
	double translacaoY;
	double translacaoZ;
};

bala::bala() {
	foiAtirada = false;
	atingiu = false;
	translacaoX = 0.0;
	translacaoY = 0.0;
	translacaoZ = 0.0;
}

void desenhabala(bala b) {
	//frente da bala
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex3f(b.translacaoX + 0.0125, b.translacaoY + -0.0125, b.translacaoZ + 0.0);
	glVertex3f(b.translacaoX + -0.0125, b.translacaoY + -0.0125, b.translacaoZ + 0.0);
	glVertex3f(b.translacaoX + -0.0125, b.translacaoY + 0.0125, b.translacaoZ + 0.0);
	glVertex3f(b.translacaoX + 0.0125, b.translacaoY + 0.0125, b.translacaoZ + 0.0);
	glEnd();

	// cima da bala
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex3f(b.translacaoX + 0.0125, b.translacaoY + 0.0125, b.translacaoZ + 0.2);
	glVertex3f(b.translacaoX + -0.0125, b.translacaoY + 0.0125, b.translacaoZ + 0.2);
	glVertex3f(b.translacaoX + -0.0125, b.translacaoY + 0.0125, b.translacaoZ + 0.0);
	glVertex3f(b.translacaoX + 0.0125, b.translacaoY + 0.0125, b.translacaoZ + 0.0);
	glEnd();

	//trás da bala
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex3f(b.translacaoX + 0.0125, b.translacaoY + -0.0125, b.translacaoZ + 0.2);
	glVertex3f(b.translacaoX + -0.0125, b.translacaoY + -0.0125, b.translacaoZ + 0.2);
	glVertex3f(b.translacaoX + -0.0125, b.translacaoY + 0.0125, b.translacaoZ + 0.2);
	glVertex3f(b.translacaoX + 0.0125, b.translacaoY + 0.0125, b.translacaoZ + 0.2);
	glEnd();

	//direita da bala
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex3f(b.translacaoX + 0.0125, b.translacaoY + -0.0125, b.translacaoZ + 0.0);
	glVertex3f(b.translacaoX + 0.0125, b.translacaoY + -0.0125, b.translacaoZ + 0.2);
	glVertex3f(b.translacaoX + 0.0125, b.translacaoY + 0.0125, b.translacaoZ + 0.2);
	glVertex3f(b.translacaoX + 0.0125, b.translacaoY + 0.0125, b.translacaoZ + 0.0);
	glEnd();

	//esquerda da bala
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex3f(b.translacaoX + -0.0125, b.translacaoY + -0.0125, b.translacaoZ + 0.2);
	glVertex3f(b.translacaoX + -0.0125, b.translacaoY + -0.0125, b.translacaoZ + 0.0);
	glVertex3f(b.translacaoX + -0.0125, b.translacaoY + 0.0125, b.translacaoZ + 0.0);
	glVertex3f(b.translacaoX + -0.0125, b.translacaoY + 0.0125, b.translacaoZ + 0.2);
	glEnd();

	//baixo da bala
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex3f(b.translacaoX + 0.0125, b.translacaoY + -0.0125, b.translacaoZ + 0.0);
	glVertex3f(b.translacaoX + -0.0125, b.translacaoY + -0.0125, b.translacaoZ + 0.0);
	glVertex3f(b.translacaoX + -0.0125, b.translacaoY + -0.0125, b.translacaoZ + 0.2);
	glVertex3f(b.translacaoX + 0.0125, b.translacaoY + -0.0125, b.translacaoZ + 0.2);
	glEnd();
}