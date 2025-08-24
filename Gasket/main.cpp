#include<bits/stdc++.h>
#include<windows.h>
#include<GL/glut.h>
#define PI acos(-1)
using namespace std;

int n;
void draw_triangle( float x1, float y1, float x2, float y2, float x3, float y3 ) {
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void gasket( float x1, float y1, float x2, float y2, float x3, float y3, int n ) {
    if ( n > 0 ) {

        float x12 = (x1 + x2) / 2;
        float y12 = (y1 + y2) / 2;
        float x23 = (x2 + x3) / 2;
        float y23 = (y2 + y3) / 2;
        float x13 = (x1 + x3) / 2;
        float y13 = (y1 + y3) / 2;

        gasket( x1, y1, x12, y12, x13, y13, n-1 );
        gasket( x2, y2, x12, y12, x23, y23, n-1 );
        gasket( x3, y3, x13, y13, x23, y23, n-1 );
    } else {
        draw_triangle( x1, y1, x2, y2, x3, y3 );
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    gasket(10, 10, 90, 10, 50, 90, n);
    glFlush();
}


void init() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0, 0, 0, 0);
    glColor3f(1,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);
}



int main(int argc, char** argv) {
    cout <<"Enter n: ";
    cin>> n;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Sierpinski Gasket");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
