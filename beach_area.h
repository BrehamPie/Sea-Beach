void beach_area(){

   // LoadTextureV2(sandTexture);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,1);
    glPushMatrix();
    glTranslatef(20,0,-100);
    glScalef(200,3,500);
    GLfloat col[] = {1,1,1};
   // glScalef(80,3,300);
    drawCube(col);
    glPopMatrix();
    glPushMatrix();
 //   LoadTextureV2(waterTexture);
    glBindTexture(GL_TEXTURE_2D,7);
    glTranslatef(-980,0,-500);
    glScalef(1000,3,1000);
    drawCube(col);
   // glDeleteTextures(1,&waterID);
    glPopMatrix();
    glBindTexture(GL_TEXTURE_2D,0);
    glDisable(GL_TEXTURE_2D);
}

