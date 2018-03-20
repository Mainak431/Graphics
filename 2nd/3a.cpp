#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
GLfloat xpos=0.0;
GLfloat ypos=0.0;
GLfloat zpos=0.0;
GLfloat eyex=1;
GLfloat eyey=1;
GLfloat eyez=1;
GLfloat angle1 = 30;
GLfloat angle2 = 60;
GLfloat zoom = 1;

static int spin = 0;
GLfloat moon = 0;
void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);
}


void display(void)
{   
  GLfloat position[] = { xpos, ypos, zpos, 1.0 };
   
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLightfv (GL_LIGHT0, GL_POSITION, position);
  glEnable (GL_LIGHTING);

  /* define the viewing transformation */
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  //gluLookAt(1.0,1.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0);
  gluLookAt(1,1,5, 0, 0, 0, 0, 1, 0);
   

  static float earth = 0;
  static float moon = 0;

  earth += 0.02 ;
  moon += 0.02 ;
  glColor3f( 0.0f, 0.0f,1.0f);
  glTranslatef(0,0,zoom);
  glPushMatrix();
  {
    glRotatef( earth, 0, 0, 1 );
    glTranslatef( 0, 0, 0 );
    glColor3f( 0.0f, 0.0f,1.0f);
    glutSolidSphere( 0.3, 100, 100 );
     
  }   
  glPopMatrix();
  glPushMatrix();
    {
      glRotatef( moon, 0, 0, 1 );
      glTranslatef( 0.6, 0, 0 );
      glColor3ub( 128, 128, 128 );
      glutSolidSphere( 0.1, 50, 50 );
    }
    glPopMatrix();
  glFlush ();
  glutPostRedisplay();

 
}
void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(40.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void SpecialInput(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_UP:
        ypos+=0.1;
        break;

        case GLUT_KEY_DOWN:
        ypos-=0.1;
        //do something here
        break;

        case GLUT_KEY_LEFT:
        xpos-=0.1;
        //do something here
        break;

        case GLUT_KEY_RIGHT:
        xpos+=0.1;
        //do something here
        break;

        case GLUT_KEY_F1:
        zpos+=1;
        //do something here
        break;

        case GLUT_KEY_F2:
        zpos-=1;
        break;

        case GLUT_KEY_F3:
        eyex-=1;        
        break;
        
        case GLUT_KEY_F4:
        eyex+=1;
        break;

        case GLUT_KEY_F5:
        zoom-=1;
        break;

        case GLUT_KEY_F6:
        zoom+=1;
        break;

        
        
        default:
        break;
        
    }

glutPostRedisplay();
}
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   //glutMouseFunc(mouse);
   glutSpecialFunc(SpecialInput);
   glutMainLoop();
   return 0;
}