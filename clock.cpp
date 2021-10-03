#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>

void init()
{
 glClearColor(0.0,0.0,0.0,1.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-200.0,200.0,-200.0,200.0);
}

void clock()
{
 glClear(GL_COLOR_BUFFER_BIT);
 int x1=0, x2, y1=0, y2, r=150, i;
 glPointSize(20);
 
 glBegin(GL_TRIANGLE_FAN);
 glVertex2i(x1,y1);
 glColor3f(1.0,1.0,1.0);
 for(i=0; i<=360; i++)
 {
  x2= r*cos(i) + x1;
  y2= y1 + r*sin(i);
  glVertex2i(x2,y2);
 }
 glEnd();
 
 
 glLineWidth(5.0);
 glBegin(GL_LINES);
 glColor3f(0.0,0.0,0.0);
 glVertex2i(0,135);
 glVertex2i(0,145);
 glVertex2i(5,135);
 glVertex2i(5,145);
 glVertex2i(-5,135);
 glVertex2i(-15,145);
 glVertex2i(-15,135);
 glVertex2i(-5,145);
 glVertex2i(145,5);
 glVertex2i(145,-5);
 glVertex2i(135,5);
 glVertex2i(135,-5);
 glVertex2i(140,5);
 glVertex2i(140,-5);
 glVertex2i(-145,-5);
 glVertex2i(-145,5);
 glVertex2i(-140,5);
 glVertex2i(-130,-5);
 glVertex2i(-130,5);
 glVertex2i(-140,-5);
 glVertex2i(0,-145);
 glVertex2i(-5,-135);
 glVertex2i(0,-145);
 glVertex2i(5,-135);
 glVertex2i(10,-135);
 glVertex2i(10,-145);
 
 glVertex2i(40,50);
 glVertex2i(50,50);
 glVertex2i(50,40);
 glVertex2i(50,50);
 
 glColor3f(1.0,0.0,0.0);
 glVertex2i(0,0);
 glVertex2i(-125,0);
 glEnd();
 
 glLineWidth(15.0);
 glBegin(GL_LINES);
 glColor3f(0.0,0.0,0.0);
 glVertex2i(0,0);
 glVertex2i(50,50);

 
 glVertex2i(0,0);
 glVertex2i(-90,-90);
 glEnd();
 
 r=7;
 glBegin(GL_TRIANGLE_FAN);
 glVertex2i(x1,y1);
 glColor3f(1.0,0.0,0.0);
 for(i=0; i<=360; i++)
 {
  x2= r*cos(i) + x1;
  y2= y1 + r*sin(i);
  glVertex2i(x2,y2);
 }
 glEnd();
 
 glFlush();
}

int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitWindowPosition(100,100);
 glutInitWindowSize(700,700);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutCreateWindow("Clock");
 init();
 glutDisplayFunc(clock);
 glutMainLoop();
}
