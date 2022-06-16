#include <stdio.h>
#include<GL/glut.h>
 
void initGL() {
 	glClearColor(1.0,1.0,1.0,1.0);
 	glMatrixMode(GL_PROJECTION);
  	glLoadIdentity();
   	gluOrtho2D(-250,250,-250,250 );
 }

void display() {

	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1.0f, 0.0f, 0.0f); 
	glBegin(GL_LINE_LOOP); 
		glVertex2f(0,0); 
		glVertex2f( 100, -100);
		glVertex2f( -100, -100);
	glEnd();
	glBegin(GL_LINE_LOOP); 
		glVertex2f(-50,-50); 
		glVertex2f( 50, -50);
		glVertex2f( 0, -100);
	glEnd();
	glFlush();  
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowPosition(0, 0);
   glutInitWindowSize(500, 500);
   glutCreateWindow("Question 1");
   initGL();
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}