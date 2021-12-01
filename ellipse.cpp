#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>

void init(){
 glClearColor(1.0,1.0,1.0,1.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-200.0,200.0,-200.0,200.0);
}

void ellipse(int xc,int yc, int rx, int ry)
{
	int i, p, p1, x = 0, y = ry;
	
	glPointSize(2);
	glBegin(GL_POINTS);
  glColor3f(0.0,0.0,0.0);
	
	p = (ry*ry)- (rx*rx)*ry + 0.25*(rx*rx);

	while(2*(ry*ry)*x <= 2*(rx*rx)*y)
	{
		if(p<0)
		{
			x++;	
			p = p+(2*(ry*ry)*x) + (3*(ry+ry)); 
		}
		else 
		{
			x++; y--;
			
			p = p+(2*(ry*ry)*x)+(3*(ry*ry))-(2*(rx*rx)*y) +(2*(rx*rx));
			
		}

		glVertex2i(xc + x, yc + y);
		glVertex2i(xc + x, yc - y);
		glVertex2i(xc - x, yc + y);
		glVertex2i(xc - x, yc - y);
	}

	p1 = ((ry*ry) * (x+0.5) * (x+0.5) ) +(( rx*rx ) * (y-1) * (y-1) ) - (rx*rx) * (ry*ry);
	
	while(y>0)
	{
		if(p1>0)
		{
			y--;
			p1 = p1 - (2*(rx*rx)*y - 3 * (rx*rx));
		}
		else
		{
			y--; x++;

			p1  = p1 + 2*(ry*ry)*x + 2*(ry*ry) - 2*(rx*rx)*y + 3*(rx*rx);
		}
		glVertex2i(xc + x, yc + y);
		glVertex2i(xc + x, yc - y);
		glVertex2i(xc - x, yc + y);
		glVertex2i(xc - x, yc - y);
		
	}
	glEnd();
}

void  display()
{
	glClear(GL_COLOR_BUFFER_BIT);
  ellipse(60,20,60,20);
	glFlush();
}

int main(int argc, char** argv){
 glutInit(&argc, argv);
 glutInitWindowSize(700, 700);
 glutInitWindowPosition(100, 100);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutCreateWindow("Ellipse program");
 init();
 glutDisplayFunc(display);
 glutMainLoop();
}
