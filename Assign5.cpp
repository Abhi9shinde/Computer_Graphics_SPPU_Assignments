#include <iostream>
#include <GL/glut.h>
using namespace std;
static int mainmenu;
double Xmin, Ymin, Xmax, Ymax, x1, y1, x2, y2, Xvmin, Yvmin, Xvmax, Yvmax;
int temp, done, accept, x, y;
const int L = 8, R = 4, B = 2, T = 1;

int regcode(double x, double y)
{
    int code = 0;
    if (x < Xmin)
    {
        code = L;
    }
    if (x > Xmax)
    { 
        code = R;
    }
    if (y < Ymin)
    {
        code = B;
    }
    if (y > Ymax)
    {
        code = T;
    }
    return code;
}
void LineClip(double x1, double y1, double x2, double y2)
{
    int outcode1, outcode2;
    accept = 0;
    done = 0;
    double M = double(y2 - y1) / (x2 - x1);
    outcode1 = regcode(x1, y1);
    outcode2 = regcode(x2, y2);
    do
    {
        if (outcode1 == 0 && outcode2 == 0)
        { // visible
            accept = 1;
            done = 1;
        }
        else if ((outcode1 & outcode2) != 0)
        { // invisible
            done = 1;
        }
        else
        {
            if (outcode1 == 0)
            {
                temp = outcode2;
            }
            else
            {
                temp = outcode1;
            }

            if (temp & T)
            {
                y = Ymax;
                x = (Ymax - y1) / M + x1;
            }
            else if (temp & B)
            {
                y = Ymin;
                x = (Ymin - y1) / M + x1;
            }
            else if (temp & R)
            {
                x = Xmax;
                y = M * (Xmax - x1) + y1;
            }
            else if (temp & L)
            {
                x = Xmin;
                y = M * (Xmin - x1) + y1;
            }
            if (temp == outcode1)
            {
                x1 = x;
                y1 = y;
                outcode1 = regcode(x1, y1);
            }
            if (temp == outcode2)
            {
                x2 = x;
                y2 = y;
                outcode2 = regcode(x2, y2);
            }
        }

    } while (done == 0);
    if (accept)
    {
        double sx = (Xvmax - Xvmin) / (Xmax - Xmin);
        double sy = (Yvmax - Yvmin) / (Ymax - Ymin);
        double vx1 = Xvmin + (x1 - Xmin) * sx;
        double vy1 = Yvmin + (y1 - Ymin) * sy;
        double vx2 = Xvmax + (x2 - Xmax) * sx;
        double vy2 = Yvmax + (y2 - Ymax) * sx;
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINE_LOOP);
        glVertex2d(Xvmin, Yvmin);
        glVertex2d(Xvmin, Yvmax);
        glVertex2d(Xvmax, Yvmax);
        glVertex2d(Xvmax, Yvmin);
        glEnd();
        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_LINES);
        glVertex2d(vx1, vy1);
        glVertex2d(vx2, vy2);
        glEnd();
    }
}
void Init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(0.0, 0.0, 0.0);
    gluOrtho2D(0.0, 1000.0, 0, 1000.0);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(Xmin, Ymin);
    glVertex2d(Xmin, Ymax);
    glVertex2d(Xmax, Ymax);
    glVertex2d(Xmax, Ymin);
    glEnd();
    glBegin(GL_LINE_STRIP);

    glVertex2d(x1, y1); // for drawing the line
    glVertex2d(x2, y2);
    glEnd();
    glFlush();
}
void cmenu(int x)
{
    switch (x)
    {
    case 1:
        LineClip(x1, y1, x2, y2);
        break;
    case 2:
        break;
    }
}

int main(int argc, char **argv)
{
    Xmin = 50;
    Ymin = 50;
    Xmax = 300;
    Ymax = 300;
    Xvmin = 250;
    Yvmin = 250;
    Xvmax = 500;
    Yvmax = 500;

    x1 = 40;
    y1 = 100;
    x2 = 310;
    y2 = 250;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Cohen Sutherland");
    mainmenu = glutCreateMenu(cmenu);
    glutDisplayFunc(display);
    glutAddMenuEntry("****MENU*****", 0);
    glutAddMenuEntry("1.Line Clipping", 1);
    glutAddMenuEntry("2.Exit", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    Init();
    glutDisplayFunc(display);
    glutMainLoop();
}
