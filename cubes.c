#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

GLdouble width, height, aspect; 

int wd; 

float a ;

typedef struct  {
  float x,y,z ;
} point3D;

point3D v1 = {1,0,0} ;

void init(void)
{
  width  = 1280.0;
  height = 800.0;
  aspect = width / height ;
}

void cube(float x, float y, float z, float s)
{

  float hs = s / 2 ;

  glPushMatrix();

  glTranslatef(x, y, z);
  glBegin(GL_TRIANGLES) ;
    glColor3f(1,0,0) ; 
    glVertex3f(-hs,-hs,-hs) ; glVertex3f(+hs,-hs,-hs) ; glVertex3f(+hs,+hs,-hs) ;
    glVertex3f(+hs,+hs,-hs) ; glVertex3f(-hs,+hs,-hs) ; glVertex3f(-hs,-hs,-hs) ;
    glVertex3f(-hs,-hs,+hs) ; glVertex3f(+hs,-hs,+hs) ; glVertex3f(+hs,+hs,+hs) ;
    glVertex3f(+hs,+hs,+hs) ; glVertex3f(-hs,+hs,+hs) ; glVertex3f(-hs,-hs,+hs) ;

    glColor3f(0,1,0) ; 
    glVertex3f(-hs,-hs,-hs) ; glVertex3f(+hs,-hs,-hs) ; glVertex3f(+hs,-hs,+hs) ;
    glVertex3f(+hs,-hs,+hs) ; glVertex3f(-hs,-hs,+hs) ; glVertex3f(-hs,-hs,-hs) ;
    glVertex3f(-hs,+hs,-hs) ; glVertex3f(+hs,+hs,-hs) ; glVertex3f(+hs,+hs,+hs) ;
    glVertex3f(+hs,+hs,+hs) ; glVertex3f(-hs,+hs,+hs) ; glVertex3f(-hs,+hs,-hs) ;

    glColor3f(0,0,1) ; 
    glVertex3f(-hs,-hs,-hs) ; glVertex3f(-hs,-hs,+hs) ; glVertex3f(-hs,+hs,+hs) ;
    glVertex3f(-hs,+hs,+hs) ; glVertex3f(-hs,+hs,-hs) ; glVertex3f(-hs,-hs,-hs) ;
    glVertex3f(+hs,-hs,-hs) ; glVertex3f(+hs,-hs,+hs) ; glVertex3f(+hs,+hs,+hs) ;
    glVertex3f(+hs,+hs,+hs) ; glVertex3f(+hs,+hs,-hs) ; glVertex3f(+hs,-hs,-hs) ;
  glEnd() ;

  glPopMatrix() ;

}


float angle = 0.0f;

void display(void)
{

  glClearColor(0.0, 0.0, 0.0, 0.0);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, aspect /*ScreenInfo.AspectRatio*/, 1, 1500);

  glMatrixMode(GL_MODELVIEW) ;
  glLoadIdentity() ;
  gluLookAt(700*cos(a),  500, 700*sin(a),
            0, 0, 0,
            0,     1,     0) ;

  a = a + 0.01 ;

  float fx, fy, fz ;

//  glBegin(GL_TRIANGLES) ;
    for (fx = -300 ; fx <= 300 ; fx += 100) {
      for (fy = -300 ; fy <= 300 ; fy += 100) {
        for (fz = -300 ; fz <= 300 ; fz += 100) {
          cube(fx,fy,fz,50) ;
        }
      }   
    }
 // glEnd() ;
  
  glutSwapBuffers();

}

void keyboard (unsigned char key, int x, int y) {
  if (key==27)
  {
    glutLeaveGameMode();
    exit(0); 
  }
}

void reshape(int w, int h)
{
  glViewport (0, 0, (GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, aspect, 1, 1500);
  glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char *argv[])
{
  init();

  glutInit(&argc, argv);

  glutInitDisplayMode (GLUT_SINGLE | GLUT_DEPTH); 
  glutGameModeString( "1280x800:32@60" ); 
  glutEnterGameMode();

  glEnable(GL_DEPTH_TEST) ;
  glDepthFunc(GL_LESS) ;


  glutDisplayFunc(display);
  glutIdleFunc(display) ;
  glutReshapeFunc(reshape);

  glutKeyboardFunc (keyboard); 
  glutMainLoop();

  return 0;
}
