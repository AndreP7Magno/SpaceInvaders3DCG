#pragma once
#include "stdafx.h"
#include "GL\glew.h"
#include "GL\freeglut.h"
#include <iostream>

class nave
{
public:
	nave();
	float posicaoNaveX, posicaoNaveY, posicaoNaveZ;
};

nave::nave() {
	posicaoNaveX = 0.0;
	posicaoNaveY = 0.0;
	posicaoNaveZ = 1.0;
}


void desnave(nave n) {
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.2 + n.posicaoNaveX, 0.0 + n.posicaoNaveY, n.posicaoNaveZ + -0.2);
	glVertex3f(-0.2 + n.posicaoNaveX, 0.0 + n.posicaoNaveY, n.posicaoNaveZ + -0.2);
	glVertex3f(0.0 + n.posicaoNaveX, 0.0 + n.posicaoNaveY, n.posicaoNaveZ + -1.0);
	glEnd();

	glColor3f(0.4, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.2 + n.posicaoNaveX, 0.0 + n.posicaoNaveY, n.posicaoNaveZ + -0.2);
	glVertex3f(0.0 + n.posicaoNaveX, -0.1 + n.posicaoNaveY, n.posicaoNaveZ + -0.2);
	glVertex3f(0.0 + n.posicaoNaveX, 0.0 + n.posicaoNaveY, n.posicaoNaveZ + -1.0);
	glEnd();

	glColor3f(0.4, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.2 + n.posicaoNaveX, 0.0 + n.posicaoNaveY, n.posicaoNaveZ + -0.2);
	glVertex3f(-0.0 + n.posicaoNaveX, -0.1 + n.posicaoNaveY, n.posicaoNaveZ + -0.2);
	glVertex3f(0.0 + n.posicaoNaveX, 0.0 + n.posicaoNaveY, n.posicaoNaveZ + -1.0);
	glEnd();
}
