void courtLine() {
    float red[]= {1,0,0};
    float points[][3]= {{0,0,0},{52,0,0},{52,0,26},{0,0,26}};
    drawLine(points[0],points[1],red);
    drawLine(points[1],points[2],red);
    drawLine(points[2],points[3],red);
    drawLine(points[3],points[0],red);
}
void net() {
    GLUquadricObj *quad;
    quad = gluNewQuadric();
    gluQuadricTexture(quad,true);

    glPushMatrix();
    glTranslatef(26,0,-.5);
    glRotatef(270,1,0,0);
    gluCylinder(quad,.16,.16,8,20,20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(26,0,26.5);
    glRotatef(270,1,0,0);
    gluCylinder(quad,.16,.16,8,20,20);
    glPopMatrix();
    glPushMatrix();
    float A[]={26,8,-.5};
    float B[]={26,8,26.5};
    drawLine(A,B,white);
    A[1] = 4.5;
    B[1] = 4.5;
    drawLine(A,B,white);
    A[1] = 8;
    for(float i=0;i<=27;i+=1.3){
        A[2] = i;
        B[2] = i;
        drawLine(A,B,white);
    }
    A[0] = 26;
    B[0] = 26;
    A[2] = 0;
    B[2] = 26;
     for(float i=4.5;i-8<=0.0000001;i+=0.7){
        A[1] = i;
        B[1] = i;
        drawLine(A,B,white);
    }
    glPopMatrix();

}
float ballx,bally,ballz;
int ballstate;
void ball(){
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(ballx,bally,ballz);
    GLUquadricObj *quad;
    quad = gluNewQuadric();
    gluQuadricTexture(quad,true);
    glBindTexture(GL_TEXTURE_2D,8);
    gluSphere(quad,1,50,50);
    glPopMatrix();
    glDisable(GL_TEXTURE);
}
void volleyball() {
    glPushMatrix();
    courtLine();
    net();
    ball();
    glPopMatrix();
}
