#include <GL/glut.h>
#include<stdio.h>
#include <GL/gl.h>
#include <stdlib.h>

GLfloat xRotated, yRotated, zRotated;
GLdouble radius=1;


int onMouse;
void mouseClicks(int button, int state, int x, int y) {
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        onMouse = 1;
    }
}

void keyboard (unsigned char key, int x, int y)
{
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
   	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

	if (key == 'a')
		{
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   		glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   		glEnable(GL_LIGHTING);
   		glEnable(GL_LIGHT0);
   		glEnable(GL_DEPTH_TEST);
	}
}

void redisplayFunc(void)
{
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
   	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

    glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT);
    // clear the identity matrix.
    glLoadIdentity();
    // traslate the draw by z = -4.0
    // Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
    glTranslatef(0.0,0.0,-4.5);
    // Red color used to draw.
    glColor3f(0.0, 0.6, 0.1); 
    glRotatef(xRotated,1.0,0.0,0.0);
    glRotatef(yRotated,0.0,1.0,0.0);
    glRotatef(zRotated,0.0,0.0,1.0); 
    glScalef(1.0,1.0,1.0);
    glutSolidSphere(radius,20,20);
	glShadeModel (GL_SMOOTH);
	glutKeyboardFunc (keyboard);
	glutMouseFunc(mouseClicks);
	if(onMouse == 1){
    //load second texture
    	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   		glLightfv(GL_LIGHT0, GL_POSITION, light_position);

   		glEnable(GL_LIGHTING);
   		glEnable(GL_LIGHT0);
   		glEnable(GL_DEPTH_TEST);
	}
	
    // Flush buffers to screen
     
    glFlush();        
    // sawp buffers called because we are using double buffering 
   // glutSwapBuffers();
}

void reshapeFunc(int x, int y)
{
    if (y == 0 || x == 0) return;  //Nothing is visible then, so return
    //Set a new projection matrix
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();
    //Angle of view:40 degrees
    //Near clipping plane distance: 0.5
    //Far clipping plane distance: 20.0
     
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  //Use the whole window for rendering
}

void idleFunc(void)
{
 
     yRotated += 0.01;
     
    redisplayFunc();
}


int main (int argc, char **argv)
{
    //Initialize GLUT
    glutInit(&argc, argv);
    //double buffering used to avoid flickering problem in animation
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
    // window size
    glutInitWindowSize(400,350);
    // create the window 
    glutCreateWindow("Sphere Rotating Animation");
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    xRotated = yRotated = zRotated = 30.0;
     xRotated=33;
     yRotated=40;
    glClearColor(0.0,0.0,0.0,0.0);
    //Assign  the function used in events
    glutDisplayFunc(redisplayFunc);
   glutReshapeFunc(reshapeFunc);
    glutIdleFunc(idleFunc);
    //Let start glut loop
    glutMainLoop();
    return 0;
}
