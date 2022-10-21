void Display(){
 // Clear Current Buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Select Matrix for Operation
    glMatrixMode(GL_PROJECTION);

    // Load identity matrix
    glLoadIdentity();

    // Choose frustum - Further the near plane bigger the object.
    // glFrustum(-6,6,-6,6,nearP,farP);//left right bottom top

    gluPerspective(fovy,1,5,500);
    // Select Matrix for Operation
    glMatrixMode(GL_MODELVIEW);

    // Load identity matrix
    glLoadIdentity();

    // Set Camera Definition.
    gluLookAt(eye[0],eye[1],eye[2],look[0],look[1],look[2],up[0],up[1],up[2]);

    //lower corner and height,width of view port.
    glViewport(0,0,1100,700);
    GLfloat a[]={1,1,1};
    drawCube(a);
    // execute all issued command quickly.
    glFlush();

    //Swap front and back buffer for smooth viewing.
    glutSwapBuffers();


}
