#ifndef BMPLOADER_H
#define BMPLOADER_H
#include<windows.h>
class BmpLoader {
  public:
    unsigned char* textureData;
    int iWidth, iHeight;

    BmpLoader(const char*);
    ~BmpLoader();

  private:
    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
};

#endif // BMPLOADER_H


BmpLoader::BmpLoader(const char* filename) {
    FILE *file=0;
    file=fopen(filename, "rb");
    if(!file)
        std::cout<<"File not found"<<std::endl;
    fread(&bfh, sizeof(BITMAPFILEHEADER),1,file);
    if(bfh.bfType != 0x4D42)
        std::cout<<"Not a valid bitmap"<<std::endl;
    fread(&bih, sizeof(BITMAPINFOHEADER),1,file);
    if(bih.biSizeImage==0)
        bih.biSizeImage=bih.biHeight*bih.biWidth*3;
    textureData = new unsigned char[bih.biSizeImage];
    fseek(file, bfh.bfOffBits, SEEK_SET);
    fread(textureData, 1, bih.biSizeImage, file);
    unsigned char temp;
    for(int i=0; i<bih.biSizeImage; i+=3) {
        temp = textureData[i];
        textureData[i] = textureData[i+2];
        textureData[i+2] = temp;

    }

    iWidth = bih.biWidth;
    iHeight = bih.biHeight;
    fclose(file);
}

BmpLoader::~BmpLoader() {
    delete [] textureData;
}


unsigned int textureID[200];

void LoadTexture(const char*filename, int idx)
{
    glGenTextures(1, &textureID[idx]);
    glBindTexture(GL_TEXTURE_2D, textureID[idx]);
    glPixelStorei(GL_UNPACK_ALIGNMENT, textureID[idx]);
  //  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
   // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    BmpLoader bl(filename);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bl.iWidth, bl.iHeight, GL_RGB, GL_UNSIGNED_BYTE, bl.textureData );
}

