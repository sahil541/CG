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

void flag(){
 glClear(GL_COLOR_BUFFER_BIT);
 glLineWidth(5);
 glPointSize(2.0);
 
 //Rectangle
 glBegin(GL_LINE_LOOP);
 glColor3f(0.0,0.0,0.0);
 glVertex2i(0,0);
 glVertex2i(0,30);
 glVertex2i(60,30);
 glVertex2i(60,0);
 glEnd();
 
 //Base
 glBegin(GL_LINE_LOOP);
 glVertex2i(-25,-70);
 glVertex2i(25,-70);
 glVertex2i(25,-75);
 glVertex2i(30,-75);
 glVertex2i(30,-80);
 glVertex2i(-30,-80);
 glVertex2i(-30,-75);
 glVertex2i(-25,-75);
 glVertex2i(-25,-70);
 glEnd();
 
 //Pole
 glBegin(GL_LINE_LOOP);
 glVertex2i(0,0);
 glVertex2i(0,-70);
 
 //Make it Tricolor
 glVertex2i(0,10);
 glVertex2i(60,10);
 
 glVertex2i(0,20);
 glVertex2i(60,20);
 glEnd();
 
 //Circle
 int x1=30,y1=15,x2,y2,r=5,i;
 glBegin(GL_TRIANGLE_FAN);
 
 glVertex2i(x1,y1);
 glColor3f(0.4,0.4,0.7);
 for(int i=0;i<=360;i++){
    x2 = r*cos(i) + x1;
    y2 = r*sin(i) + y1;
    glVertex2i(x2,y2);
 }
 glEnd();
 
 //Spokes in chakra
 glBegin(GL_LINES);
 glColor3f(1.0,1.0,1.0);
 glVertex2i(30,10);
 glVertex2i(30,20);
 
 glVertex2f(26.5,15);
 glVertex2f(33.5,15);
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
    glutCreateWindow("Flag Program");
    init();
    glutDisplayFunc(flag);
    glutMainLoop();
    return 0;
}
