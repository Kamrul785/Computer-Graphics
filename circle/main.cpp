#include <bits/stdc++.h>
#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
using namespace std;

float xl, yl, r;

void display(void)
{
    glColor3f(2, 0, 0); // for yellow color
    glPointSize(2);

    float x = 0, y = r;
    float d = 3 - (2 * r);

    while (x <= y)
    {
        glBegin(GL_POINTS);
        glVertex2i(xl + x, yl + y);
        glVertex2i(xl + y, yl + x);
        glVertex2i(xl - y, yl + x);
        glVertex2i(xl - x, yl + y);
        glVertex2i(xl - x, yl - y);
        glVertex2i(xl - y, yl - x);
        glVertex2i(xl + y, yl - x);
        glVertex2i(xl + x, yl - y);
        glEnd();

        if (d < 0)
        {
            d = d + (4 * x) + 6;
        }
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }

    glFlush();
}

void init(void)
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
}

int main(int argc, char **argv)
{
    cout << "Enter the center point of the circle: ";
    cin >> xl >> yl;
    cout << "Enter the Radius of the circle: ";
    cin >> r;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Circle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
