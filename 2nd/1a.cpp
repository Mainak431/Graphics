#include <GL/glut.h>
#include <stdio.h>

int deltax = 1;
int deltay = 1;
int occ = 0;
GLfloat win_left = 0.0;
GLfloat win_right = 14.0;
GLfloat win_bottom = 0.0;
GLfloat win_top = 14.0;
void display()
{
	glClearColor(0.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
		glVertex2i(0, 0);
		glVertex2i(10, 0);
		glVertex2i(10, 10);
		glVertex2i(5,13);
		glVertex2i(0, 10);
	glEnd();
	if (occ != 0) {
		glTranslatef(deltax,deltay,0);
		occ --;
	}
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(win_left, win_right, win_bottom, win_top);
	glMatrixMode(GL_MODELVIEW);
}

void change(unsigned char key, int x, int y)
{
	GLfloat win_center_x, win_center_y;

	switch(key){
		/* pan up */
		case 'w':
			win_bottom += 1.0;
			win_top += 1.0;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D(win_left, win_right, win_bottom, win_top);
			glutPostRedisplay();
			break;
		/* pan down */
		case 's':
			win_bottom -= 1.0;
			win_top -= 1.0;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D(win_left, win_right, win_bottom, win_top);
			glutPostRedisplay();
			break;
		/* pan left */
		case 'd':
			win_left -= 1.0;
			win_right -= 1.0;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D(win_left, win_right, win_bottom, win_top);
			glutPostRedisplay();
			break;
		/* pan right */
		case 'a':
			win_left += 1.0;
			win_right += 1.0;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D(win_left, win_right, win_bottom, win_top);
			glutPostRedisplay();
			break;
		/* zoom in */
		case '+':
			win_center_x = (win_left + win_right)/2.0;
			win_center_y = (win_bottom + win_top)/2.0;
			win_left = ((win_left - win_center_x)*0.5) + win_center_x;
			win_right = ((win_right - win_center_x)*0.5) + win_center_x;
			win_bottom = ((win_bottom - win_center_y)*0.5) + win_center_y;
			win_top = ((win_top - win_center_y)*0.5) + win_center_y;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D(win_left, win_right, win_bottom, win_top);
			glutPostRedisplay();
			break;
		/* zoom out */
		case '-':
			win_center_x = (win_left + win_right)/2.0;
			win_center_y = (win_bottom + win_top)/2.0;
			win_left = ((win_left - win_center_x)*2.0) + win_center_x;
			win_right = ((win_right - win_center_x)*2.0) + win_center_x;
			win_bottom = ((win_bottom - win_center_y)*2.0) + win_center_y;
			win_top = ((win_top - win_center_y)*2.0) + win_center_y;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D(win_left, win_right, win_bottom, win_top);
			glutPostRedisplay();
			break;
		case 'm':
			occ++;
			glutPostRedisplay();
			break;
		default:
			break;
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowSize(800,800);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Assignment 1a");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(change);
	glutMainLoop();
	
	return 0;
}

