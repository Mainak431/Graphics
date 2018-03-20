#include <stdio.h>
#include <GL/glut.h>
#include<string.h>
float x = 1;
float y = 0;
float z = 0;
float x1 = 1;
float y1 = 1;
float z1 = 0;
float ax = 100;
float ay = 300;
float bx = 100;
float by = 100;
float cx = 400;
float cy = 100;
float dx = 400;
float dy = 300;
float angle = 30.0f;
void display()
{
	 glClear(GL_COLOR_BUFFER_BIT);
	 glPushMatrix();
	 glColor3f(x,y,z);
	 glBegin(GL_POLYGON);
	 glVertex2f(ax,ay);
	 glVertex2f(bx,by);
	 glVertex2f(cx,cy);
	 glVertex2f(dx,dy);
	 glEnd();
	 unsigned char string[] = "Assignment 1B";
	 int w,i=0;
	 glColor3f(x1, y1, z1);
	 glLineWidth(4);
	 w = glutBitmapLength(GLUT_BITMAP_8_BY_13, string);
	 glRasterPos2f(150, 200);
	 int len = 0;
	 while(string[i]!= '\0')
	 {
	 	len++;
	 	i++;
	 }
	 i = 0;
	 for (i = 0; i < len; i++) {
	     glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
	 }
	 glPopMatrix();
	 glFlush();
	 glutSwapBuffers();
}
void update(int value) {
	
	if (x == 0) {
		x++;
		if(y == 0){
			y++;
			if(z == 0){
			z++;
			} else {
				z--;
			}
		} else {
			y--;
		}
	} else
	{
		x--;
	}
	if (x1 == 0) {
		x1++;
		if(y1 == 0){
			y1++;
			if(z1 == 0){
			z1++;
			} else {
				z1--;
			}
		} else {
			y1--;
		}
	} else
	{
		x1--;
	}
	
	glutPostRedisplay(); //Tell GLUT that the display has changed
	
	//Tell GLUT to call update again in 1000 milliseconds
	glutTimerFunc(1000, update, 0);
}

int main(int argc, char** argv)
{ 
	 glutInit(&argc, argv);
	 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	 glutInitWindowSize(400,400);
	 glutCreateWindow("Assignment1b");
	 glutDisplayFunc(display);
	 glutTimerFunc(1000, update, 0);
	 gluOrtho2D(0,640,0,640);
	 glClearColor(1,1,0,0);
	 
	 glutMainLoop();
	 return 0;
} 
