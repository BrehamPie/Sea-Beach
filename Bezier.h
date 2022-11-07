//
//
//int anglex= 0, angley = 0, anglez = 0;          //rotation angles
//int window;
//int wired=0;
//int shcpt=1;
//int animat = 0;
//const int L=4;
//const int dgre=3;
//int ncpt=L+1;
//int clikd=0;
//const int nt = 30;				//number of slices along x-direction
//const int ntheta = 30;
//
//
////GLfloat ctrlpoints[L+1][3] = {
////    { 0.0, 0.0, 0.0}, { -0.3, 0.5, 0.0},
////    { 0.1, 1.7, 0.0},{ 0.5, 1.5, 0.0},
////    {1.0, 1.5, 0.0}, {1.4, 1.4, 0.0},
////    {1.8, 0.4, 0.0},{2.2, 0.4, 0.0},
////    {2.6, 1.5, 0.0}, {3.0, 1.4, 0.0},
////    {3.4, 1.4, 0.0},{3.8, 1.4, 0.0},
////    {4.2, 1.0, 0.0},{4.6, 1.0, 0.0},
////    {5.0, 1.0, 0.0},{5.4, 1.0, 0.0},
////    {5.8, 0.5, 0.0},{6.2, 0.5, 0.0},
////    {6.6, 0.5, 0.0},{7.2, 0.2, 0.0},
////    {6.8, 0.52, 0.0}
////};
//GLfloat ctrlpoints[L+1][3] = {
//    { 0.2, 0.2, 0.0},{0.25,.5,0},{.5,1,0},{0.75,.25,0},{.8,.2,0}
//};
//
//
//double ex=0, ey=0, ez=15, lx=0,ly=0,lz=0, hx=0,hy=1,hz=0;
//
//float wcsClkDn[3],wcsClkUp[3];
/////////////////////////////////
//class point1 {
//  public:
//    point1() {
//        x=0;
//        y=0;
//    }
//    int x;
//    int y;
//} clkpt[2];
////control points
//long long nCr(int n, int r) {
//    if(r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
//    long long ans = 1;
//    int i;
//
//    for(i = 1; i <= r; i++) {
//        ans *= n - r + i;
//        ans /= i;
//    }
//
//    return ans;
//}
//
////polynomial interpretation for N points
//void BezierCurve ( double t,  float xy[2]) {
//    double y=0;
//    double x=0;
//    t=t>1.0?1.0:t;
//    for(int i=0; i<=L; i++) {
//        int ncr=nCr(L,i);
//        double oneMinusTpow=pow(1-t,double(L-i));
//        double tPow=pow(t,double(i));
//        double coef=oneMinusTpow*tPow*ncr;
//        x+=coef*ctrlpoints[i][0];
//        y+=coef*ctrlpoints[i][1];
//
//    }
//    xy[0] = float(x);
//    xy[1] = float(y);
//
//    //return y;
//}
//void setNormal(GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3) {
//    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;
//
//    Ux = x2-x1;
//    Uy = y2-y1;
//    Uz = z2-z1;
//
//    Vx = x3-x1;
//    Vy = y3-y1;
//    Vz = z3-z1;
//
//    Nx = Uy*Vz - Uz*Vy;
//    Ny = Uz*Vx - Ux*Vz;
//    Nz = Ux*Vy - Uy*Vx;
//
//    glNormal3f(-Nx,-Ny,-Nz);
//}
//void bottleBezier() {
//    float add = 0;
//    float addz = 0;
//A:
//    glPushMatrix();
//    glTranslatef(15+addz,3,50+add);
//    glRotatef(90,0,1,0);
//    //glRotatef(90,1,0,0);
//    //if(add%2==0)glRotatef(90,1,0,0);
//    //else glRotatef(270,1,0,0);
//    glScalef(5,5,5);
//    int i, j;
//    float x, y, z, r;				//current coordinates
//    float x1, y1, z1, r1;			//next coordinates
//    float theta;
//
//    const float startx = 0, endx = ctrlpoints[L][0];
//    //number of angular slices
//    const float dx = (endx - startx) / nt;	//x step size
//    const float dtheta = PI / ntheta;		//angular step size
//
//    float t=0;
//    float dt=1.0/nt;
//    float xy[2];
//    BezierCurve( t,  xy);
//    x = xy[0];
//    r = xy[1];
//    //rotate about z-axis
//    float p1x,p1y,p1z,p2x,p2y,p2z;
//    //step through x
//    for ( i = 0; i < nt; ++i ) {
//        theta = 0;
//        t+=dt;
//        BezierCurve( t,  xy);
//        x1 = xy[0];
//        r1 = xy[1];
////        LoadTextureV2(woodTexture);
//        //draw the surface composed of quadrilaterals by sweeping theta
//        glEnable(GL_TEXTURE_2D);
//        glBindTexture(GL_TEXTURE_2D,7);
//        glBegin( GL_QUAD_STRIP );
//        for ( j = 0; j <= ntheta; ++j ) {
//            theta += dtheta;
//            double cosa = cos( theta );
//            double sina = sin ( theta );
//            y = r * cosa;
//            y1 = r1 * cosa;	//current and next y
//            z = r * sina;
//            z1 = r1 * sina;	//current and next z
//
//            //edge from point at x to point at next x
//            glVertex3f (x, y, z);
//            glTexCoord2f(0,0);
//
//            if(j>0) {
//                setNormal(p1x,p1y,p1z,p2x,p2y,p2z,x, y, z);
//            } else {
//                p1x=x;
//                p1y=y;
//                p1z=z;
//                p2x=x1;
//                p2y=y1;
//                p2z=z1;
//
//            }
//            glVertex3f (x1, y1, z1);
//            glTexCoord2f(0,1);
//
//            //forms quad with next pair of points with incremented theta value
//        }
//        glEnd();
//        x = x1;
//        r = r1;
//    } //for i
//    glPopMatrix();
//    add+=3.5;
//    if(add<100) goto A;
//    addz+=1;
//    add=0;
//    if(addz<3)goto A;
//
//}
