#include<bits/stdc++.h>
#include <windows.h>
#include <GL/glut.h>
#include <cmath>
using namespace std;
void plotPoint(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void bresenhamLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x, y;
    int sx = (x2 >= x1) ? 1 : -1;
    int sy = (y2 >= y1) ? 1 : -1;

    bool isSteep = dy > dx;
    if (isSteep) {
        swap(dx, dy);
    }

    int p = 2 * dy - dx;

    x = x1;
    y = y1;

    for (int i = 0; i <= dx; i++) {
        plotPoint(x, y);
        if (p >= 0) {
            if (isSteep)
                x += sx;
            else
                y += sy;
            p -= 2 * dx;
        }

        if (isSteep)
            y += sy;
        else
            x += sx;

        p += 2 * dy;
    }

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);  // black background
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);          // yellow color
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-100, 100, -100, 100);
}

void display() {
    bresenhamLine(0, 0, 20, 0);    // horizontal
    bresenhamLine(20, 0, 20, 20);  // vertical
    bresenhamLine(0, 20, 20, 20);  // top
    bresenhamLine(0, -1, 0, 20);   // left
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Line Drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
