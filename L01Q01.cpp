// Using OpenGL Primitives display a rectangular window placed it in suitable position and draw a rectangle inside the window having red edges.

#include <windows.h> 
#include <glut.h>
 
void initGL () {
}
 
void display () {
   glClear (GL_COLOR_BUFFER_BIT);
   
   glBegin (GL_LINE_LOOP);
      glColor3f (1.0f, 0.0f, 0.0f);
      glVertex2f (-0.5f, 0.3f);
      glVertex2f (-0.5f, -0.3f);
      glVertex2f (0.5f, -0.3f);
      glVertex2f (0.5f, 0.3f);
   glEnd ();
   
   glFlush (); 
}
 
int main (int argc, char** argv) {
   glutInit (&argc, argv);
   glutCreateWindow ("Red Edged Rectangle Using OpenGL Primitives");
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (0, 0);
   glutDisplayFunc (display);
   initGL ();
   glutMainLoop ();
   return 0;
}
