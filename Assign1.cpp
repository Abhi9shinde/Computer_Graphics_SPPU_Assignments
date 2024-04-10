#include <iostream>
#include <GL/glut.h>
#include <cmath>
using namespace std;
static int mainmenu, submain_menu1, submain_menu2;

void myInit(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPointSize(1.0);
    gluOrtho2D(-600.0, 600.0, -400.0, 400.0);
}
/*******************************************DDA LINE ALGORITHM*********************************************/
void DD_simple(void)
{
    float x1, y1, x2, y2, xx, yy, len, dx, dy;
    x1 = 0;
    y1 = 0;
    x2 = 200,
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

void DD_dotted(void)
{
    float x1, y1, x2, y2, xx, yy, len, dx, dy;
    x1 = 0;
    y1 = 0;
    x2 = -200,
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
void DD_dashed(void)
{
    float x1, y1, x2, y2, xx, yy, len, dx, dy;
    x1 = 0;
    y1 = 0;
    x2 = -200,
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
void DD_thick(void)
{
    float x1, y1, x2, y2, xx, yy, len, dx, dy;
    glPointSize(3.0);
    x1 = 0;
    y1 = 0;
    x2 = 200,
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
/******************************************BRESENHAM LINE ALGORITHM******************************************/
void bre_simple(void)
{
    int x1, y1, x2, y2, dx, dy;
    x1 = 0;
    y1 = 0;
    x2 = 200,
    y2 = 200;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    int x = x1;
    int y = y1;
    int i = 1;
    int e = (2 * dy) - dx;
    while (i <= dx)
    {
        glBegin(GL_POINTS);
        glVertex2d(x, y);
        glEnd();
        if (e >= 0)
        {
            y += 1;
            e = e - (2 * dx);
        }
        x += 1;
        e = e + (2 * dy);
        i++;
    }
    glFlush();
}

void bre_dotted(void)
{
    int x1, y1, x2, y2, dx, dy;
    x1 = 0;
    y1 = 0;
    x2 = 200,
    y2 = 200;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    int x = x1;
    int y = y1;
    int i = 1;
    int e = (2 * dy) - dx;
    while (i <= dx)
    {
        if (i % 2 != 0)
        {
            glBegin(GL_POINTS); // Begin drawing points
            glVertex2d(x, y);   // Draw the point
            glEnd();            // End drawing points
        }
        else
        {
            if (e >= 0)
            {
                y += 1;
                e = e - (2 * dx);
            }
            x += 1;
            e = e + (2 * dy);
        }
        i++;
    }
    glFlush();
}
void bre_thick(void)
{
    glPointSize(3.0);
    int x1, y1, x2, y2, dx, dy, S1, S2;
    x1 = 0;
    y1 = 0;
    x2 = 200,
    y2 = -200;
    dx = (x2 - x1);
    dy = (y2 - y1);
    int x = x1;
    int y = y1;
    int i = 1;
    int e = (2 * abs(dy)) - abs(dx);
    while (x1 < x2)
    {
        glBegin(GL_POINTS);
        glVertex2d(x, y);
        glEnd();
        if (e >= 0)
        {
            if (dy < 0)
            {
                y -= 1;
            }
            else
            {
                y++;
            }
            e = e - (2 * dx);
        }
        if (dx < 0)
        {
            x -= 1;
        }
        else
        {
            x++;
        }
        e = e + (2 * dy);
        i++;
    }
    glFlush();
}

void display(void)
{
    glBegin(GL_LINES);
    glVertex2d(600, 0);
    glVertex2d(-600, 0);
    glVertex2d(0, -400);
    glVertex2d(0, 400);
    glEnd();
    glFlush();
}
void DDAmenu(int k)
{
    switch (k)
    {
    case 1:
        DD_simple();
        break;
    case 2:
        DD_dotted();
        break;
    case 3:
        DD_dashed();
        break;
    case 4:
        DD_thick();
        break;
    case 5:
        break;
    }
}
void BREmenu(int j)
{
    switch (j)
    {
    case 1:
        bre_simple();
        break;
    // case 2:
    //     DD_dotted();
    //     break;
    // case 3:
    //     DD_dashed();
    //     break;
    case 4:
        bre_thick();
        break;
    case 5:
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
    submain_menu1 = glutCreateMenu(DDAmenu);
    glutAddMenuEntry("1.DDA Simple Line", 1);
    glutAddMenuEntry("2.DDA Dotted Line", 2);
    glutAddMenuEntry("3.DDA Dashed Line", 3);
    glutAddMenuEntry("4.DDA Thick Line", 4);
    submain_menu2 = glutCreateMenu(BREmenu);
    glutAddMenuEntry("1.BRE Simple Line", 1);
    glutAddMenuEntry("2.BRE Dotted Line", 2);
    glutAddMenuEntry("3.BRE Dashed Line", 3);
    glutAddMenuEntry("4.BRE Thick Line", 4);
    mainmenu = glutCreateMenu(DDAmenu);
    glutAddSubMenu("1.DDA", submain_menu1);
    glutAddSubMenu("2.Bresenham", submain_menu2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    myInit();
    glutMainLoop();
}