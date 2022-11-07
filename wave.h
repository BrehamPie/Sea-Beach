float moved;
float ang;
void wave() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,7);
    GLUquadricObj *quad;
    quad = gluNewQuadric();
    gluQuadricTexture(quad,true);
    for(int j=0; j<40; j++) {
        for(int i=0; i<8; i++) {
            glPushMatrix();
            glTranslatef(20-i*25,3,-50+j*6);
            // glRotatef(ang,0,0,1);

            gluSphere(quad,4,32,32);
            glPopMatrix();
        }
    }

    /* moved =  fmod(moved+.3,10);
     ang = fmod(ang+20,180);
     glPushMatrix();
     glTranslatef(moved,0,-20);
     glRotatef(ang,0,0,1);
     GLUquadricObj *quadratic;
     quadratic = gluNewQuadric();
     //glRotatef(90,0,0,0);
     gluQuadricTexture(quadratic,true);
     LoadTexture("D:\\Computer Graphics\\Sea Beach\\Textures\\water3.bmp",waterID);
     gluCylinder(quadratic,3,3,82.0f,32,32);
     glDeleteTextures(1,&waterID);
     glPopMatrix();*/
}
