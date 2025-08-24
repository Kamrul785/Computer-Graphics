
#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
float x,y,x1,y1,x2,y2,dx,dy,m;
void display(float x1,float y1,float x2,float y2)
{
    glColor3f(2,2,0);// for yellow color
    glPointSize(2);
    int i=1;
    dx=x2-x1;
    dy=y2-y1;
    m=dy/dx;
    if(m<=1)
    {
        int step=abs(dx);
        x=x1;
        y=y1;
        while(i<=step)
        {
            x=x+1;
            y=y+m;
            glBegin(GL_POINTS);
            glVertex2f(x,y);
            i++;
        }
    }
    else
    {
        int step=abs(dy);
        x=x1;
        y=y1;

        while(i<=step)
        {
            x=x+(1/m);
            y=y+1;
            i++;
            glBegin(GL_POINTS);
            glVertex2f(x,y);
        }
    }
    glEnd();
    glFlush();
}
void init(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("DDA");
    init();
    glutDisplayFunc([]()
    {
        display(0,0,50,0); // last line
        display(50,0,50,30); // right line
        display(0,30,50,30); // above line
        display(0,-1,0,30); //  left line

    });
    glutMainLoop();
    return 0;
}
