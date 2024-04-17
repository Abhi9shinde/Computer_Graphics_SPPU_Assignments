#include <iostream>
#include <GL/glut.h>
#include <cmath>
using namespace std;

static int main_menu, submain_menu;
float x1, y1, x2, y2, x3, y3, ABC1[3][2];
void myInit();
void display(void);
void dis_ori();
void translation();
void rotation();
void shearing();
void reflection();
void scaling();
void menu(int);

void myInit(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1000, 1000, -1000, 1000);
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex2d(1000, 0);
    glVertex2d(-1000, 0);
    glVertex2d(0, 1000);
    glVertex2d(0, -1000);
    glEnd();
    dis_ori();
    glFlush();
}
void translation()
{
    int tx = 50;
    int ty = 70;
    ABC1[0][0] = x1;
    ABC1[0][1] = y1;

    ABC1[1][0] = x2;
    ABC1[1][1] = y2;

    ABC1[2][0] = x3;
    ABC1[2][1] = y3;

    ABC1[0][0] += tx;
    ABC1[1][0] += tx;
    ABC1[2][0] += tx;

    ABC1[0][1] += ty;
    ABC1[1][1] += ty;
    ABC1[2][1] += ty;

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(ABC1[0][0], ABC1[0][1]);
    glVertex2d(ABC1[1][0], ABC1[1][1]);
    glVertex2d(ABC1[2][0], ABC1[2][1]);
    glEnd();
    glFlush();
}
void scaling()
{
    float tx = 1.5;
    float ty = 2;
    ABC1[0][0] = x1;
    ABC1[0][1] = y1;

    ABC1[1][0] = x2;
    ABC1[1][1] = y2;

    ABC1[2][0] = x3;
    ABC1[2][1] = y3;

    ABC1[0][0] *= tx;
    ABC1[1][0] *= tx;
    ABC1[2][0] *= tx;

    ABC1[0][1] *= ty;
    ABC1[1][1] *= ty;
    ABC1[2][1] *= ty;

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(ABC1[0][0], ABC1[0][1]);
    glVertex2d(ABC1[1][0], ABC1[1][1]);
    glVertex2d(ABC1[2][0], ABC1[2][1]);
    glEnd();
    glFlush();
}
void shearing()
{
}
void reflection()
{
}
void rotation()
{
}
void dis_ori()
{
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2d(x1, y1);
    glVertex2d(x2, y2);
    glVertex2d(x3, y3);
    glEnd();
    glFlush();
}
void menu(int x)
{
    switch (x)
    {
    case 1:
        translation();
        break;
    case 2:
        rotation();
        break;
    case 3:
        reflection();
        break;
    case 4:
        shearing();
        break;
    case 5:
        scaling();
        break;
    }
}
int main(int argc, char *argv[])
{
    x1 = 0;
    y1 = 0;

    x2 = 400;
    y2 = 0;

    x3 = 200;
    y3 = 400;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("2D Transformation");
    myInit();
    glutDisplayFunc(display);

    submain_menu = glutCreateMenu(menu);
    glutAddMenuEntry("***MENU***", 0);
    glutAddMenuEntry("Translation", 1);
    glutAddMenuEntry("Rotation", 2);
    glutAddMenuEntry("Reflection", 3);
    glutAddMenuEntry("Shearing", 4);
    glutAddMenuEntry("Scaling", 5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
}