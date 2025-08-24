#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

void putPixel(int x, int y) {
    glVertex2i(x, y);
}

void bresenhamLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x2 >= x1) ? 1 : -1;
    int sy = (y2 >= y1) ? 1 : -1;
    int err = dx - dy;

    glBegin(GL_POINTS);
    while (true) {
        putPixel(x1, y1);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 <  dx) { err += dx; y1 += sy; }
    }
    glEnd();
}

void bresenhamCircle(int xc, int yc, int r)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;

    glBegin(GL_POINTS);
    while (x <= y) {
        putPixel(xc + x, yc + y);
        putPixel(xc - x, yc + y);
        putPixel(xc + x, yc - y);
        putPixel(xc - x, yc - y);
        putPixel(xc + y, yc + x);
        putPixel(xc - y, yc + x);
        putPixel(xc + y, yc - x);
        putPixel(xc - y, yc - x);

        if (d < 0)
            d = d + 4 * x + 6;
        else {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(2.0f);

    // Set color: Green for rectangle (flag)
    glColor3f(0, 0.6, 0);
    int x = -60, y = -30, w = 120, h = 60;

    // Draw rectangle with Bresenham line
    bresenhamLine(x, y, x + w, y);         // bottom
    bresenhamLine(x + w, y, x + w, y + h); // right
    bresenhamLine(x + w, y + h, x, y + h); // top
    bresenhamLine(x, y + h, x, y);         // left

    // Set color: Red for circle (sun)
    glColor3f(1, 0, 0);
    bresenhamCircle(x + w / 2 - 15, y + h / 2, 15); // red circle at center-left

    glFlush();
}

void init()
{
    glClearColor(0, 0, 0, 0); // black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100); // simple 2D view
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Flag of Bangladesh - Bresenham Line and Circle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
