void ship(){
    GLUquadricObj *quad;
    quad = gluNewQuadric();
    //glRotatef(90,0,1,0);

    //Body
    float white[]={1,1,1};
    float points_bottom[][3]={{0,0,-0.3},{0.1,0,-0.4},{4,0,-0.4},{4,0,0.4},{0.1,0,0.4},{0,0,0.3}};
    float points_bottomtexCord[][2]={{0,0},{0,-0.4},{0.1,-0.5},{5,0},{4,0.5},{0.1,0.5},{0,0.4}};
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,5);
    glScalef(20,20,20);
    drawPolygon(points_bottom,6,white,points_bottomtexCord);
    glPopMatrix();

    glPushMatrix();
    //glTranslatef(0,0,-2);
    glScalef(20,20,20);
    glBindTexture(GL_TEXTURE_2D,4);
    float front_tri[][3] = {{4,0,-0.4},{4,0,0.4},{5,1.5,0}};
    glBegin(GL_TRIANGLES);
    glVertex3fv(front_tri[0]);
    glVertex3fv(front_tri[1]);
    glVertex3fv(front_tri[2]);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    float points_top[][3]={{0,0,-0.4},{0.1,0,-0.5},{4,0,-0.5},{5,0,0},{4,0,0.5},{0.1,0,0.5},{0,0,0.4}};
    glTranslatef(0,30,0);
    glScalef(20,20,20);
    drawPolygon(points_top,7,white,points_bottomtexCord);
    glPopMatrix();

    glPushMatrix();
    //sides
    glScalef(20,30,20);
    glBindTexture(GL_TEXTURE_2D,4);
    float side1[][3]={{0,0,-0.3},{0.1,0,-0.4},{0.1,1,-0.5},{0,1,-0.4}};
    float side2[][3]={{0,0,0.3},{0.1,0,0.4},{0.1,1,0.5},{0,1,0.4}};
    float side3[][3]={{0.1,0,-0.4},{4,0,-0.4},{4,1,-0.5},{0.1,1,-0.5}};
    float side4[][3]={{0.1,0,0.4},{4,0,0.4},{4,1,0.5},{0.1,1,0.5}};
    float side5[][3] = {{4,0,-0.4},{5,1,0},{5,1,0},{4,1,-0.5}};
    float side6[][3] = {{4,0,0.4},{5,1,0},{5,1,0},{4,1,0.5}};
    float side7[][3] = {{0,0,-0.3},{0,0,0.3},{0,1,0.4},{0,1,-0.4}};
    drawQuad(side1[0],side1[1],side1[2],side1[3],white);
    drawQuad(side2[0],side2[1],side2[2],side2[3],white);
    drawQuad(side3[0],side3[1],side3[2],side3[3],white);
    drawQuad(side4[0],side4[1],side4[2],side4[3],white);
    drawQuad(side5[0],side5[1],side5[2],side5[3],white);
    drawQuad(side6[0],side6[1],side6[2],side6[3],white);
    drawQuad(side7[0],side7[1],side7[2],side7[3],white);
    glDisable(GL_TEXTURE_2D);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,6);
    glTranslatef(5,30,-10);
    glScalef(33,20,20);
    drawCube(white);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    //railing

    glPushMatrix();
    gluQuadricTexture(quad,true);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,4);
    glTranslatef(0,30,0);
    glPushMatrix();
    glTranslatef(98,0,0);
    glRotatef(90,0,0,1);
    glRotatef(90,1,0,0);
    glRotatef(90,0,1,0);
    glScalef(1,1,1);
    gluCylinder(quad,0.5,0.5,7,30,30);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glPushMatrix();
     gluQuadricTexture(quad,true);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,4);
    glTranslatef(0,30,0);
    glPushMatrix();
    glTranslatef(80,0,-9.5);
    glRotatef(90,0,0,1);
    glRotatef(90,1,0,0);
    glRotatef(90,0,1,0);
    glScalef(1,1,1);
    gluCylinder(quad,0.5,0.5,7,30,30);
    glPopMatrix();
        glDisable(GL_TEXTURE_2D);

    glPopMatrix();

    glPushMatrix();
     gluQuadricTexture(quad,true);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,4);
    glTranslatef(0,30,0);
    glPushMatrix();
    glTranslatef(80,0,9.5);
    glRotatef(90,0,0,1);
    glRotatef(90,1,0,0);
    glRotatef(90,0,1,0);
    glScalef(1,1,1);
    gluCylinder(quad,0.5,0.5,7,30,30);
    glPopMatrix();
        glDisable(GL_TEXTURE_2D);

    glPopMatrix();

    glPushMatrix();
     gluQuadricTexture(quad,true);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,4);
    glTranslatef(0,30,0);
    glPushMatrix();
    glTranslatef(40,0,-9.5);
    glRotatef(90,0,0,1);
    glRotatef(90,1,0,0);
    glRotatef(90,0,1,0);
    glScalef(1,1,1);
    gluCylinder(quad,0.5,0.5,7,30,30);
    glPopMatrix();
        glDisable(GL_TEXTURE_2D);

    glPopMatrix();

    glPushMatrix();
     gluQuadricTexture(quad,true);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,4);
    glTranslatef(0,30,0);
    glPushMatrix();
    glTranslatef(40,0,9.5);
    glRotatef(90,0,0,1);
    glRotatef(90,1,0,0);
    glRotatef(90,0,1,0);
    glScalef(1,1,1);
    gluCylinder(quad,0.5,0.5,7,30,30);
    glPopMatrix();
        glDisable(GL_TEXTURE_2D);

    glPopMatrix();

    float rail1[][3]={{98,0,0},{80,0,-9.5},{80,1,-9.5},{98,1,0}};
    float rail2[][3]={{98,0,0},{80,0,9.5},{80,1,9.5},{98,1,0}};
    float rail3[][3] = {{40,0,-9.5},{80,0,-9.5},{80,1,-9.5},{40,1,-9.5}};
    float rail4[][3] = {{40,0,9.5},{80,0,9.5},{80,1,9.5},{40,1,9.5}};
    glPushMatrix();
     gluQuadricTexture(quad,true);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,4);
    glTranslatef(0,35,0);
    drawQuad(rail1[0],rail1[1],rail1[2],rail1[3],white);
        glDisable(GL_TEXTURE_2D);

    glPopMatrix();

    glPushMatrix();
     gluQuadricTexture(quad,true);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,4);
    glTranslatef(0,32,0);
    drawQuad(rail1[0],rail1[1],rail1[2],rail1[3],white);
        glDisable(GL_TEXTURE_2D);

    glPopMatrix();

    glPushMatrix();
     gluQuadricTexture(quad,true);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,4);
    glTranslatef(0,35,0);
    drawQuad(rail2[0],rail2[1],rail2[2],rail2[3],white);
        glDisable(GL_TEXTURE_2D);

    glPopMatrix();

    glPushMatrix();
     gluQuadricTexture(quad,true);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,4);
    glTranslatef(0,32,0);
    drawQuad(rail2[0],rail2[1],rail2[2],rail2[3],white);
        glDisable(GL_TEXTURE_2D);

    glPopMatrix();


    //Rail3-4 two pieces
    glPushMatrix();
     gluQuadricTexture(quad,true);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,4);
    glTranslatef(0,35,0);
    drawQuad(rail3[0],rail3[1],rail3[2],rail3[3],white);
        glDisable(GL_TEXTURE_2D);

    glPopMatrix();

    glPushMatrix();
     gluQuadricTexture(quad,true);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,4);
    glTranslatef(0,32,0);
    drawQuad(rail3[0],rail3[1],rail3[2],rail3[3],white);
        glDisable(GL_TEXTURE_2D);

    glPopMatrix();

    glPushMatrix();
     gluQuadricTexture(quad,true);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,4);
    glTranslatef(0,35,0);
    drawQuad(rail4[0],rail4[1],rail4[2],rail4[3],white);
        glDisable(GL_TEXTURE_2D);

    glPopMatrix();

    glPushMatrix();
     gluQuadricTexture(quad,true);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,4);
    glTranslatef(0,32,0);
    drawQuad(rail4[0],rail4[1],rail4[2],rail4[3],white);
        glDisable(GL_TEXTURE_2D);

    glPopMatrix();
    //Big Box

    //masters room




}
