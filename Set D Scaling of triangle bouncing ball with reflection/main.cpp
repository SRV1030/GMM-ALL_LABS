#include <glut.h>

GLfloat V1X = 0.0f, V1Y = 0.0f, V1Z = 0.0f;
GLfloat V2X = 60.0f, V2Y = 50.0f, V2Z = 0.0f;
GLfloat V3X = 60.0f, V3Y = 0.0f, V3Z = 0.0f;

void myInit() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0f, 0.5f, 0.5f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500, 500, -500, 500);
	glBegin(GL_LINE_LOOP);
	glVertex3f(-400.0, 0.0, 0.0);
	glVertex3f(400.0, 0.0, 0.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0, -400.0, 0.0);
	glVertex3f(0.0, 400.0, 0.0);
	glEnd();
	glFlush();
}

void drawTriangle() {
	glBegin(GL_TRIANGLES);
	glVertex3f(V1X, V1Y, V1Z);
	glVertex3f(V2X, V2Y, V2Z);
	glVertex3f(V3X, V3Y, V3Z);
	glEnd();
	glFlush();
}

void scale(float xaxis, float yaxis, float zaxis) {
	glColor3f(1.0f, 0.0f, 0.0f);
	glScalef(xaxis, yaxis, zaxis);
	drawTriangle();
}


void display() {
	glColor3f(1.0, 1.0, 1.0);
	drawTriangle();
	scale(2.0, 3.0, 0);
	drawTriangle();
	scale(1/2.0, 1/3.0, 0);
	glColor3f(1.0, 1.0, 1.0);
	drawTriangle();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("Triangle Scaling");
	glutDisplayFunc(display);
	myInit();
	glutMainLoop();
	return 0;
}