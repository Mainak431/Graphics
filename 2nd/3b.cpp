#include <GL/glut.h>

#include <math.h>
#define PI 3.14159265f
int refreshMills = 30;
GLfloat next = 0;

void Timer(int value) {
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(refreshMills, Timer, 0); // next Timer call milliseconds later
}
void display()
{
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    if(next>=1){
      
    //EAR1
    glBegin(GL_TRIANGLE_FAN);
      glColor3f(0.0f, 0.0f, 0.0f);  // Blue
      GLfloat x1 = 0.3;
      GLfloat y1 = 0.3;
      glVertex2f(x1, y1);       // Center of circle
      int numSegments = 100;
      GLfloat angle;
      for (int i = 0; i <= numSegments; i++) { // Last vertex same as first vertex
         angle = i * 2.0f * PI / numSegments;  // 360 deg for all segments
         glVertex2f(cos(angle) * 0.15 + x1, sin(angle) * 0.15 + y1);
      }
    glEnd();
    }
    if(next>=2){
    //EAR2
    glBegin(GL_TRIANGLE_FAN);
      glColor3f(0.0f, 0.0f, 0.0f);  // Blue
      GLfloat x2 = -0.3;
      GLfloat y2 = 0.3;
      glVertex2f(x2, y2);       // Center of circle
      int numSegments1 = 100;
      GLfloat angle1;
      for (int i = 0; i <= numSegments1; i++) { // Last vertex same as first vertex
         angle1 = i * 2.0f * PI / numSegments1;  // 360 deg for all segments
         glVertex2f(cos(angle1) * 0.15 + x2, sin(angle1) * 0.15 + y2);
      }
    glEnd();
    }

    //FACE SHAPE 
    glBegin(GL_TRIANGLE_FAN);
      glColor3f(0.0f, 0.0f, 0.0f);
      //glColor3ub(105,105,105);  // Blue
      GLfloat x3 = 0.0;
      GLfloat y3 = 0.0;
      glVertex2f(x3, y3);       // Center of circle
      int numSegments3 = 100;
      GLfloat angle3;
      for (int i = 0; i <= numSegments3; i++) { // Last vertex same as first vertex
         angle3 = i * 2.0f * PI / numSegments3;  // 360 deg for all segments
         glVertex2f(cos(angle3) * 0.3 + x3, sin(angle3) * 0.3 + y3);
      }
    glEnd();
    
    // circle behind left eye
    glBegin(GL_TRIANGLE_FAN);
      //glColor3f(1.0f, 1.0f, 1.0f);
      glColor3ub(255,227,159);
      //glColor3f(0.255f,0.224f,0.189f);  
      glVertex2f(-0.1, 0.1);       
      GLfloat angle4;
      for (int i = 0; i <= 100; i++) { 
         angle4 = i * 2.0f * PI / 100;  // 360 deg for all segments
         glVertex2f(cos(angle4) * 0.13 - 0.1, sin(angle4) * 0.15 + 0.1);
      }
    glEnd();

    // circle behind right eye
    glBegin(GL_TRIANGLE_FAN);
      //glColor3f(1.0f, 1.0f, 1.0f);
      glColor3ub(255,227,159);  // Blue
      glVertex2f(0.1, 0.1);       // Center of circle
      GLfloat angle5;
      for (int i = 0; i <= 100; i++) { // Last vertex same as first vertex
         angle5 = i * 2.0f * PI / 100;  // 360 deg for all segments
         glVertex2f(cos(angle5) * 0.13 + 0.1, sin(angle5) * 0.15 + 0.1);
      }
    glEnd();

    //lower face
    glBegin(GL_TRIANGLE_FAN);
      //glColor3f(1.0f, 1.0f, 1.0f);
      glColor3ub(255,227,159);  // Blue
      glVertex2f(0.0,-0.12);       // Center of circle
      GLfloat angle6;
      for (int i = 0; i <= 100; i++) { // Last vertex same as first vertex
         angle6 = i * 2.0f * PI / 100;  // 360 deg for all segments
         glVertex2f(cos(angle6) * 0.3 + 0.0, sin(angle6) * 0.17 - 0.12);
      }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
      //glColor3f(1.0f, 1.0f, 1.0f);
      glColor3ub(255,227,159);  // Blue
      glVertex2f(0.0,-0.28);       // Center of circle
      GLfloat angle66;
      for (int i = 0; i <= 100; i++) { // Last vertex same as first vertex
         angle66 = i * (-1.0f) * PI / 100;  // 360 deg for all segments
         glVertex2f(cos(angle66) * 0.12 + 0.0, sin(angle66) * 0.09 - 0.26);
      }
    glEnd();
     
    if(next>=3){ 
    //nose
    glBegin(GL_TRIANGLE_FAN);
      glColor3f(0.0f, 0.0f, 0.0f);  // Blue
      glVertex2f(0.0, -0.1);       // Center of circle
      GLfloat angle7;
      for (int i = 0; i <= 100; i++) { // Last vertex same as first vertex
         angle7 = i * 2.0f * PI / 100;  // 360 deg for all segments
         glVertex2f(cos(angle7) * 0.1 + 0.0, sin(angle7) * 0.05 - 0.08);
      }
    glEnd();
    }

    glLineWidth(3); 

    if(next>=4){
    //left eye
    glBegin(GL_TRIANGLE_FAN);
      glColor3f(1.0f, 1.0f, 1.0f);
       // Blue
      glVertex2f(-0.06, 0.1);       // Center of circle
      GLfloat angle88;
      for (int i = 0; i <= 1000; i++) { // Last vertex same as first vertex
         angle88 = i * 2.0f * PI / 1000;  // 360 deg for all segments
         glVertex2f(cos(angle88) * 0.04 - 0.06, sin(angle88) * 0.1 + 0.1);
      }
    glEnd();
    }
    
    if(next>=4){
    //left eye outline
    glBegin(GL_LINE_LOOP);
      glColor3f(0.0f, 0.0f, 0.0f);
       // Blue
      //glVertex2f(-0.08, 0.1);       // Center of circle
      GLfloat angle8;
      for (int i = 0; i <= 1000; i++) { // Last vertex same as first vertex
         angle8 = i * 2.0f * PI / 1000;  // 360 deg for all segments
         glVertex2f(cos(angle8) * 0.04 - 0.06, sin(angle8) * 0.1 + 0.1);
      }
    glEnd();
    }

    if(next>=5){
    //right eye
    glBegin(GL_TRIANGLE_FAN);
      glColor3f(1.0f, 1.0f, 1.0f);
       // Blue
      glVertex2f(0.06, 0.1);       // Center of circle
      GLfloat angle99;
      for (int i = 0; i <= 1000; i++) { // Last vertex same as first vertex
         angle99 = i * 2.0f * PI / 1000;  // 360 deg for all segments
         glVertex2f(cos(angle99) * 0.04 + 0.06, sin(angle99) * 0.1 + 0.1);
      }
    glEnd();
    }

    if(next>=5){
    //right eye outline
    glBegin(GL_LINE_LOOP);
      glColor3f(0.0f, 0.0f, 0.0f);
       // Blue
      //glVertex2f(-0.08, 0.1);       // Center of circle
      GLfloat angle9;
      for (int i = 0; i <= 1000; i++) { // Last vertex same as first vertex
         angle9 = i * 2.0f * PI / 1000;  // 360 deg for all segments
         glVertex2f(cos(angle9) * 0.04 + 0.06, sin(angle9) * 0.1 + 0.1);
      }
    glEnd();
    }

    if(next>=4){
    //left iris
    glBegin(GL_TRIANGLE_FAN);
      glColor3f(0.0f, 0.0f, 0.0f);  // Blue
      glVertex2f(-0.06, 0.06);       // Center of circle
      GLfloat angle10;
      for (int i = 0; i <= 100; i++) { // Last vertex same as first vertex
         angle10 = i * 2.0f * PI / 100;  // 360 deg for all segments
         glVertex2f(cos(angle10) * 0.03 - 0.06, sin(angle10) * 0.06 + 0.06);
      }
    glEnd();
    }

    if(next>=5){
    //right iris
    glBegin(GL_TRIANGLE_FAN);
      glColor3f(0.0f, 0.0f, 0.0f);  // Blue
      glVertex2f(0.06, 0.06);       // Center of circle
      GLfloat angle11;
      for (int i = 0; i <= 100; i++) { // Last vertex same as first vertex
         angle11 = i * 2.0f * PI / 100;  // 360 deg for all segments
         glVertex2f(cos(angle11) * 0.03 + 0.06, sin(angle11) * 0.06 + 0.06);
      }
    glEnd();
    }
     
    if(next>=6){ 
    //mouth outline
    glBegin(GL_LINE_STRIP);
      glColor3f(0.0f, 0.0f, 0.0f);
       // Blue
      //glVertex2f(-0.08, 0.1);       // Center of circle
      GLfloat angle12;
      for (int i = 0; i <= 100; i++) { // Last vertex same as first vertex
         angle12 = i * (-1.0f) * PI / 100;  // 360 deg for all segments
         glVertex2f(cos(angle12) * 0.2 + 0.0, sin(angle12) * 0.12 - 0.1);
      }
    glEnd();

    //mouth
    glBegin(GL_LINE_STRIP);
      glColor3f(0.0f, 0.0f, 0.0f);
       // Blue
      //glVertex2f(-0.08, 0.1);       // Center of circle
      GLfloat angle13;
      for (int i = 0; i <= 100; i++) { // Last vertex same as first vertex
         angle13 = i * (-1.0f) * PI / 100;  // 360 deg for all segments
         glVertex2f(cos(angle13) * 0.1 + 0.0, sin(angle13) * 0.07 - 0.2);
      }
    glEnd();
   
    }

    ////face outline
    //glBegin(GL_LINE_STRIP);
    //  glColor3f(0.0f, 0.0f, 0.0f);  // Blue
    //  
    //  GLfloat angle33;
    //  for (int i = 0; i <= 1000; i++) { // Last vertex same as first vertex
    //     angle33 = i * 2.0f * PI / 1000;  // 360 deg for all segments
    //     glVertex2f(cos(angle33) * 0.3 , sin(angle33) * 0.3 );
    //  }
    //glEnd();

    glFlush();
}
void reshape(GLsizei width, GLsizei height)
{
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(width >= height)
    {
        gluOrtho2D(-1.0*aspect,1.0*aspect,-1.0,1.0);
    }
    else{
        gluOrtho2D(-1.0,1.0,-1.0/aspect,1.0/aspect);
    }
}
void SpecialInput(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_RIGHT:
        next+=1;
        //do something here
        break;
        case GLUT_KEY_LEFT:
        next-=1;
        //do something here
        break;
        default:
        break;
        
    }

glutPostRedisplay();
}
int main(int argc, char** argv) {
   glutInit(&argc, argv);                
   glutCreateWindow("OpenGL Setup Test");
   glutInitWindowSize(320, 320);   
   glutInitWindowPosition(50, 50); 
   glutTimerFunc(0, Timer, 0);   
   glutDisplayFunc(display);
   glutReshapeFunc(reshape); 
   //glutTimerFunc(0, Timer, 0);
   glutSpecialFunc(SpecialInput);

   glutMainLoop();           
   return 0;
}
