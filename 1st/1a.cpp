#include <stdio.h>
#include <GL/glut.h>
void display()
{
 glClear(GL_COLOR_BUFFER_BIT);
   
 glColor3f(1,0,0);
 glBegin(GL_POLYGON);
 glVertex2f(100,300);
 glVertex2f(100,100);
 glVertex2f(200,100);
 glVertex2f(200,300);
 glEnd();
 glLineWidth(2.5); 
 
 glFlush();
 glutSwapBuffers();
}

int main(int argc, char** argv)
{ 
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
 glutInitWindowSize(400,400);
 glutCreateWindow("Assignment1a");
 glutDisplayFunc(display);
 gluOrtho2D(0,640,0,640);
 glClearColor(1,1,0,0);
 glutMainLoop();
 return 0;
} 
