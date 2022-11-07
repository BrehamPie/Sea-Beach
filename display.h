void Display(){
 // Clear Current Buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Select Matrix for Operation
    glMatrixMode(GL_PROJECTION);
    // Load identity matrix
    glLoadIdentity();

    // Choose frustum - Further the near plane bigger the object.
    // glFrustum(-6,6,-6,6,nearP,farP);//left right bottom top

    gluPerspective(fovy,1,1,5000);
    // Select Matrix for Operation
    glMatrixMode(GL_MODELVIEW);

    // Load identity matrix
    glLoadIdentity();

    // Set Camera Definition.
    gluLookAt(eye[0],eye[1],eye[2],look[0],look[1],look[2],up[0],up[1],up[2]);

    //lower corner and height,width of view port.
    glViewport(0,0,1366,768);
    //umbrella();
    /*//ship();*/

    glColor3f(1,1,1);
    //sky();
    beach_area();
   // sun();
    sunLight();
drawCycle();
    //wave();
   // chair();
   /* //
    //lighthouse();
    //speedboat();
    glTranslatef(90,15,50);
    glRotatef(90,0,0,1);*/
   // bottleBezier();
    // execute all issued command quickly.
    glFlush();
    //Swap front and back buffer for smooth viewing.
    glutSwapBuffers();


}
