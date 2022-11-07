void sky(){
    glPushMatrix();
    GLUquadricObj *quad;
    quad = gluNewQuadric();
    glTranslatef(0,-500,0);
    glRotatef(180,1,0,0);
    gluQuadricTexture(quad,true);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,2);
    gluSphere(quad,1000,50,50);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,0);
    glPopMatrix();
}
