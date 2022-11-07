
void speedboat(){
    unsigned int boatID;
    glPushMatrix();
    glTranslatef(25,5,55);
    glRotatef(135,0,1,0);
//    LoadTextureV2(woodTexture);
    float backside[][3]={{0,0,0},{0,0,5},{0,5,5},{0,5,0}};
    float front1[][3]={{0,0,5},{13,0,5},{13,3,5},{0,3,5}};
    float front2[][3]={{0,0,0},{13,0,0},{13,3,0},{0,3,0}};
    float join1[][3] = {{13,0,5},{18,3,2.5},{13,3,5}};
    float join2[][3] = {{13,0,0},{18,3,2.5},{13,3,0}};
    float join3[][3] = {{13,0,0},{18,3,2.5},{13,0,5}};
    float lowpart[][3] = {{0,0,0},{13,0,0},{13,0,5},{0,0,5}};
    float uppart[][3] = {{10,3,0},{13,3,0},{18,3,2.5},{13,3,5},{10,3,5}};
    float texcord[][2]={{0,0},{0,1},{1,1},{1,0}};
    float color[]={1,1,1};
    drawPolygon(backside,4,color,texcord);
    drawPolygon(front1,4,color,texcord);
    drawPolygon(front2,4,color,texcord);
    drawPolygon(join1,3,color,texcord);
    drawPolygon(join2,3,color,texcord);
    drawPolygon(join3,3,color,texcord);
    drawPolygon(lowpart,4,color,texcord);

    //float texcord2[][2]={{0,1},{0.5,1},{1,0.5},{0.5,0},{0,0}};
    //LoadTexture("D:\\Computer Graphics\\Sea Beach\\Textures\\ship2.bmp",boatID);

    drawPolygon(uppart,5,color,texcord);
    glPopMatrix();

}
