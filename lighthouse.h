void lighthouse(){
    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();
    glPushMatrix();
    glTranslatef(30,0,0);
    glPushMatrix();
    glRotatef(-90,1,0,0);
    gluQuadricTexture(quadratic,true);
//    LoadTextureV2(brickTexture1);
    gluCylinder(quadratic,10,8,15,32,32);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,15,0);
    glRotatef(-90,1,0,0);
//    LoadTextureV2(brickTexture2);
    gluCylinder(quadratic,6,3,35,32,32);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,50,0);
    glRotatef(-90,1,0,0);
  //  LoadTextureV2(brickTexture3);
    gluCylinder(quadratic,2,2,7,32,32);
    glPopMatrix();

    glPopMatrix();
}
