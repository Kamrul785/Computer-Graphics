#include <bits/stdc++.h>
#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
using namespace std;

void drawLine(float x1, float y1, float x2, float y2)
{
    glColor3f(0, 0.4, 0); // for green color
    glPointSize(2);

    float dx = x2 - x1;
    float dy = y2 - y1;
    float x = x1;
    float y = y1;

    float m = dy / dx;
    int step = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    for (int i = 0; i <= step; i++)
    {
        glBegin(GL_POINTS);
        glVertex2f(round(x), round(y));
        glEnd();

        x += dx / step;
        y += dy / step;
    }
    glFlush();
}

void drawCircle(float xc, float yc, float r)
{
    glColor3f(2, 0, 0); // for red color
    glPointSize(2);

    float x = 0, y = r;
    float d = 3 - 2 * r;

    while (x <= y)
    {
        glBegin(GL_POINTS);
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc - x, yc - y);
        glVertex2i(xc - y, yc - x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc + x, yc - y);
        glEnd();

        if (d < 0)
        {
            d += 4 * x + 6;
        }
        else
        {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
    glFlush();
}

void display()
{
    // Draw rectangle (flag body)
    drawLine(0, 0, 80, 0);      // bottom
    drawLine(80, 0, 80, 50);    // right
    drawLine(80, 50, 0, 50);    // top
    drawLine(0, 50, 0, 0);      // left

    // Draw circle (sun) at center-left of rectangle
    drawCircle(35, 25, 15); // Circle centered at (20,15), radius = 7
}

void init(void)
{
    glClearColor(0, 0, 0, 0); // black background
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100); // set 2D view
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bangladeshi Flag");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
