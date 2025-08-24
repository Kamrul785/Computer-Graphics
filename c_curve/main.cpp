#include<bits/stdc++.h>
#include<windows.h>
#include<GL/glut.h>
#define PI acos(-1)
using namespace std;

float x, y, len, alpha, x2, y2 ;
int n ;

void C_curve(float x, float y,float len,float alpha,int n)
{
if(n>0)
{
len = len / sqrt(2.0);
C_curve(x,y,len,alpha+45,n-1);

x = x + len * cos( (alpha + 45)*PI/180 );
y = y + len * sin ( (alpha + 45)*PI/180 );
C_curve(x,y,len,alpha - 45, n-1);
}
else
{
glBegin(GL_LINES);
glVertex2f(x,y);
glVertex2f(x + len * cos(alpha*PI/180), y + len * sin(alpha*PI/180) );
x2 = x + len * cos(alpha*PI/180), y2 = y + len * sin(alpha*PI/180) ;
glEnd();
}
}

void display(void)
{
C_curve(x,y,200,0,1);
x = x2, y = y2 ;

C_curve(x,y,200,72,1);
x = x2, y = y2 ;

C_curve(x,y,200,144,1);
x = x2, y = y2 ;

C_curve(x,y,200,216,1);
x = x2, y = y2 ;

C_curve(x,y,200,288,1);

glFlush();
}

void init(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0,0,0,0);
glMatrixMode(GL_PROJECTION);

glLoadIdentity();
gluOrtho2D(-300,300,-300,300);
}

int main(int argc, char** argv)
{
printf("Enter the value of x & y : ");
scanf("%f %f",&x,&y);
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(100,100);
glutCreateWindow("Star using C_Curve");
init();
glutDisplayFunc(display);
glutMainLoop();

return 0;
}
