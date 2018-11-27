#pragma once
#include "stdafx.h"
#include "GL\glew.h"
#include "GL\freeglut.h"
#include <iostream>

class bala {
public:
	bala();

	bool foiAtirada;
	bool atingiu;
	float translacaoX;
	float translacaoY;
	float translacaoZ;
};

bala::bala() {
	foiAtirada = false;
	atingiu = false;
	translacaoX = 0.0;
	translacaoY = 0.0;
	translacaoZ = 0.0;
}

void desenhaBala(bala b) {
	
	glColor3f(1.0, 1.0, 1.0);
	
	// Parte da frente da bala
	glBegin(GL_QUADS);
	glVertex3f(b.translacaoX + 0.0125, b.translacaoY + -0.0125, b.translacaoZ + 0.0);
	glVertex3f(b.translacaoX + -0.0125, b.translacaoY + -0.0125, b.translacaoZ + 0.0);
	glVertex3f(b.translacaoX + -0.0125, b.translacaoY + 0.0125, b.translacaoZ + 0.0);
	glVertex3f(b.translacaoX + 0.0125, b.translacaoY + 0.0125, b.translacaoZ + 0.0);
	glEnd();

	// Parte de cima da bala
	glBegin(GL_QUADS);
	glVertex3f(b.translacaoX + 0.0125, b.translacaoY + 0.0125, b.translacaoZ + 0.2);
	glVertex3f(b.translacaoX + -0.0125, b.translacaoY + 0.0125, b.translacaoZ + 0.2);
	glVertex3f(b.translacaoX + -0.0125, b.translacaoY + 0.0125, b.translacaoZ + 0.0);
	glVertex3f(b.translacaoX + 0.0125, b.translacaoY + 0.0125, b.translacaoZ + 0.0);
	glEnd();

	// Parte atrás da bala
	glBegin(GL_QUADS);
	glVertex3f(b.translacaoX + 0.0125, b.translacaoY + -0.0125, b.translacaoZ + 0.2);
	glVertex3f(b.translacaoX + -0.0125, b.translacaoY + -0.0125, b.translacaoZ + 0.2);
	glVertex3f(b.translacaoX + -0.0125, b.translacaoY + 0.0125, b.translacaoZ + 0.2);
	glVertex3f(b.translacaoX + 0.0125, b.translacaoY + 0.0125, b.translacaoZ + 0.2);
	glEnd();

	// Parte direita da bala
	glBegin(GL_QUADS);
	glVertex3f(b.translacaoX + 0.0125, b.translacaoY + -0.0125, b.translacaoZ + 0.0);
	glVertex3f(b.translacaoX + 0.0125, b.translacaoY + -0.0125, b.translacaoZ + 0.2);
	glVertex3f(b.translacaoX + 0.0125, b.translacaoY + 0.0125, b.translacaoZ + 0.2);
	glVertex3f(b.translacaoX + 0.0125, b.translacaoY + 0.0125, b.translacaoZ + 0.0);
	glEnd();

	// Parte esquerda da bala
	glBegin(GL_QUADS);
	glVertex3f(b.translacaoX + -0.0125, b.translacaoY + -0.0125, b.translacaoZ + 0.2);
	glVertex3f(b.translacaoX + -0.0125, b.translacaoY + -0.0125, b.translacaoZ + 0.0);
	glVertex3f(b.translacaoX + -0.0125, b.translacaoY + 0.0125, b.translacaoZ + 0.0);
	glVertex3f(b.translacaoX + -0.0125, b.translacaoY + 0.0125, b.translacaoZ + 0.2);
	glEnd();

	// Parte inferior da bala
	glBegin(GL_QUADS);
	glVertex3f(b.translacaoX + 0.0125, b.translacaoY + -0.0125, b.translacaoZ + 0.0);
	glVertex3f(b.translacaoX + -0.0125, b.translacaoY + -0.0125, b.translacaoZ + 0.0);
	glVertex3f(b.translacaoX + -0.0125, b.translacaoY + -0.0125, b.translacaoZ + 0.2);
	glVertex3f(b.translacaoX + 0.0125, b.translacaoY + -0.0125, b.translacaoZ + 0.2);
	glEnd();
}