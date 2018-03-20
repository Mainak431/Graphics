#include <stdio.h>
#include <GL/glut.h>
 
void initRendering() {
	 glEnable(GL_DEPTH_TEST);
	 glEnable(GL_COLOR_MATERIAL);
	 glEnable(GL_LIGHTING); 
	 glEnable(GL_LIGHT0); 
	 glEnable(GL_LIGHT1); 
	 glEnable(GL_LIGHT2);
	 glEnable(GL_LIGHT3); 
	 glEnable(GL_LIGHT4); 
	 glEnable(GL_LIGHT5);
	 glEnable(GL_LIGHT6); 
	 glEnable(GL_LIGHT7); 
	 glEnable(GL_NORMALIZE); //Automatically normalize normals
	 glShadeModel(GL_SMOOTH); //Enable smooth shading
}

void reshape(int w, int h) {
 	glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();
 	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}
 
float _angle = -30.0f;
 
//Draws the 3D chair
void display() {
 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 	glMatrixMode(GL_MODELVIEW); // keep it like this
 	glLoadIdentity();
 	glTranslatef(0.0f, 0.0f, -14.0f);
 
 	//Add ambient light
 	GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; 
 	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
 
 	//Add positioned light
 	GLfloat lightColor0[] = {1.0f, 1.0f, 1.0f, 1.0f};//white coloured light
 	GLfloat lightPos0[] = {0.0f, -8.0f, 8.0f, 1.0f};
 	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
 	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
 
 	//Add directed light
 	GLfloat lightColor1[] = {1.0f, 1.0f, 1.0f, 1.0f}; 
 	//Coming from the direction (-1, 0.5, 0.5)
 	GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
 	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
 	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
 
 	glRotatef(10, 1.0f, 0.0f, 0.0f);
 	glRotatef(-10, 0.0f, 0.0f, 1.0f);
 	glRotatef(_angle,0.0f, 1.0f, 0.0f);
 	glColor3f(1.0f, 1.0f, 1.0f);
 	glBegin(GL_QUADS);
 	//glnormal sets the normal for each and every vertex and shading uses those normals automatically to interpolate across the face
 	//Front
    glNormal3f(0.0f, 0.0f, 1.0f);
  	glVertex3f(-2.0f, -0.2f, 2.0f);
 	glVertex3f(2.0f, -0.2f, 2.0f);
 	glVertex3f(2.0f, 0.2f, 2.0f);
 	glVertex3f(-2.0f, 0.2f, 2.0f);
 
 	//Right
 	glNormal3f(1.0f, 0.0f, 0.0f);
 	glVertex3f(2.0f, -0.2f, -2.0f);
 	glVertex3f(2.0f, 0.2f, -2.0f);
 	glVertex3f(2.0f, 0.2f, 2.0f);
 	glVertex3f(2.0f, -0.2f, 2.0f);
 
 	//Back
 	glNormal3f(0.0f, 0.0f, -1.0f);
 	glVertex3f(-2.0f, -0.2f, -2.0f);
 	glVertex3f(-2.0f, 0.2f, -2.0f);
 	glVertex3f(2.0f, 0.2f, -2.0f);
 	glVertex3f(2.0f, -0.2f, -2.0f);
 
 	//Left
 	glNormal3f(-1.0f, 0.0f, 0.0f);
 	glVertex3f(-2.0f, -0.2f, -2.0f);
 	glVertex3f(-2.0f, -0.2f, 2.0f);
 	glVertex3f(-2.0f, 0.2f, 2.0f);
 	glVertex3f(-2.0f, 0.2f, -2.0f);
 
 	//top
 	glNormal3f(0.0f,1.0f,0.0f);
 
 	glVertex3f(2.0f, 0.2f, 2.0f);
 	glVertex3f(-2.0f, 0.2f, 2.0f);
 	glVertex3f(-2.0f, 0.2f, -2.0f);
 	glVertex3f(2.0f, 0.2f, -2.0f);
 
    //bottom
    glNormal3f(0.0f,-1.0f,0.0f);
 
 	glVertex3f(2.0f, -0.2f, 2.0f);
 	glVertex3f(-2.0f, -0.2f, 2.0f);
 	glVertex3f(-2.0f, -0.2f, -2.0f);
	glVertex3f(2.0f, -0.2f, -2.0f);
 
    //table front leg
    //front
    glNormal3f(0.0f, 0.0f, 1.0f);
 
 	glVertex3f(1.8f,-0.2f,1.6f);
 	glVertex3f(1.4f, -0.2f, 1.6f);
 	glVertex3f(1.4f, -3.0f, 1.6f);
 	glVertex3f(1.8f, -3.0f, 1.6f);
 
    //back
    glNormal3f(0.0f, 0.0f, -1.0f);
 
 	glVertex3f(1.8f,-0.2f,1.2f);
 	glVertex3f(1.4f, -0.2f, 1.2f);
 	glVertex3f(1.4f, -3.0f, 1.2f);
 	glVertex3f(1.8f, -3.0f, 1.2f);
 
 	//right
 	glNormal3f(1.0f, 0.0f, 0.0f);
 
 	glVertex3f(1.8f,-0.2f,1.6f);
 	glVertex3f(1.8f, -0.2f, 1.2f);
 	glVertex3f(1.8f, -3.0f, 1.2f);
 	glVertex3f(1.8f, -3.0f, 1.6f);
 
    //left
    glNormal3f(-1.0f, 0.0f, 0.0f);
 
 	glVertex3f(1.4f,-0.2f,1.6f);
 	glVertex3f(1.4f, -0.2f, 1.2f);
 	glVertex3f(1.4f, -3.0f, 1.2f);
 	glVertex3f(1.4f, -3.0f, 1.6f);
 
 	//back leg back
 	//front
 	glNormal3f(0.0f, 0.0f, -1.0f);
 
 	glVertex3f(1.8f,-0.2f,-1.2f);
 	glVertex3f(1.4f, -0.2f, -1.2f);
 	glVertex3f(1.4f, -3.0f, -1.2f);
 	glVertex3f(1.8f, -3.0f, -1.2f);
 
 	//back
 	glNormal3f(0.0f, 0.0f, -1.0f);
 
 	glVertex3f(1.8f,-0.2f,-1.6f);
 	glVertex3f(1.4f, -0.2f, -1.6f);
 	glVertex3f(1.4f, -3.0f, -1.6f);
 	glVertex3f(1.8f, -3.0f, -1.6f);
 
    //right
    glNormal3f(1.0f, 0.0f, 0.0f);
 
 	glVertex3f(1.8f,-0.2f,-1.6f);
 	glVertex3f(1.8f, -0.2f, -1.2f);
 	glVertex3f(1.8f, -3.0f, -1.2f);
 	glVertex3f(1.8f, -3.0f, -1.6f);
 
 	//left
    glNormal3f(1.0f, 0.0f, 0.0f);
 
 	glVertex3f(1.4f,-0.2f,-1.6f);
 	glVertex3f(1.4f, -0.2f, -1.2f);
 	glVertex3f(1.4f, -3.0f, -1.2f);
 	glVertex3f(1.4f, -3.0f, -1.6f);
 
    //leg left front
    glNormal3f(0.0f, 0.0f, 1.0f);
 
 	glVertex3f(-1.8f,-0.2f,1.6f);
 	glVertex3f(-1.4f, -0.2f, 1.6f);
 	glVertex3f(-1.4f, -3.0f, 1.6f);
 	glVertex3f(-1.8f, -3.0f, 1.6f);
 
    //back
    glNormal3f(0.0f, 0.0f, -1.0f);
 
 	glVertex3f(-1.8f,-0.2f,1.2f);
 	glVertex3f(-1.4f, -0.2f, 1.2f);
 	glVertex3f(-1.4f, -3.0f, 1.2f);
 	glVertex3f(-1.8f, -3.0f, 1.2f);
 
 	//right
 	glNormal3f(1.0f, 0.0f, 0.0f);
 
 	glVertex3f(-1.8f,-0.2f,1.6f);
 	glVertex3f(-1.8f, -0.2f, 1.2f);
 	glVertex3f(-1.8f, -3.0f, 1.2f);
 	glVertex3f(-1.8f, -3.0f, 1.6f);
 
    //left
    glNormal3f(-1.0f, 0.0f, 0.0f);
 
 	glVertex3f(-1.4f,-0.2f,1.6f);
 	glVertex3f(-1.4f, -0.2f, 1.2f);
 	glVertex3f(-1.4f, -3.0f, 1.2f);
 	glVertex3f(-1.4f, -3.0f, 1.6f);
 
 	//left leg back front
 
 	//front
 	glNormal3f(0.0f, 0.0f, -1.0f);
 
 	glVertex3f(-1.8f,-0.2f,-1.2f);
 	glVertex3f(-1.4f, -0.2f, -1.2f);
 	glVertex3f(-1.4f, -3.0f, -1.2f);
 	glVertex3f(-1.8f, -3.0f, -1.2f);
 
 	//back
 	glNormal3f(0.0f, 0.0f, -1.0f);
 
 	glVertex3f(-1.8f,-0.2f,-1.6f);
 	glVertex3f(-1.4f, -0.2f, -1.6f);
 	glVertex3f(-1.4f, -3.0f, -1.6f);
 	glVertex3f(-1.8f, -3.0f, -1.6f);
 
    //right
    glNormal3f(1.0f, 0.0f, 0.0f);
 
 	glVertex3f(-1.8f,-0.2f,-1.6f);
 	glVertex3f(-1.8f, -0.2f, -1.2f);
 	glVertex3f(-1.8f, -3.0f, -1.2f);
 	glVertex3f(-1.8f, -3.0f, -1.6f);
 
 	//left
    glNormal3f(-1.0f, 0.0f, 0.0f);
 
 	glVertex3f(-1.4f,-0.2f,-1.6f);
 	glVertex3f(-1.4f, -0.2f, -1.2f);
 	glVertex3f(-1.4f, -3.0f, -1.2f);
 	glVertex3f(-1.4f, -3.0f, -1.6f);
 
 	//chair back
 	//front
 	glColor3f(1,0,1);
 	glVertex3f(-1.8f, 0.2f, -1.8f);
 	glVertex3f(1.8f, 0.2f, -1.8f);
 	glVertex3f(1.8f, 3.5f, -1.8f);
 	glVertex3f(-1.8f, 3.5f, -1.8f);
 
    //back
	glVertex3f(-1.8f, 0.2f, -2.0f);
 	glVertex3f(1.8f, 0.2f, -2.0f);
 	glVertex3f(1.8f, 3.5f, -2.0f);
 	glVertex3f(-1.8f, 3.5f, -2.0f);
 	glVertex3f(-1.8f, 0.2f, -2.0f);
 	glVertex3f(-1.8f, 3.5f, -2.0f);
 	glVertex3f(-1.8f, 3.5f, -1.8f);
 	glVertex3f(-1.8f, 0.2f, -1.8f);
    glVertex3f(1.8f, 0.2f, -2.0f);
 	glVertex3f(1.8f, 3.5f, -2.0f);
 	glVertex3f(1.8f, 3.5f, -1.8f);
 	glVertex3f(1.8f, 0.2f, -1.8f);
 	glVertex3f(-1.8f, 3.5f, -2.0f);
 	glVertex3f(-1.8f, 3.5f, -1.8f);
 	glVertex3f(1.8f, 3.5f, -1.8f);
    glVertex3f(1.8f, 3.5f, -2.0f);
 	glEnd();
 	glutSwapBuffers();
}
 
void update(int value) {
 	_angle += 1.5f;
 	if (_angle > 360) {
  		_angle -= 360;
 	}
 
 	glutPostRedisplay();
 	glutTimerFunc(25, update, 0);//update after 25ms
 	//calling update endlessly after 25 ms
}
 
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Lighting");
	initRendering();
	glutDisplayFunc(display);
	update(0);
	glutReshapeFunc(reshape);
	glClearColor(0,0,0,0);//sets background colour
	glutMainLoop();
	return 0;
}
