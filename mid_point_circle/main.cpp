#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

void putPixel(int x, int y) {
    glVertex2i(x, y);
}

void midpointCircle(int xc, int yc, int r)
{
    int x = 0;
    int y = r;
    int d = 1 - r;

    glBegin(GL_POINTS);
    while (x <= y) {
        // 8-way symmetry
        putPixel(xc + x, yc + y);
        putPixel(xc - x, yc + y);
        putPixel(xc + x, yc - y);
        putPixel(xc - x, yc - y);
        putPixel(xc + y, yc + x);
        putPixel(xc - y, yc + x);
        putPixel(xc + y, yc - x);
        putPixel(xc - y, yc - x);

        if (d < 0)
            d += 2 * x + 3;
        else {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 0); // red
    glPointSize(2.0f);

    midpointCircle(0, 0, 250); // Center at (0,0), radius 40

    glFlush();
}

void init()
{
    glClearColor(0, 0, 0, 0); // black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400, 400, -400, 400); // 2D view
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint Circle Drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
