// Develop a program to demonstrate 2D transformation on basic objects

#include <GL/glut.h>
#include <stdio.h>
void myinit()
{
    gluOrtho2D(-500, 500, -500, 500);
}

void drawtriangle()
{
    glBegin(GL_POLYGON);
        glVertex2f(100, 100);
        glVertex2f(200, 100);
        glVertex2f(150, 150);
    glEnd();
}

void translate()
{
    glPushMatrix();
        glTranslated(100, 0, 0);
        drawtriangle();
    glPopMatrix();
}

void rotate_triangle()
{
    glPushMatrix();
        glRotated(45, 0, 0, 1);
        drawtriangle();
    glPopMatrix();
}

void pivot_point_rotate()
{
    glColor3f(1, 1, 0); // Yellow
    glPushMatrix();
        glTranslated(100, 100, 0);   // translate back to the original position
        glRotated(45, 0, 0, 1);      // Rotate degree 45
        glTranslated(-100, -100, 0); // translate to Origin
        drawtriangle();
    glPopMatrix();
}

void scale_triangle()
{
    glPushMatrix();
        glScaled(2, 2, 1);
        drawtriangle();
    glPopMatrix();
}

void pivot_point_scale()
{
    glColor3d(1, 1, 0); // yellow
    glPushMatrix();
        glTranslated(100, 100, 0);
        glScaled(2, 2, 1);
        glTranslated(-100, -100, 0);
        drawtriangle();
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 1, 1, 0);
    glColor3f(1, 0, 0); // Red
    drawtriangle();
    // glutPostReDisplay();
    glFlush();
}

void menu_rotate(int id)
{
    switch (id)
    {
    case 1:
        translate();
        break;
    case 2:
        rotate_triangle();
        break;
    case 3:
        pivot_point_rotate();
        break;
    case 4:
        scale_triangle();
        break;
    case 5:
        pivot_point_scale();
        break;
    default:
        exit(0);
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Transformation");
    myinit();
    glutDisplayFunc(display);
    glutCreateMenu(menu_rotate);

    glutAddMenuEntry("Translate", 1);
    glutAddMenuEntry("Rotation About origin", 2);
    glutAddMenuEntry("Rotation About Fixed Point", 3);
    glutAddMenuEntry("Scale About origin", 4);
    glutAddMenuEntry("Scale About Fixed Point", 5);
    glutAddMenuEntry("EXIT", 6);

    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}
