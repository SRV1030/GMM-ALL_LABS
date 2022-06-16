// Implementation of Bresenham’s Line drawing algorithm. “The program should take input of the initial end‐point and the final end‐point, and verify whether the drawn line is smooth one or not. The program should be generic so that it works for integer values. Check for the slop of the line (i.e. m>0, m=0 and m<0)”.

#include <GL/glut.h>
#include <stdio.h>

int x1, y1, x2, y2;

void myInit () {
	glClear (GL_COLOR_BUFFER_BIT);
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glColor3f (1.0, 1.0, 1.0);
	glPointSize (3.0);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluOrtho2D (-500, 500, -500, 500);
}

void draw_pixel (int xx, int yy) {	
	glBegin (GL_POINTS);
		glColor3f (1.0, 1.0, 1.0);
		glVertex2i (xx, yy);
	glEnd ();
}

void draw_line () {
	int dx, dy, ii, ee;
	int incx, incy, inc1, inc2;
	int xx, yy;
	dx = x2 - x1;
	dy = y2 - y1;
	if (dx < 0) 
		dx = -dx;
	if (dy < 0) 
		dy = -dy;
	incx = 1;
	if (x2 < x1) 
		incx = -1;
	incy = 1;
	if (y2 < y1) 
		incy = -1;
	xx = x1; 
	yy = y1;
	if (dx > dy) {
		draw_pixel (xx, yy);
		ee = 2 * dy - dx;
		inc1 = 2 * (dy - dx);
		inc2 = 2 * dy;
		for (ii = 0; ii < dx; ++ii) {
			if (ee >= 0) {
				yy += incy;
				ee += inc1;
			}
			else
				ee += inc2;
			xx += incx;
			draw_pixel(xx, yy);
		}
	}
	else {
		draw_pixel (xx, yy);
		ee = 2 * dx - dy;
		inc1 = 2 * (dx - dy);
		inc2 = 2 * dx;
		for (ii = 0; ii < dy; ++ii) {
			if (ee >= 0) {
				xx += incx;
				ee += inc1;
			}
			else
				ee += inc2;
			yy += incy;
			draw_pixel (xx, yy);
		}
	}
	
	glFlush ();
}

int main (int argc, char **argv) {
	printf ("ENTER TWO END POINTS OF THE LINE TO BE DRAWN\n");
	printf ("\nENTER FIRST POINT (X1, Y1):\n");
	scanf (" %d %d", &x1, &y1);
	printf ("\nENTER SECOND POINT (X2, Y2):\n");
	scanf (" %d %d", &x2, &y2);
	printf ("\nSLOPE (m) = %f", ((float)y2-(float)y1)/((float)x2-(float)x1));
	
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("Bresenham's Line Drawing");
	myInit ();
	glutDisplayFunc (draw_line);
	glutMainLoop ();

	return 0;
}
