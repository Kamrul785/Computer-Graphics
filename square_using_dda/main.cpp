#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

void drawLineDDA(float x1, float y1, float x2, float y2)
{
    glColor3f(0,0,1);     // white
    glPointSize(2.0f);

    float dx = x2 - x1;
    float dy = y2 - y1;

    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
    float xInc = dx / steps;
    float yInc = dy / steps;

    float x = x1, y = y1;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++) {
        glVertex2i((int)round(x), (int)round(y));
        x += xInc;
        y += yInc;
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Square parameters
    float x = -50, y = -50;   // bottom-left corner
    float side = 100;

    // 4 sides using DDA
    drawLineDDA(x, y, x + side, y);             // bottom
    drawLineDDA(x + side, y, x + side, y + side); // right
    drawLineDDA(x + side, y + side, x, y + side); // top
    drawLineDDA(x, y + side, x, y);               // left

    glFlush();
}

void init()
{
    glClearColor(0, 0, 0, 0); // black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100); // simple 2D world
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Square using DDA");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
