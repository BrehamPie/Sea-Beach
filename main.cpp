#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<windows.h>
#include<bits/stdc++.h>

//Global Variables
GLfloat eye[3] = {50,0,50},look[3]={};
GLfloat up[3]= {0,1,0};
float fovy=90;

//external header files
#include "geometry.h"
#include "primitives.h"
#include "begin.h"
#include "display.h"
#include "keyboard.h"
#include "animation.h"
int main(int argc,char **argv) {

    // Reset Global Variables
    initialize();

    // Initialize GLUT Library.
    glutInit(&argc,argv);

    // Determine OpenGL Display mode for the to-be-created window.
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB| GLUT_DEPTH);
    // Double Buffer, RGB color, Depth Buffer

    // Specify Upper Left Corner of to-be-created Window.
    glutInitWindowPosition(100,0);

    // Specify the size of to-be-created window in pixels.
    glutInitWindowSize(1100,700);

    // Select Mode of Shading - Flat or Smooth. Need Lighting to see difference.
    glShadeModel(GL_SMOOTH);

    // Create Window with title.
    glutCreateWindow("Sea Beach");

    // Enable Necessary Capabilities.
    glEnable(GL_DEPTH_TEST );
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);

    // Specify Keyboard function.
    glutKeyboardFunc(keyBoardFunction);
    // Specify display function.
    glutDisplayFunc(Display);

    // Specify idle function.
    glutIdleFunc(animation);

    // Start event processing.
    glutMainLoop();
}

