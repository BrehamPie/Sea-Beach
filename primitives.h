float default_ambient[]={.2,.2,.2};
float default_diffuse[]={.8,.8,.8};
float default_specular[] = {0,0,0};
void drawLine(GLfloat A[],GLfloat B[],const GLfloat Color[]) {
    glPushMatrix();
    glColor3fv(&Color[0]);
    glBegin(GL_LINES);
    glVertex3fv(&A[0]);
    glVertex3fv(&B[0]);
    glEnd();
    glPopMatrix();
}
void drawPolygon(GLfloat a[][3],int n,GLfloat color[],GLfloat t[][2]) {
    glPushMatrix();
    glBegin(GL_POLYGON);
    GLfloat mat_ambient[] = { color[0], color[1],color[2], 1.0 };
    GLfloat mat_diffuse[] = { color[0], color[1],color[2], 1.0 };
    GLfloat mat_specular[] = { color[0], color[1],color[2], 1.0 };
    GLfloat mat_shininess[] = {60};
    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    for(int i=0; i<n; i++) {
        glVertex3fv(&a[i][0]);glTexCoord2fv(&t[i][0]);
    }
    glEnd();
    glMaterialfv( GL_FRONT, GL_AMBIENT, default_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, default_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, default_specular);
    glPopMatrix();
}

// Draw a Single Quad
void drawQuad(GLfloat A[],GLfloat B[],GLfloat C[],GLfloat D[],GLfloat color[]) {
    glPushMatrix();
    GLfloat mat_ambient[] = { color[0], color[1],color[2], 1.0 };
    GLfloat mat_diffuse[] = { color[0], color[1],color[2], 1.0 };
    GLfloat mat_specular[] = { color[0], color[1],color[2], 1.0 };
    GLfloat mat_shininess[] = {60};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    glBegin(GL_QUADS);
    getNormal3p(A,B,C);
    glVertex3fv(&A[0]);glTexCoord2f(0,1);
    glVertex3fv(&B[0]);glTexCoord2f(1,1);
    glVertex3fv(&C[0]);glTexCoord2f(1,0);
    glVertex3fv(&D[0]);glTexCoord2f(0,0);
    glEnd();
    glPopMatrix();
     glMaterialfv( GL_FRONT, GL_AMBIENT, default_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, default_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, default_specular);

}

void drawTriangle(GLfloat color[]) {
    glBegin(GL_TRIANGLES);

}
//Draw main axis line
void drawMainAxis() {
    glPushMatrix();
    glScalef(50,50,50);
    GLfloat A[]= {0,0,0};
    GLfloat B[]= {1,0,0};
    GLfloat D[] = {0,1,0};
    GLfloat E[] = {0,0,1};
    GLfloat c1[]= {1,0,0};
    GLfloat c2[] = {0,1,0};
    GLfloat c3[] = {0,0,1};

    drawLine(A,B,c1);
    drawLine(A,D,c2);
    drawLine(A,E,c3);
    glPopMatrix();
    return;
}
// Draw 1*1*1 cube.
void drawCube(GLfloat color[]) {

    GLfloat vertex[8][3] = {
        {0.0, 0.0, 0.0},
        {1.0, 0.0, 0.0},
        {1.0, 1.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0},
        {1.0, 0.0, 1.0},
        {1.0, 1.0, 1.0},
        {0.0, 1.0, 1.0}
    };

    GLubyte index[6][4] = {
        {3, 2, 1, 0},
        {4, 5, 6, 7},
        {1,5,4,0},
        {7, 6, 2, 3},
        {7, 3, 0, 4},
        {1, 2, 6, 5,}
    };
    for(int i=0; i<6; i++) {
        drawQuad(vertex[index[i][0]],
                 vertex[index[i][1]],
                 vertex[index[i][2]],
                 vertex[index[i][3]],color);
    }
}

