#include <stdio.h>
#include <GL/glut.h>
#include<string.h>
float angle=0;
float x = 1;
float y = 0;
float z = 0;
float x1 = 1;
float y1 = 1;
float z1 = 0;
float ax = -0.8;
float ay = -0.8;
float bx = 0.8;
float by = -0.8;
float cx = 0.8;
float cy = 0.8;
float dx = -0.8;
float dy = 0.8;

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
	 unsigned char string[] = "Hello";
	 int w,i=0;
    
	 glColor3f(x1, y1, z1);
	 glLineWidth(4);
	 w = glutBitmapLength(GLUT_BITMAP_8_BY_13, string);
	 glRotatef(angle,0.0f,0.0f,1.0f);
	 glRasterPos2f(0.4,0.4);
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
	 angle-=30.0f;
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
    
	
	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(1000, update, 0);
}
void reshape(GLsizei width, GLsizei height) {  
   if (height == 0) height = 1;               
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
   glViewport(0, 0, width, height);
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}
int main(int argc, char** argv)
{ 
	 glutInit(&argc, argv);
	 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	 glutInitWindowSize(400,400);
	 glutCreateWindow("Assignment1c");
	 glutDisplayFunc(display);
	 glutTimerFunc(1000, update, 0);
	 //glutReshapeFunc(reshape);
	 glutMainLoop();
	 return 0;
} 
