class Person {
  public:
#define WIN_WIDTH 800
#define WIN_HEIGHT 800
#define TORSO_HEIGHT 5.0
#define TORSO_RADIUS 1.3
#define UPPER_ARM_HEIGHT 2.5
#define LOWER_ARM_HEIGHT 2.3
#define UPPER_ARM_RADIUS  0.5
#define LOWER_ARM_RADIUS  0.5
#define UPPER_LEG_RADIUS  0.5
#define LOWER_LEG_RADIUS  0.5
#define LOWER_LEG_HEIGHT 3.1
#define UPPER_LEG_HEIGHT 3.3
#define HEAD_HEIGHT 1.2
#define HEAD_RADIUS 1.4
#define HAND_RADIUS 0.6
#define HAND_HEIGHT 0.9
#define FOOT_RADIUS 0.7
#define FOOT_HEIGHT 1.1
#define NECK_RADIUS 0.5
#define NECK_HEIGHT 1.0
#define JOINT_POINT_RADIUS 0.5
#define JOINT_POINT_HEIGHT 0.5

    bool flag1=true, flag2=false,
         flag3=true, flag4=false,
         flag5=true, flag6=false,
         hflag=true;

    /*
    Initialization of body parts' angles
    */
    /*
        0 - rotates whole body.
        1-2 - rotates neck.
        3 - rotate upper hand x axis.(right)
        4 - rotate lower hand x axis.
        5 - rotate upper hand x axis.(left)
        6 - rotate lower hand x axis
        7 - leg upper x axis
        8 - leg lower x axis
        9 - leg upper x axis
        10 - leg lower x axis
        11 - upper hand z axis
        12 - upper hand z axis
        13 - upper leg z axis
        14 -  upper leg z axis
        15-16 - foot

    */
    GLfloat humTheta[17] = {0.0,   0.0,   0.0, 90.0,
                                   -20.0, 90.0, -20.0, 180.0,
                                   0.0, 180.0, 0.0, 0.0,
                                   0.0, 0.0,  0.0, 0.0,
                                   0.0
                                  };
    GLint choise = 2;
    GLint m_choise = 0;

    /*
    Body parts
    */
    GLUquadricObj *t,   *h,   *n,    *lh,
                  *rh,   *lf,  *rf,   *jp,
                  *lhnd, *lft, *lua,  *lla,
                  *rua,  *rla, *lll,  *rll,
                  *rul,  *lul, *rhnd, *rft;
    /*
    Mouse control area & view point translation initialization
    */
    typedef struct _area {
        int id;
        int x, y;
        float min, max;
        float value;
        float step;
    } area;

    area translation[5] = {
        { 0, 120, 40, -30.0, 30.0, 0.0, 0.05,},
        { 1, 180, 40, -30.0, 30.0, 0.0, 0.05,},
        { 2, 180, 40, -200.0, 200.0, 0.0, 0.1,},
        { 3, 180, 120, -100, 100, 0.0, 0.5},
        { 4, 240, 120, -100, 100, 0.0, 0.5}
    };

    /*
    gluLookAt initial values, view point rotation
    */
    GLfloat hum_eye[3] = { 0.0, 0.0, 60.0 };
    GLfloat hum_at[3]  = { 0.0, 0.0, 0.0 };
    GLfloat hum_up[3]  = { 0.0, 1.0, 0.0 };

    /*
    Animation variables and angles
    */
    GLuint texture1=0;
    GLuint texture2=0;
    GLuint texture3=0;
    GLuint texture4=0;

    GLuint old_thetaW3=0;
    GLuint old_thetaX4=0;
    GLuint old_thetaE5=0;
    GLuint old_thetaC6=0;
    GLuint old_thetaS11=0;
    GLuint old_thetaD12=0;

    GLint selection = 0;

    void redisplay_all(void);


//TODO
    /*
     - Restart function
     - Stop animation function
     - More body parts' rotation
     - Rotation borders
    */
//--------------------------------draw body functions-------------------------------
    void head() {
        glPushMatrix();
        glRotatef(-90.0, 1.0, 0.0, 0.0);
        glRotatef(15.0, 0.0, 0.0, 1.0);
        glScalef(HEAD_HEIGHT, HEAD_HEIGHT, HEAD_RADIUS);

        h = gluNewQuadric();
        gluQuadricTexture(h,true);
        gluSphere(h,1.0,10,10);
        glPopMatrix();
    }

    void neck() {
        glPushMatrix();
        glRotatef(-90.0, 1.0, 0.0, 0.0);
        n = gluNewQuadric();
        gluQuadricTexture(n,true);
        gluCylinder(n,NECK_RADIUS, NECK_RADIUS, NECK_HEIGHT,10,10);
        glPopMatrix();
    }

    void torso() {
        glPushMatrix();
        glMaterialfv( GL_FRONT, GL_AMBIENT, default_ambient);
        glMaterialfv( GL_FRONT, GL_DIFFUSE, default_diffuse);
        glMaterialfv( GL_FRONT, GL_SPECULAR, default_specular);
        glMaterialfv(GL_FRONT,GL_EMISSION,default_diffuse);
        glRotatef(-90.0, 1.0, 0.0, 0.0);
        t = gluNewQuadric();
        gluQuadricTexture(t,true);
        //glScalef(TORSO_HEIGHT,3,5);
        //drawCube(white);
        gluCylinder(t,TORSO_RADIUS, TORSO_RADIUS, TORSO_HEIGHT,10,10);
        glPopMatrix();
    }

    void joint_point() {
        glPushMatrix();
        glScalef(JOINT_POINT_RADIUS, JOINT_POINT_HEIGHT,JOINT_POINT_RADIUS);

        jp = gluNewQuadric();
        gluQuadricTexture(jp,true);
        gluSphere(jp,1.0,10,10);
        glPopMatrix();
    }

    void left_upper_arm() {
        glPushMatrix();
        lua = gluNewQuadric();
        gluQuadricTexture(lua,true);
        gluCylinder(lua,UPPER_ARM_RADIUS, UPPER_ARM_RADIUS,UPPER_ARM_HEIGHT,10,10);
        glPopMatrix();
    }

    void left_lower_arm() {
        glPushMatrix();
        glRotatef(0.0, 1.0, 0.0, 0.0);
        lla = gluNewQuadric();
        gluQuadricTexture(lla,true);
        gluCylinder(lla,LOWER_ARM_RADIUS, LOWER_ARM_RADIUS,
                    LOWER_ARM_HEIGHT,10,10);
        glPopMatrix();
    }

    void left_hand() {
        glPushMatrix();
        glRotatef(90.0, 1.0, 0.0, 0.0);
        lhnd = gluNewQuadric();
        gluQuadricTexture(lhnd,true);
        glScalef(HAND_RADIUS, HAND_HEIGHT, HAND_RADIUS);
        gluSphere(lhnd,1.0,10,10);
        glPopMatrix();
    }

    void right_upper_arm() {
        glPushMatrix();
        rua = gluNewQuadric();
        gluQuadricTexture(rua,true);
        gluCylinder(rua,UPPER_ARM_RADIUS, UPPER_ARM_RADIUS,
                    UPPER_ARM_HEIGHT,10,10);
        glPopMatrix();
    }

    void right_lower_arm() {
        glPushMatrix();
        rla = gluNewQuadric();
        gluQuadricTexture(rla,true);
        gluCylinder(rla,LOWER_ARM_RADIUS, LOWER_ARM_RADIUS,
                    LOWER_ARM_HEIGHT,10,10);
        glPopMatrix();
    }

    void right_hand() {
        glPushMatrix();
        rhnd = gluNewQuadric();
        gluQuadricTexture(rhnd,true);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        glScalef(HAND_RADIUS, HAND_HEIGHT, HAND_RADIUS);
        gluSphere(rhnd,1.0,10,10);
        glPopMatrix();
    }

    void left_upper_leg() {
        glPushMatrix();
        lul = gluNewQuadric();
        glRotatef(-90.0, 1.0, 0.0, 0.0);
        gluQuadricTexture(lul,true);
        gluCylinder(lul,UPPER_LEG_RADIUS, UPPER_LEG_RADIUS,
                    UPPER_LEG_HEIGHT,10,10);
        glPopMatrix();
    }

    void left_lower_leg() {
        glPushMatrix();
        glRotatef(-90.0, 1.0, 0.0, 0.0);
        lll = gluNewQuadric();
        gluQuadricTexture(lll,true);
        gluCylinder(lll,LOWER_LEG_RADIUS, LOWER_LEG_RADIUS,
                    LOWER_LEG_HEIGHT,10,10);
        glPopMatrix();
    }

    void left_foot() {
        glPushMatrix();
        glRotatef(90.0, 1.0, 0.0, 0.0);
        lft = gluNewQuadric();
        gluQuadricTexture(lft,true);
        glScalef(FOOT_RADIUS, FOOT_HEIGHT, FOOT_RADIUS);
        gluSphere(lft,1.0,10,10);
        glPopMatrix();
    }

    void right_upper_leg() {
        glPushMatrix();
        glRotatef(-90.0, 1.0, 0.0, 0.0);
        rul = gluNewQuadric();
        gluQuadricTexture(rul,true);
        gluCylinder(rul,UPPER_LEG_RADIUS, UPPER_LEG_RADIUS,
                    UPPER_LEG_HEIGHT,10,10);
        glPopMatrix();
    }

    void right_lower_leg() {
        glPushMatrix();
        glRotatef(-90.0, 1.0, 0.0, 0.0);
        rll = gluNewQuadric();
        gluQuadricTexture(rll,true);
        gluCylinder(rll,LOWER_LEG_RADIUS, LOWER_LEG_RADIUS,
                    LOWER_LEG_HEIGHT,10,10);
        glPopMatrix();
    }

    void right_foot() {
        glPushMatrix();
        rft = gluNewQuadric();
        gluQuadricTexture(rft,true);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        glScalef(FOOT_RADIUS, FOOT_HEIGHT, FOOT_RADIUS);
        gluSphere(rft,1.0,10,10);
        glPopMatrix();
    }

    void human() {
        glPushMatrix();

        glScalef(0.85,0.85,0.85);
        glEnable(GL_TEXTURE_2D);
        glPushMatrix();

        glBindTexture(GL_TEXTURE_2D, 13);
        glRotatef(humTheta[0], 0.0, 1.0, 0.0);
        torso();

        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, 15);
        glTranslatef(0,TORSO_HEIGHT, 0.0);
        neck();
        glBindTexture(GL_TEXTURE_2D, 15);
        glTranslatef(0.0, NECK_HEIGHT+0.5*HEAD_HEIGHT, 0.0);
        glRotatef(humTheta[1], 1.0, 0.0, 0.0);
        glRotatef(humTheta[2], 0.0, 1.0, 0.0);
        head();
        glPopMatrix();//add JOINT_POINT_

        glPushMatrix();//add JOINT_POINT_
        glBindTexture(GL_TEXTURE_2D, 13);
        glTranslatef(-0.85*(TORSO_RADIUS+JOINT_POINT_RADIUS),0.9*TORSO_HEIGHT, 0.0);
        joint_point();
        glBindTexture(GL_TEXTURE_2D, 13);
        glTranslatef(0.0, 0.0, 0.0);
        glRotatef(humTheta[3], 1.0, 0.0, 0.0);
        glRotatef(humTheta[11], 0.0, 0.0, 1.0);
        left_upper_arm();
        glBindTexture(GL_TEXTURE_2D, 15);
        glTranslatef(0.0, 0.0,UPPER_ARM_HEIGHT);
        joint_point();
        glBindTexture(GL_TEXTURE_2D, 15);
        glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
        glRotatef(humTheta[4], 1.0, 0.0, 0.0);
        left_lower_arm();
        glBindTexture(GL_TEXTURE_2D, 15);
        glTranslatef(0.0, 0.0, LOWER_ARM_HEIGHT);
        left_hand();
        glPopMatrix();


        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, 13);
        glTranslatef(0.85*(TORSO_RADIUS+JOINT_POINT_RADIUS),0.9*TORSO_HEIGHT, 0.0);
        joint_point();
        glBindTexture(GL_TEXTURE_2D, 13);
        glTranslatef(0.0, 0.0, 0.0);
        glRotatef(humTheta[5], 1.0, 0.0, 0.0);
        glRotatef(humTheta[12], 0.0, 0.0, 1.0);
        right_upper_arm();
        glBindTexture(GL_TEXTURE_2D, 15);
        glTranslatef(0.0, 0.0, UPPER_ARM_HEIGHT);
        joint_point();
        glBindTexture(GL_TEXTURE_2D, 15);
        glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
        glRotatef(humTheta[6], 1.0, 0.0, 0.0);
        right_lower_arm();
        glBindTexture(GL_TEXTURE_2D, 15);
        glTranslatef(0.0, 0.0, LOWER_ARM_HEIGHT);
        right_hand();
        glPopMatrix();

        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, 14);
        glTranslatef(-(TORSO_RADIUS-JOINT_POINT_RADIUS),-0.15*JOINT_POINT_HEIGHT, 0.0);
        joint_point();
        glBindTexture(GL_TEXTURE_2D, 14);
        glTranslatef(0, 0.1*JOINT_POINT_HEIGHT, 0.0);
        glRotatef(humTheta[7], 1.0, 0.0, 0.0);
        glRotatef(humTheta[13], 0.0, 0.0, 1.0);
        left_upper_leg();
        glBindTexture(GL_TEXTURE_2D, 14);
        glTranslatef(0.0, UPPER_LEG_HEIGHT, 0.0);
        joint_point();
        glBindTexture(GL_TEXTURE_2D, 15);
        glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
        glRotatef(humTheta[8], 1.0, 0.0, 0.0);
        left_lower_leg();
        glBindTexture(GL_TEXTURE_2D, 10);
        glTranslatef(0.0, LOWER_LEG_HEIGHT, -0.5*FOOT_HEIGHT);
        glRotatef(humTheta[15], 1.0, 0.0, 0.0);
        left_foot();
        glPopMatrix();


        glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, 14);
        glTranslatef(TORSO_RADIUS-JOINT_POINT_RADIUS,-0.15*JOINT_POINT_HEIGHT, 0.0);
        joint_point();
        glBindTexture(GL_TEXTURE_2D,14);
        glTranslatef(0, 0.1*JOINT_POINT_HEIGHT, 0.0);
        glRotatef(humTheta[9], 1.0, 0.0, 0.0);
        glRotatef(humTheta[14], 0.0, 0.0, 1.0);
        right_upper_leg();
        glBindTexture(GL_TEXTURE_2D, 14);
        glTranslatef(0.0, UPPER_LEG_HEIGHT, 0.0);
        joint_point();
        glBindTexture(GL_TEXTURE_2D, 15);
        glTranslatef(0.0, 0.1*JOINT_POINT_HEIGHT, 0.0);
        glRotatef(humTheta[10], 1.0, 0.0, 0.0);
        right_lower_leg();
        glBindTexture(GL_TEXTURE_2D, 10);
        glTranslatef(0.0, LOWER_LEG_HEIGHT, -0.5*FOOT_HEIGHT);
        glRotatef(humTheta[16], 1.0, 0.0, 0.0);
        right_foot();
        glPopMatrix();
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();
    }
};
Person ballman[4];
