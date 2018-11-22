#pragma once
#pragma once
#include "stdafx.h"
#include "GL\glew.h"
#include "GL\freeglut.h"
#include <iostream>

class escreve
{
public:
};

void Escreve(int cont) {
	char texto[11] = "Pontuacao:";
	char teste[20];

	sprintf_s(teste, "%d", cont);

	glColor3ub(255, 255, 255);
	glRasterPos3f(0.7, -2.0, 0.0);

	for (int k = 0; k <= strlen(texto); k++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, texto[k]);

	for (int k = 0; k <= strlen(teste); k++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, teste[k]);
}