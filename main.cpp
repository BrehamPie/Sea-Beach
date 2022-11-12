#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<windows.h>
#include<bits/stdc++.h>

//external header files
#include "variables.h"
#include "texturing.h"
#include "TexFiles.h"
#include "geometry.h"
#include "primitives.h"
#include "Bezier.h"
#include "sky.h"
#include "beach_area.h"
#include "wave.h"
#include "sun.h"
#include "bicycle.h"
#include "beach_chair.h"
#include "volleyball.h"
#include "human.h"
#include "lighthouse.h"
#include "speedboat.h"
#include "ship.h"
#include "umbrella.h"
#include "linear_motion.h"
#include "angular_motion.h"
#include "display.h"
#include "keyboard.h"
#include "animation.h"


#include "begin.h"
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
    //glutFullScreen();
    // Enable Necessary Capabilities.
    glEnable(GL_DEPTH_TEST );
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    glColorMaterial(GL_FRONT,GL_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    // Specify Keyboard function.
    glutKeyboardFunc(keyBoardFunction);
    LoadTextureInMemory();
    // Specify display function.
    glutDisplayFunc(Display);

    // Specify idle function.
    glutIdleFunc(animation);

    // Start event processing.
    glutMainLoop();
}

