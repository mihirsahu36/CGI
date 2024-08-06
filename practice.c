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
