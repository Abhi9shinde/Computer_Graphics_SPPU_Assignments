#include <iostream>
#include <GL/glut.h>
#include <cmath>
using namespace std;
static int submenu1, submenu2, mainmenu;
void Init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPointSize(1.0);
    gluOrtho2D(-600, 600, -400, 400);
}
void DDA_simple();
void DDA_dotted();
void DDA_dashed();
void DDA_thick();
void bre_simple();
void bre_dotted();
void bre_dashed();
void bre_thick();

void DDA_simple()
{
    float x1, y1, x2, y2, dx, dy, xx, yy, len;
    x1 = 0;
    y1 = 0;
    x2 = 200;
    y2 = 200;

    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
    {
        len = abs(dx);
    }
    else
    {
        len = abs(dy);
    }

    xx = dx / len;
    yy = dy / len;

    float x = x1;
    float y = y1;
    glBegin(GL_POINTS);
    glVertex2d(x, y);
    glEnd();
    for (int i = 0; i < len; i++)
    {
        x += xx;
        y += yy;
        glBegin(GL_POINTS);
        glVertex2d(x, y);
        glEnd();
    }
    glFlush();
}
void DDA_dotted()
{
    float x1, y1, x2, y2, dx, dy, xx, yy, len;
    x1 = 0;
    y1 = 0;
    x2 = -200;
    y2 = 200;

    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
    {
        len = abs(dx);
    }
    else
    {
        len = abs(dy);
    }

    xx = dx / len;
    yy = dy / len;

    float x = x1;
    float y = y1;
    glBegin(GL_POINTS);
    glVertex2d(x, y);
    glEnd();
    for (int i = 0; i < len; i++)
    {
        x += xx;
        y += yy;
        if (i % 5 != 0)
        {
            continue;
        }
        glBegin(GL_POINTS);
        glVertex2d(x, y);
        glEnd();
    }
    glFlush();
}
void DDA_dashed()
{
    float x1, y1, x2, y2, dx, dy, xx, yy, len;
    x1 = 0;
    y1 = 0;
    x2 = -200;
    y2 = -200;

    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
    {
        len = abs(dx);
    }
    else
    {
        len = abs(dy);
    }

    xx = dx / len;
    yy = dy / len;

    float x = x1;
    float y = y1;
    glBegin(GL_POINTS);
    glVertex2d(x, y);
    glEnd();
    for (int i = 0; i < len; i++)
    {
        x += xx;
        y += yy;
        if (i % 10 == 0)
        {
            continue;
        }
        glBegin(GL_POINTS);
        glVertex2d(x, y);
        glEnd();
    }
    glFlush();
}
void DDA_thick()
{
    glPointSize(3.0);
    float x1, y1, x2, y2, dx, dy, xx, yy, len;
    x1 = 0;
    y1 = 0;
    x2 = 200;
    y2 = -200;

    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
    {
        len = abs(dx);
    }
    else
    {
        len = abs(dy);
    }

    xx = dx / len;
    yy = dy / len;

    float x = x1;
    float y = y1;
    glBegin(GL_POINTS);
    glVertex2d(x, y);
    glEnd();
    for (int i = 0; i < len; i++)
    {
        x += xx;
        y += yy;
        glBegin(GL_POINTS);
        glVertex2d(x, y);
        glEnd();
    }
    glFlush();
}
void bre_simple()
{
    int x1, y1, x2, y2, dx, dy, incX, incY;
    x1 = 0;
    y1 = 0;
    x2 = 200;
    y2 = 200;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    if (x2 > x1)
    {
        incX = 1;
    }
    else
    {
        incX = -1;
    }
    if (y2 > y1)
    {
        incY = 1;
    }
    else
    {
        incY = -1;
    }
    int x = x1;
    int y = y1;
    int e = (2 * dy) - dx;
    if (dx > dy)
    {
        while (x != x2)
        {
            glBegin(GL_POINTS);
            glVertex2d(x, y);
            glEnd();
            if (e < 0)
            {
                e = e + (2 * dy);
            }
            else
            {
                y += incY;
                e = e + (2 * dy) - (2 * dx);
            }
            x += incX;
        }
    }
    else
    {
        while (y != y2)
        {
            glBegin(GL_POINTS);
            glVertex2d(x, y);
            glEnd();
            if (e < 0)
            {
                e = e + (2 * dx);
            }
            else
            {
                x += incX;
                e = e + (2 * dx) - (2 * dy);
            }
            y += incY;
        }
    }
    glFlush();
}
void bre_dotted()
{
    int x1, y1, x2, y2, dx, dy, incX, incY;
    x1 = 0;
    y1 = 0;
    x2 = -200;
    y2 = 200;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    if (x2 > x1)
    {
        incX = 1;
    }
    else
    {
        incX = -1;
    }
    if (y2 > y1)
    {
        incY = 1;
    }
    else
    {
        incY = -1;
    }
    int x = x1;
    int y = y1;
    int e = (2 * dy) - dx;
    if (dx > dy)
    {
        while (x != x2)
        {
            if (x % 3 != 0)
            {
                glBegin(GL_POINTS); // Begin drawing points
                glVertex2d(x, y);   // Draw the point
                glEnd();            // End drawing points
            }

            if (e < 0)
            {
                e = e + (2 * dy);
            }
            else
            {
                y += incY;
                e = e + (2 * dy) - (2 * dx);
            }
            x += incX;
        }
        glFlush();
    }
    else
    {
        while (y != y2)
        {
            if (y % 3 != 0)
            {
                glBegin(GL_POINTS); // Begin drawing points
                glVertex2d(x, y);   // Draw the point
                glEnd();            // End drawing points
            }
            if (e < 0)
            {
                e = e + (2 * dx);
            }
            else
            {
                x += incX;
                e = e + (2 * dx) - (2 * dy);
            }
            y += incY;
        }
    }
    glFlush();
}

void bre_dashed()
{
    int x1, y1, x2, y2, dx, dy, incX, incY;
    x1 = 0;
    y1 = 0;
    x2 = -200;
    y2 = -200;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    if (x2 > x1)
    {
        incX = 1;
    }
    else
    {
        incX = -1;
    }
    if (y2 > y1)
    {
        incY = 1;
    }
    else
    {
        incY = -1;
    }
    int x = x1;
    int y = y1;
    int e = (2 * dy) - dx;
    if (dx > dy)
    {
        while (x != x2)
        {
            if (x % 10 != 0)
            {
                glBegin(GL_POINTS); // Begin drawing points
                glVertex2d(x, y);   // Draw the point
                glEnd();            // End drawing points
            }
            if (e < 0)
            {
                e = e + (2 * dy);
            }
            else
            {
                y += incY;
                e = e + (2 * dy) - (2 * dx);
            }
            x += incX;
        }
        glFlush();
    }
    else
    {
        while (y != y2)
        {
            if (y % 10 != 0)
            {
                glBegin(GL_POINTS); // Begin drawing points
                glVertex2d(x, y);   // Draw the point
                glEnd();            // End drawing points
            }
            if (e < 0)
            {
                e = e + (2 * dx);
            }
            else
            {
                x += incX;
                e = e + (2 * dx) - (2 * dy);
            }
            y += incY;
        }
    }
    glFlush();
}
void bre_thick()
{
    glPointSize(3.0);
    int x1, y1, x2, y2, dx, dy, incX, incY;
    x1 = 0;
    y1 = 0;
    x2 = 200;
    y2 = -200;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    if (x2 > x1)
    {
        incX = 1;
    }
    else
    {
        incX = -1;
    }
    if (y2 > y1)
    {
        incY = 1;
    }
    else
    {
        incY = -1;
    }
    int x = x1;
    int y = y1;
    int e = (2 * dy) - dx;
    if (dx > dy)
    {
        while (x != x2)
        {
            glBegin(GL_POINTS);
            glVertex2d(x, y);
            glEnd();
            if (e < 0)
            {
                e = e + (2 * dy);
            }
            else
            {
                y += incY;
                e = e + (2 * dy) - (2 * dx);
            }
            x += incX;
        }
    }
    else
    {
        while (y != y2)
        {
            glBegin(GL_POINTS);
            glVertex2d(x, y);
            glEnd();
            if (e < 0)
            {
                e = e + (2 * dx);
            }
            else
            {
                x += incX;
                e = e + (2 * dx) - (2 * dy);
            }
            y += incY;
        }
    }
    glFlush();
}
void display()
{
    glBegin(GL_LINES);
    glVertex2d(600, 0);
    glVertex2d(-600, 0);
    glVertex2d(0, 400);
    glVertex2d(0, -400);
    glEnd();
    glFlush();
}
void ddamenu(int k)
{
    switch (k)
    {
    case 1:
        DDA_simple();
        break;
    case 2:
        DDA_dotted();
        break;
    case 3:
        DDA_dashed();
        break;
    case 4:
        DDA_thick();
        break;
    }
}
void bremenu(int j)
{
    switch (j)
    {
    case 1:
        bre_simple();
        break;
    case 2:
        bre_dotted();
        break;
    case 3:
        bre_dashed();
        break;
    case 4:
        bre_thick();
        break;
    }
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1200, 800);
    glutCreateWindow("Line Drawing Algorithm");
    glutDisplayFunc(display);

    submenu1 = glutCreateMenu(ddamenu);
    glutAddMenuEntry("1.DDA Simple", 1);
    glutAddMenuEntry("2.DDA Dotted", 2);
    glutAddMenuEntry("3.DDA Dashed", 3);
    glutAddMenuEntry("4.DDA Thick", 4);
    submenu2 = glutCreateMenu(bremenu);
    glutAddMenuEntry("1.BRE Simple", 1);
    glutAddMenuEntry("2.BRE Dotted", 2);
    glutAddMenuEntry("3.BRE Dashed", 3);
    glutAddMenuEntry("4.BRE Thick", 4);
    mainmenu = glutCreateMenu(ddamenu);
    glutAddSubMenu("DDA", submenu1);
    glutAddSubMenu("BRE", submenu2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    Init();
    glutMainLoop();
}