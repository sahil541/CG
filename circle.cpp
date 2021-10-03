#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <iostream>
#include<math.h>

 
void init()
{
 glClearColor(1.0,1.0,1.0,1.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-100.0,100.0,-100.0,100.0);
}

void object(){
 glClear(GL_COLOR_BUFFER_BIT);
 int x1=0,y1=0,x2,y2,r=50,i;
 glPointSize(2.0);
 glBegin(GL_TRIANGLE_FAN);
 
 glVertex2i(x1,y1);
 glColor3f(0.4,0.4,0.7);
 for(int i=0;i<=360;i++){
    x2 = r*cos(i) + x1;
    y2 = r*sin(i) + y1;
    glVertex2i(x2,y2);
 }
 glEnd();
 glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Circle");
    init();
    glutDisplayFunc(object);
    glutMainLoop();
    return 0;
}
