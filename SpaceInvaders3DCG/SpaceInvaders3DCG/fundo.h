#pragma once
#include "stdafx.h"
#include "GL\glew.h"
#include "GL\freeglut.h"
#include <iostream>

class fundo
{
public:
};

struct ponto {
	float ponto1, ponto2;
};

void LuzMaterial() {
	//Definição das propriedades dos materiais
	float ambiente[] = { 1.0f, 1.0f, 1.0f, 1.0f }; //Cinza
	float difusa[] = { 0.6f, 0.6f, 0.6f, 1.0f };
	float especular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float brilho[] = { 100.0f };

	glMaterialfv(GL_FRONT, GL_AMBIENT, ambiente);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, difusa);
	glMaterialfv(GL_FRONT, GL_SPECULAR, especular);
	glMaterialfv(GL_FRONT, GL_SHININESS, brilho);

	//Definição das propriedades das fontes de luz
	//glTranslatef(0.45, 0.0, 0.0);
	GLfloat intensidade_luz[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat posicao_luz[] = { 1.0f, 10.0f, 0.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, posicao_luz);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, intensidade_luz);

	/*glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);*/
}
