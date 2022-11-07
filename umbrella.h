void umbrella() {
    //float points[][3]={{1,0,0},{0.5,0,0.5},{0,0,1},{-0.5,0,0.5},{-1,0,0},{-0.5,0,-0.5},{0,0,-1},{0.5,0,-0.5}};
    float points[][3]= {{0,0,0},{-0.5,-1,-0.5},{0.5,-1,-0.5}};
    glPushMatrix();
    GLUquadricObj *quad;
    quad = gluNewQuadric();
    gluQuadricTexture(quad,true);
    glTranslatef(150,13,50);
    GLfloat white[]= {1,1,1};
    GLfloat notext[][2]= {{0,0},{1,0},{1,1},{0,1}};
    glPushMatrix();
    //glTranslatef(0,-10,0);
    glRotatef(90,1,0,0);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,4);
    gluCylinder(quad,.1,.1,10,10,9.5);
    glPopMatrix();
    float cur = 0;
    for(int i=0; i<12; i++) {
        glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,8);
        glScalef(3,1,3);
        points[1][0] = cos(cur*PI/180);
        points[1][2] = sin(cur*PI/180);
        cur+=30;
        points[2][0] = cos(cur*PI/180);
        points[2][2] = sin(cur*PI/180);
        //glRotatef(46,1,0,0);
        drawPolygon(points,3,white,notext);
        glBindTexture(GL_TEXTURE_2D,0);
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();
    }
    glPopMatrix();
}
