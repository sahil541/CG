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

void rectangle(){
 glClear(GL_COLOR_BUFFER_BIT);
 glLineWidth(5);
 glPointSize(2.0);
 
 
 glBegin(GL_LINE_LOOP);
 glColor3f(0.0,0.0,0.0);
 glVertex2i(0,0);
 glVertex2i(0,30);
 glVertex2i(60,30);
 glVertex2i(60,0);
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
    glutCreateWindow("rectangle Program");
    init();
    glutDisplayFunc(rectangle);
    glutMainLoop();
    return 0;
}
