#include <GL/glut.h>
#include <math.h>
#include <cstdlib>
#include "parkinglot.h"
using namespace std;
void CarPark()
{
    glColor3f(0.0,0.0,0.0 );//black lines
//outer fram
    glBegin( GL_LINE_STRIP);
    glVertex3f(-120,-80,0);
    glVertex3f(-120,90,0);
    glVertex3f(120,90,0);
    glVertex3f(120,-60,0);
    glVertex3f(-86,-60,0);
    glEnd();
    //inner datails
    glBegin(GL_LINES);
    //bottom
    glVertex3f(-86,-70,0);//1
    glVertex3f(-86,-40,0);
    glVertex3f(-52,-60,0);//2
    glVertex3f(-52,-40,0);
    glVertex3f(-18,-60,0);//3
    glVertex3f(-18,-40,0);
    glVertex3f(16,-60,0);//4
    glVertex3f(16,-40,0);
    glVertex3f(50,-60,0);//5
    glVertex3f(50,-40,0);
    glVertex3f(84,-60,0);//6
    glVertex3f(84,-40,0);
    //top
    glVertex3f(-86,70,0);//1
    glVertex3f(-86,90,0);
    glVertex3f(-52,70,0);//2
    glVertex3f(-52,90,0);
    glVertex3f(-18,70,0);//3
    glVertex3f(-18,90,0);
    glVertex3f(16,70,0);//4
    glVertex3f(16,90,0);
    glVertex3f(50,70,0);//5
    glVertex3f(50,90,0);
    glVertex3f(84,70,0);//6
    glVertex3f(84,90,0);
    glEnd();
    glColor3f(0.4f, 0.2f, 0.7f);    //color
    glRectf(-80,7, 80, 25);  //center rectangle
}