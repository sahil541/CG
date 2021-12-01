#include<GL/glu.h>
#include<GL/gl.h>
#include<GL/glut.h>

void init(){
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glMatrixMode(GL_PROJECTION);
        gluOrtho2D(-120.0, 120.0, -120.0, 120.0);
}

void mpca(float xc, float yc, float r){
        float p, x, y;
        glPointSize(3);
        glBegin(GL_POINTS);
        glColor3f(0.8, 0.6, 0.5);
        p = 1 - r;
        x = 0;
        y = r;
        while(x<=y){
                glVertex2i(xc+x, yc+y);
                glVertex2i(xc+x, yc-y);
                glVertex2i(xc-x, yc+y);
                glVertex2i(xc-x, yc-y);
                glVertex2i(xc+y, yc+x);
                glVertex2i(xc+y, yc-x);
                glVertex2i(xc-y, yc+x);
                glVertex2i(xc-y, yc-x);
                if (p < 0){
                        p += 2*x+1;
                }
                else{
                        p+=2*x+1-2*y;
                        y--;
                }
                x++;

        }
        glEnd();
}

void dda(float x1,float y1, float x2,float y2){
 float length,dx,dy,i,xinc,yinc;
 dx=x2-x1;
 dy=y2-y1;
 if(abs(dx) > abs(dy))
 length = dx;
 else
 length = dy;
 
 xinc = dx/length;
 yinc = dy/length;
 glBegin(GL_POINTS);
 
 glPointSize(5);
 glVertex2i(x1,y1);
 for(i=0;i<=length;i++){
  x1 += xinc;
  y1 += yinc;
  glVertex2i(x1,y1);
 }
 glEnd();
}


void circle(){
        glClear(GL_COLOR_BUFFER_BIT);
        mpca(0,0,100);
        mpca(0,0,30);
        mpca(70,-70,40);
        glColor3f(0.0,1.0,0.0);
        dda(30,10,100,20);
        glColor3f(1.0,0.0,0.0);
        dda(20,30,70,80);
        glColor3f(0.0,0.0,1.0);
        dda(-80,80,-20,30);
        glColor3f(1.0,1.0,0.0);
        dda(-70,-80,-20,-30);
        glColor3f(1.0,0.0,0.0);
        dda(68,-79,68,-65);
        dda(76,-79,76,-65);
        dda(72,-72,68,-65);
        dda(72,-72,76,-65);
        glFlush();
}

int main( int argc, char **argv){
        glutInit( &argc, argv );
        glutInitWindowPosition(20, 20);
        glutInitWindowSize(200, 200);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutCreateWindow("Mid Point Circle");
        init();
        glutDisplayFunc(circle);
        glutMainLoop();
        return 0;
}
