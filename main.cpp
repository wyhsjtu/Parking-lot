#include <GL/freeglut.h>
#include <cmath>
#include <ctime>
#include "figures.h"
#include <iostream>
#include "parkinglot.h"
#include "carparking.h"
#include "display.h"
using namespace std;

void TimeStep(int n) {
    glutTimerFunc(25, TimeStep, 0); glutPostRedisplay();
}

void ChangeSize( GLsizei w, GLsizei h ) {
    GLfloat nRange = 100.0f;
    // Prevent a divide by zero
    if(h == 0)
        h = 1;
    // Set Viewport to window dimensions
    glViewport(0, 0, w, h);
    // Reset projection matrix stack
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Establish clipping volume (left, right, bottom, top, near, far)
    if (w <= h)
        glOrtho (-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange, nRange);
    else
        glOrtho (-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange, nRange);
    // Reset Model view matrix stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize (800, 600);
    glutInitWindowPosition (0, 0);
    glutCreateWindow( "Interstellar Parking Lot" );
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(display);
    glutReshapeFunc( ChangeSize );
    glutTimerFunc(25, TimeStep, 0);
    glutMainLoop();
    return 1;
}