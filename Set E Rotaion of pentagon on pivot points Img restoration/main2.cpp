#include <GL/freeglut.h>
#include<bits/stdc++.h>

float x1,yl,x2,y2,x3,y3,x4,y4,x5,y5,px,py;

float points[5][3];
float t_matrix[3][3];
float res[5][3];



void translate(float tx,float ty)
{
	t_matrix[0][0] = 1; t_matrix[0][1] = 0; t_matrix[0][2] = 0;
	t_matrix[1][0] = 0; t_matrix[1][1] = 1; t_matrix[1][2] = 0;
	t_matrix[2][0] = tx; t_matrix[2][1] = ty; t_matrix[2][2] = 1;
}


void rotate(float deg)
{
	deg = deg*(M_PI/180.00);
	t_matrix[0][0] = cos(deg); t_matrix[0][1] = sin(deg); t_matrix[0][2] = 0;
	t_matrix[1][0] = -sin(deg); t_matrix[1][1] = cos(deg); t_matrix[1][2] = 0;
	t_matrix[2][0] = 0; t_matrix[2][1] = 0; t_matrix[2][2] = 1;
}

void matrix_mul()
{

	points[0][0] = x1;  points[0][1] = yl; points[0][2] = 1;
	points[1][0] = x2;  points[1][1] = y2; points[1][2] = 1;
	points[2][0] = x3;  points[2][1] = y3; points[2][2] = 1;
	points[3][0] = x4;  points[3][1] = y4; points[3][2] = 1;
	points[4][0] = x5;  points[4][1] = y5; points[4][2] = 1;

	for(int i=0;i<5;i++)
	{
		for(int j=0;j<3;j++)
		{
			res[i][j]=0;
			for(int k=0;k<3;k++)
			{
				res[i][j] += points[i][k] * t_matrix[k][j];
			}
		}
	}
	x1 = res[0][0];	yl = res[0][1];
	x2 = res[1][0];	y2 = res[1][1];
	x3 = res[2][0];	y3 = res[2][1];
	x4 = res[3][0]; y4 = res[3][1];
	x5 = res[4][0]; y5 = res[4][1];

}

void draw_pentagon(float r, float g, float b)
{
	glBegin(GL_LINE_LOOP);
		glColor3f(r,g,b);
		glVertex2f(x1,yl);
		glVertex2f(x2,y2);
		glVertex2f(x3,y3);
		glVertex2f(x4,y4);
		glVertex2f(x5,y5);
	glEnd();
}

void axes_lines()
{
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.5, 0.5);
		glVertex2f(-100.0,0);
		glVertex2f(100.0,0);
	glEnd();

	glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.5, 0.5);
		glVertex2f(0,100.0);
		glVertex2f(0,-100.0);
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	x1 = -20, yl = 60;  //A
	x2 = -50, y2 = 30;	//B
	x3 = -30, y3 = -10;  //C
	x4 = -10, y4 = -10;  //D
	x5 = 10, y5 = 30;  	//E

	// pivot point
	px = -20, py= 40;

	draw_pentagon(1.0,0.0,0.0);

	translate(-px,-py);
	matrix_mul();
	//draw_pentagon(0.0,1.0,0.0);

	rotate(90);
	matrix_mul();
	//draw_pentagon(1.0,1.0,0.0);

	translate(px,py);
	matrix_mul();
	draw_pentagon(0.0,0.0,1.0);
	axes_lines();

	glFlush();
}

void myinit() {

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(480, 480);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Q1: Pentagon Rotation");

	glClearColor(0, 0, 0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-120.0, 120.0, -120.0, 120.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}