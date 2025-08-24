#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
float x,y,x1,y1,x2,y2,dx,dy,m,p0;
void display(float x1,float y1,float x2,float y2)
{
    glColor3f(2,2,0);// for yellow color
    glPointSize(2);
    int i=1;
    dx=x2-x1;
    dy=y2-y1;
    m=dy/dx;
    p0= 2*dy - dx;
    while(x!=x2){
        if(p0 < 0){
            x+=1;
            p0 = p0+2*dy;
        }
        else if(p0 > 0){
            x+=1;
            y++;
            p0+= (2*dy - dx);
        }
        glBegin(GL_POINTS);
        glVertex2f(x,y);
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
        display(0,0,20,0);
        display(20,0,20,20);
        display(0,20,20,20);
        display(0,-1,0,20);
    });
    glutMainLoop();
    return 0;
}
