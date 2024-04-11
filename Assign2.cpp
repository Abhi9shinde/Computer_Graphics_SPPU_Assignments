#include <iostream>
#include <GL/glut.h>
using namespace std;

void myInit(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPointSize(1.0);
    gluOrtho2D(600, -600, 400, -400);
}
void bresenham_circle(void)
{
    int x, y, p, q, r, d;
    r = 300;
    p = 0;
    q = 0;
    d = 3 - 2 * r;
    x = 0;
    y = r;
    while (x <= y)
    {
        glBegin(GL_POINTS);
        glVertex2d(x + p, y + q);
        glVertex2d(-x + p, y + q);
        glVertex2d(y + p, x + q);
        glVertex2d(y + p, -x + q);
        glVertex2d(x + p, -y + q);
        glVertex2d(-x + p, -y + q);
        glVertex2d(-y + p, x + q);
        glVertex2d(-y + p, -x + q);
        glEnd();
        glFlush();

        if (d < 0)
        {
            x++;
            d = d + (4 * x) + 6;
        }
        else
        {
            x++;
            y--;
            d = d + 4 * (x - y) + 10;
        }
    }
}
void display(void)
{
    glBegin(GL_LINES);
    glVertex2d(600, 0);
    glVertex2d(-600, 0);
    glVertex2d(0, 400);
    glVertex2d(0, -400);
    glEnd();
    bresenham_circle();
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1200, 800);
    glutCreateWindow("Bresengam Circle");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
