unsigned int sunID;
GLfloat sunPosition[] = {0,200,0};
GLfloat white[]= {1,1,1};
GLfloat black[]= {0,0,0};
void sun() {
    //LoadTextureV2(sunTexture);
    glPushMatrix();
    glTranslatef(0,100,0);
    GLUquadricObj *quad;
    quad = gluNewQuadric();
    gluQuadricTexture(quad,true);
    glMaterialfv(GL_FRONT,GL_EMISSION,white);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,3);
    gluSphere(quad,3,100,100);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    // glMaterialfv(GL_FRONT,GL_EMISSION,clearColor);
    glMaterialfv( GL_FRONT, GL_AMBIENT, default_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, default_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, default_specular);
    glMaterialfv(GL_FRONT,GL_EMISSION,default_specular);

  /*  glPushMatrix();
    glEnable(GL_BLEND);
    glColor4f(1.0f,1.0f,1.0f,0.2f);		// Full Brightness, 50% Alpha ( NEW )
	glBlendFunc(GL_SRC_ALPHA,GL_ONE);
    glTranslatef(0,100,0);
    GLfloat mat_ambient[] = { 1,1,1, 0.2 };
    GLfloat mat_diffuse[] = { 1,1,1, 0.2 };
    GLfloat mat_specular[] = { 1,1,1, 0.2 };
    glMaterialfv(GL_FRONT,GL_EMISSION,black);
    GLfloat mat_shininess[] = {60};
    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    glRotatef(90,0,1,0);
    glutSolidSphere(4.5,50,50);
	glDisable(GL_BLEND);
	glPopMatrix();*/
}
void sunLight() {

    glEnable(GL_LIGHT0);
    glLightfv( GL_LIGHT0, GL_AMBIENT,white);
    glLightfv( GL_LIGHT0, GL_DIFFUSE,white);
    glLightfv( GL_LIGHT0, GL_SPECULAR,white);
    glLightfv( GL_LIGHT0, GL_POSITION,sunPosition);
}
