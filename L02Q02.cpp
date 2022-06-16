/*
Given a square object with coordinate points A (0, 3), B (3, 3), C (3, 0), D (0, 0) and perform
a. Scaling with parameter 2 towards X axis and 3 towards Y axis
b. Translation with distance 1 towards X axis and 5 towards Y axis
c. Reflection on the X axis
d. Shear parameter 3 on X axis and 4 on Y axis
e. Rotation 90 degrees anticlockwise
*/

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

GLfloat V1X = 0.0f, V1Y = 3.0f, V1Z = 0.0f;
GLfloat V2X = 3.0f, V2Y = 3.0f, V2Z = 0.0f;
GLfloat V3X = 3.0f, V3Y = 0.0f, V3Z = 0.0f;
GLfloat V4X = 0.0f, V4Y = 0.0f, V4Z = 0.0f;

void myInit () {
	glClear (GL_COLOR_BUFFER_BIT);
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glColor3f (0.0f, 0.5f, 0.5f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (-10, 10, -10, 10);
    
    glBegin (GL_LINE_LOOP);
    	glVertex3f (-400.0, 0.0, 0.0);
    	glVertex3f (400.0, 0.0, 0.0);
    glEnd ();
    
    glBegin (GL_LINE_LOOP);
    	glVertex3f (0.0, -400.0, 0.0);
    	glVertex3f (0.0, 400.0, 0.0);
    glEnd ();
    
    glFlush ();
}

void drawSquare () {
    glBegin (GL_POLYGON);
    	glVertex3f (V1X, V1Y, V1Z);
    	glVertex3f (V2X, V2Y, V2Z);
    	glVertex3f (V3X, V3Y, V3Z);
    	glVertex3f (V4X, V4Y, V4Z);
    glEnd ();
    glFlush ();
}
  
void transformRotate (float deg, float xaxis, float yaxis, float zaxis) {
	glColor3f (0.0f, 0.0f, 1.0f);
	glRotatef (deg, xaxis, yaxis, zaxis);
	drawSquare ();
}

void transformTranslate (float xaxis, float yaxis, float zaxis) {
	glColor3f (0.0f, 1.0f, 0.0f);
	glTranslatef (xaxis, yaxis, zaxis);
	drawSquare ();
}

void transformScale (float xaxis, float yaxis, float zaxis) {
	glColor3f (1.0f, 0.0f, 0.0f);
	glScalef (xaxis, yaxis, zaxis);
	drawSquare ();
}

void transformShear (float xaxis, float yaxis, float zaxis) {
	glColor3f (0.7f, 0.5f, 0.0f);
	if (xaxis != 0.0) {
		V1X += V1Y * xaxis; V2X += V2Y * xaxis; V3X += V3Y * xaxis; V4X += V4Y * xaxis;
	}
	if (yaxis != 0.0) {
		V1Y += V1X * yaxis; V2Y += V2X * yaxis; V3Y += V3X * yaxis; V4Y += V4X * yaxis;
	}
	drawSquare ();
}

void transformReflect (float xaxis, float yaxis, float zaxis) {
	glColor3f (0.0f, 0.5f, 0.2f);
	if (xaxis == 1.0) {
		V1Y = -V1Y; V2Y = -V2Y; V3Y = -V3Y; V4Y = -V4Y;
	}
	if (yaxis == 1.0) {
		V1X = -V1X; V2X = -V2X; V3X = -V3X; V4X = -V4X;
	}
	drawSquare ();
}
  
void myDisplay () {
	glColor3f (1.0, 1.0, 1.0);
	drawSquare ();
	system ("pause");
	// transformScale (2.0, 3.0, 0.0);
    // transformTranslate (1.0, 5.0, 0.0);
    // transformReflect (1.0, 0.0, 0.0);
     transformShear (0.3, 0.4, 0.0);
	// transformRotate (90.0, 0.0, 0.0, 1.0);
}
  
int main (int argc, char **argv) {
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (500, 0);
    glutInitWindowSize (1000, 1000);
    glutCreateWindow ("2D TRANSFORMATION OVER THE SQUARE");
    glutDisplayFunc (myDisplay);
    myInit ();
    glutMainLoop ();
    return 0;
}

