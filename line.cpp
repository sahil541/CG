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

void line(){
 glClear(GL_COLOR_BUFFER_BIT);
 glLineWidth(4);
 glBegin(GL_LINES);
 glVertex2i(-30,50);
 glVertex2i(20,70);
 glColor3f(0.0,0.0,0.0);
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
    glutCreateWindow("Line Program");
    init();
    glutDisplayFunc(line);
    glutMainLoop();
    return 0;
}
