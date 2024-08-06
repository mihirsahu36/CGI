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
