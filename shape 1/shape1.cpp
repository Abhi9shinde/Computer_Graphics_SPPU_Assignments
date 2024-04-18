#include <iostream>
#include <GL/glut.h>
using namespace std;

void Init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPointSize(1.0);
    gluOrtho2D(0, 1200, 0, 800);
}
void bre_simpleh(int x1, int y1, int x2, int y2)
{

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int incX, incY;

    if (x1 < x2)
        incX = 1;
    else
        incX = -1;

    if (y1 < y2)
        incY = 1;
    else
        incY = -1;

    int x = x1;
    int y = y1;
    int p = 2 * dy - dx;

    while (x != x2)
    {
        glBegin(GL_POINTS);
        glVertex2d(x, y);
        glEnd();

        if (p < 0)
            p = p + 2 * dy;
        else
        {
            p = p + 2 * dy - 2 * dx;
            y = y + incY;
        }
        x = x + incX;
    }
    glFlush();
}
void bre_simplev(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int incX, incY;

    if (x1 < x2)
        incX = 1;
    else
        incX = -1;

    if (y1 < y2)
        incY = 1;
    else
        incY = -1;

    int x = x1;
    int y = y1;
    int p = 2 * dx - dy; // Adjusted for vertical lines

    while (y != y2) // Loop until reaching the end y-coordinate
    {
        glBegin(GL_POINTS);
        glVertex2d(x, y);
        glEnd();

        if (p < 0)
            p = p + 2 * dx;
        else
        {
            p = p + 2 * dx - 2 * dy;
            x = x + incX;
        }
        y = y + incY;
    }
    glFlush();
}

void displayl(int x1, int y1, int x2, int y2)
{
    bre_simpleh(x1, y2, x2, y2);
    bre_simpleh(x2, y1, x1, y1);
    bre_simplev(x2, y2, x2, y1);
    bre_simplev(x1, y1, x1, y2);

    // Calculate midpoints of the outer rectangle
    int midX = (x1 + x2) / 2;
    int midY = (y1 + y2) / 2;

    // Draw the inner rectangle using midpoints
    bre_simpleh(midX, y2, x2, midY);
    bre_simpleh(x2, midY, midX, y1);
    bre_simpleh(midX, y1, x1, midY);
    bre_simpleh(x1, midY, midX, y2);

    int innerMidX = (midX + midY) / 2;
    int middY = (y1 + midY) / 2;

    // Draw the second inner rectangle using midpoints of the inner rectangle
    bre_simpleh(x1 + innerMidX, y2 - middY, x2 - innerMidX, y2 - middY);
    bre_simpleh(x2 - innerMidX, y1 + middY, x1 + innerMidX, y1 + middY);
    bre_simplev(x2 - innerMidX, y2 - middY, x2 - innerMidX, y1 + middY);
    bre_simplev(x1 + innerMidX, y1 + middY, x1 + innerMidX, y2 - middY);
}
void display(void)
{
    displayl(100, 100, 400, 300);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1200, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Let's See");
    Init();
    glutDisplayFunc(display);
    glutMainLoop();
}