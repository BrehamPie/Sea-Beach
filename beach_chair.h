unsigned int chairID;
void chair(){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,9);
    float c[] = {1,1,1};
    glPushMatrix();
    glPushMatrix();
    glTranslatef(147,5,54);
    glRotatef(90,0,1,0);
    //glScalef(4,4,4);
    glPushMatrix();
    glTranslatef(0,2,0);
    glScalef(3,.5,6);
    drawCube(c);
    glPopMatrix();

    glPushMatrix();
    glScalef(.2,2,.2);
    glTranslatef(0,0,0);
    drawCube(c);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.8,0,0);
    glScalef(.2,2,.2);
    drawCube(c);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.8,0,5.8);
    glScalef(.2,2,.2);
    drawCube(c);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,5.8);
    glScalef(.2,2,.2);
    drawCube(c);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,2,6);
    glRotatef(-45,1,0,0);
    glScalef(3,0.5,2);
    drawCube(c);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();

}


