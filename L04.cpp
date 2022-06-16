/*
Rotation of a rectangle based on pivot points (20, 30).
a. Translate object to origin from its original position as shown in fig (b).
b. Rotate the object about the origin as shown in fig (c).
c. Translate the object to its original position from origin. It is called as reverse
translation as shown in fig (d).
*/

#include <iostream>
#include <GL/glut.h>
using namespace std;

GLfloat px, py, Rotation;
GLfloat ax, ay, bx, by, cx, cy, dx, dy;

void myinit (void) {
	glClear (GL_COLOR_BUFFER_BIT);
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (-100, 100, -100, 100);
}

void drawRect () {
	glBegin (GL_LINE_LOOP);
		glVertex2f (ax, ay);
		glVertex2f (bx, by);
		glVertex2f (dx, dy);
		glVertex2f (cx, cy);
	glEnd ();
}

void drawQuadrants () {
	glPointSize (3.0);   
	glColor3f (0.0f, 0.5f, 0.5f);
	
	glBegin (GL_LINE_LOOP);
    	glVertex3f (-500.0, 0.0, 0.0);
    	glVertex3f (500.0, 0.0, 0.0);
    glEnd ();
    
    glBegin (GL_LINE_LOOP);
    	glVertex3f (0.0, -500.0, 0.0);
    	glVertex3f (0.0, 500.0, 0.0);
    glEnd ();
}

void display () {
		drawQuadrants ();
	// Original Points
	ax = 15.0, ay = 35.0, bx = 30.0, by = 35.0, cx = 15.0, cy = 25.0, dx = 30.0, dy = 25.0;
	// Pivot Points
	px = 20.0, py = 30.0;
	
	glColor3f (1.0f, 1.0f, 1.0f);
	drawRect ();
	
	// 1. Translate object to origin from its original position
	GLfloat midX, midY;
	midX = (ax + bx + cx + dx) / 4.0;
	midY = (ay + by + cy + dy) / 4.0;
	glColor3f (0.0f, 1.0f, 0.0f);
	glTranslatef (-midX, -midY, 0.0);
	glTranslatef (midX-px, midY-py, 0.0);
	drawRect ();
	// 2. Rotate the object about the origin
	Rotation = -90;
	glColor3f (1.0f, 0.0f, 0.0f);
	glTranslatef (px, py, 0.0f);
	glRotatef (Rotation, 0.0f, 0.0f, 1.0f);
	glTranslatef (-px, -py, 0.0f);
	drawRect ();
	// 3. Translate the object to its original position from origin.
	glColor3f (0.0f, 0.0f, 1.0f);
	glTranslatef (px, py, 0.0f);
	glRotatef (-Rotation, 0.0f, 0.0f, 1.0f);
	glTranslatef (-px, -py, 0.0f);
	
	glTranslatef (px-midX, py-midY, 0.0);
	glTranslatef (midX, midY, 0.0);
	
	drawRect ();
	
	glFlush ();
}

int main (int argc, char **argv) {
	glutInit (&argc, argv);
    glutInitWindowSize (1000, 1000);
    glutInitWindowPosition (500, 0);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow ("Rotation a rectangle based on pivot points (20, 30)");
	myinit ();
    glutDisplayFunc (display);
    glutMainLoop ();
    return 0;
}
