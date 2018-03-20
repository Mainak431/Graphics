#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>
#include <stdlib.h>

void Draw() {
 	glClear(GL_COLOR_BUFFER_BIT);
 	glColor3d(0,1,0);
 	glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0,0.0);
    glVertex2f(5.0,0.0);
    glVertex2f(5.0,5.0);
	glVertex2f(0.0,5.0);
 	glEnd();
 	glFlush();
}


void Initialize() {
 	glClearColor(0, 0, 0, 1.0);
 	glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();
 	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
}
int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(476, 477);
	glutInitWindowPosition(250, 250);
	glutCreateWindow("Triangle fan");
	Initialize();
	glutDisplayFunc(Draw);
	glutMainLoop();
	return EXIT_SUCCESS;
}
