#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

int x1,y11,x2,y2;
int x,y,dx,dy,m,p;
int incx=1;
int incy=1;

void init(){
  glClear(GL_COLOR_BUFFER_BIT)
  glClearColor(1,0,0,0)
  glOrthod2D(0,500,0,500)
}

void plotpoint(int x,int y){
  glColor3d(1,1,1);
  glBegin(GL_POINT)
  glVertex2f(x,y)
  glEnd()
}

void breshmans(int x1,int y11,int x2,int y2){
  x=x1;
  y=y11;
  dx=abs(x2-x1);
  dy=abs(y2-y11);
  if(x2<x1){
    incx=-1;
  }
  if(y2<y11){
    incy=-1;
  }
  m=(y2-y11)/(x2-x1);
  if(m<1){
    plotpoint(x1,y11);
    p=2*dy-dx;
    if(p<0){
      x=x+incx;
      p=p+2*dy;
    }
    else{
      y=y+incy;
      p=p+2*dy-2*dx;
    }
    plotpoint(x1,y11)
      }
}

void display(){
  glClearColor(1,0,0);
  breshamans(x1,y11,x2,y2);
  glFlush();
}

void main(int char, char **argv){
  printf("Enter first set of points:");
  scanf("%d%d",&x1,&y11);
  printf("Enter second set of points:");
  scanf("%d%d",&x2,&y2);
  glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham's Line Drawing Algorithm");
    myinit();
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}


#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

float x[3][3]={{1,0,100},{0,50,100},{1,1,1}};
float r[3][3];

void init(){
  glClearColor(1,0,0);
  glOrtho2D(500,0,500,0);
}

void triangle(float x[3][3]){
  glColor3D(1,1,0);
  glBegin(GL_TRIANGLE);
  glVertex2f(x[0][0],x[1][0]);
  glVertex2f(x[0][1],x[1][1]);
  glVertex2f(x[0][2],x[1][2]);
  glEnd();
}

void matrixmul(float mul[3][3]){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        float r[i][j]=0;
        for(int k=0;k<3;k++){
          r[i][j]=r[i][j]+mul[i][k]*r[k][j];
        }
    }
  }
}

void translate(){
  float t[3][3]={{1,0,0},{0,1,0},{0,0,1}};
  printf("Enter the value of tx and ty:");
  scanf("%d%d",&t[0][2],&t[1][2]);
  matrixmul(t);
  traingle(r);
}

void scale(){
  float s[3][3]={{1,0,0},{0,1,0},{0,0,1}};
  printf("Enter the value of sx and sy:");
  scanf("%d%d",&s[0][0],&s[1][1]);
  matrixmul(s);
  traingle(r);
}

void rotate(){
  float theta=0;
  printf("Enter the theta angle:");
  scanf("%f",&theta);
  float angle=theta*3.14/180;
  cosx=cos(angle);
  sinx=sin(angle);
  float r[3][3]={{-cosx,sinx,1},{sinx,cosx,1},{1,1,1}};
  matrixmul(rr);
  triangle(r);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1, 0, 0);
    int ch;
    while (1)
    {
        glColor3d(1, 1, 1);
        printf("Enter the choice: \n0 for normal triangle \n1 for translation \n2 for scaling \n3 for rotation\n4 for exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 0:
            triangle(x);
            break;
        case 1:
            translation();
            break;
        case 2:
            scaling();
            break;
        case 3:
            rotation();
            break;
        case 4:
            exit(0);
        default:
            printf("\nEnter a valid choice.");
            break;
        }

        glColor3d(1, 0, 0);
        triangle(x);
        glFlush();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Line Drawing Algorithm");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

typedef float point[3];
point v[] = {{0.0, 0.0, 1.0},
             {0.0, 1.0, 0.0},
             {-1.0, -1.0, 0.0},
             {1.0, -1.0, 0.0}};

int n;
void triangle(point a, point b, point c)
{
    glBegin(GL_TRIANGLES);
        glVertex3fv(a);
        glVertex3fv(b);
        glVertex3fv(c);
    glEnd();
}

void divide_tri(point a, point b, point c, int m)
{
    point v1, v2, v3;
    int j;
    if (m > 0)
    {
        for (j = 0; j < 3; j++)
            v1[j] = (a[j] + b[j]) / 2;
        for (j = 0; j < 3; j++)
            v2[j] = (a[j] + c[j]) / 2;
        for (j = 0; j < 3; j++)
            v3[j] = (b[j] + c[j]) / 2;

        divide_tri(a, v1, v2, m - 1);
        divide_tri(c, v2, v3, m - 1);
        divide_tri(b, v3, v1, m - 1);
    }
    else
    {
        triangle(a, b, c);
    }
}

void tetrahedron(int m)
{
    glColor3f(1.0, 0.0, 0.0);
    divide_tri(v[0], v[1], v[2], m);
    glColor3f(0.0, 0.0, 0.0);
    divide_tri(v[3], v[2], v[1], m);
    glColor3f(0.0, 1.0, 0.0);
    divide_tri(v[0], v[3], v[1], m);
    glColor3f(0.0, 0.0, 1.0);
    divide_tri(v[0], v[2], v[3], m);
}

void display()
{
    tetrahedron(n);
    glFlush();
}

void myinit()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
}

int main(int argc, char **argv)
{
    printf("\nEnter the number of recursive steps you want: ");
    scanf("%d", &n);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D Sierpinski's Gasket");
    glutDisplayFunc(display);
    myinit();
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}


#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

void init(){
  glClearColor(1,0,0);
  glOrthod2D(50,0,50,0);
}

void drawtriangle()
{
    glBegin(GL_POLYGON);
        glVertex2f(100, 100);
        glVertex2f(200, 100);
        glVertex2f(150, 150);
    glEnd();
}

void translate(){
  glPushMatrix();
  glTranslated(100,0,0);
  drawtriangle();
  glPopMatrix();
}

void scale(){
  glPushMatrix();
  glScaled(2,0,0);
  drawtriangle();
  glPopMatrix();
}

void rotate(){
  glPushMatrix();
  glRotated(45,0,0);
  drawtriangle();
  glPopMatrix();
}

void pivot_scale(){
  glPushMatrix();
  glTranslated(100,0,0);
  glScaled(2,0,0);
  glTranslated(-100,0,0);
  drawtriangle();
  glPopMatrix();
}

void pivot_rotate(){
  glPushMatrix();
  glTranslated(100,0,0);
  glRotated(45,0,0);
  glTranslated(-100,0,0);
  drawtriangle();
  glPopMatrix();
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
