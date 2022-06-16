// Implementation of DDA line drawing algorithm. “The program should take input of the initial end‐point and the final end‐point. Divide the coordinate axes into four quadrants and draw the line. Show that your program works for [m>0, m=0 and m<0]”.
#include <stdio.h>
#include <cmath>
#include <glut.h>
#include<iostream>

using namespace std;

double X1, Y1, X2, Y2;

void LineDDA(void) {
	GLint dx = abs(X2 - X1);
	GLint dy = abs(Y2 - Y1);
	GLint steps;
	GLfloat xInc, yInc, xx = X1, yy = Y1;
	steps = (dx > dy) ? (dx) : (dy);
	xInc = dx / (GLfloat)steps;
	yInc = dy / (GLfloat)steps;

	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POINTS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2d(xx, yy);
	int kk;
	for (kk = 0; kk < steps; ++kk) {
		xx += xInc;
		yy += yInc;
		glVertex2i(floor(xx + 0.5), floor(yy + 0.5));
	}
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(-400, 0);
	glVertex2f(400, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(0, -400);
	glVertex2f(0, 400);
	glEnd();

	glFlush();
}

void Init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500, 500, -500, 500);
}

int main(int argc, char** argv) {
	printf("ENTER TWO END POINTS OF THE LINE TO BE DRAWN\n");
	printf("\nENTER FIRST POINT (X1, Y1):\n");
	cin>>X1>>Y1;
	printf("\nENTER SECOND POINT (X2, Y2):\n");
	cin >> X2 >> Y2;
	printf("\nSLOPE (m) = %lf", (Y2 - Y1) / (X2 - X1));

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("DDA Line Drawing Algorithm");
	glutDisplayFunc(LineDDA);
	Init();
	glutMainLoop();
	return 0;
}

