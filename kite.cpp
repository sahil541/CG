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

void setKite(){
 glClear(GL_COLOR_BUFFER_BIT);
 glLineWidth(2);
 glBegin(GL_LINES);
 glVertex2i(0,-50);
 glVertex2i(0,-50);
 glColor3f(0.0,0.0,1.0);
 
 glVertex2i(-50,0);
 glVertex2i(50,0);
 glColor3f(0.0,1.0,0.0);
 
 glVertex2i(-50,0);
 glVertex2i(0,50);
 glColor3f(0.0,0.0,1.0);
 
 glVertex2i(0,50);
 glVertex2i(50,0);
 
 glVertex2i(50,0);
 glVertex2i(0,-50);
 
 glVertex2i(0,-50);
 glVertex2i(-50,0);
 glColor3f(0.0,0.0,1.0);
 
 glVertex2i(0,-50);
 glVertex2i(-30,-60);
 glVertex2i(-30,-60);
 glVertex2i(30,-60);
 glVertex2i(30,-60);
 glVertex2i(0,-50);
 
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
    glutCreateWindow("Kite Program");
    init();
    glutDisplayFunc(setKite);
    glutMainLoop();
    return 0;
}
