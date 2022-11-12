void ballanimation() {
    if(ballstate==0) {
        if(ballx>=32) {
            ballman[2].humTheta[3]-=3;
            ballman[2].humTheta[5]-=3;
            ballman[2].humTheta[11]-=3;
            ballman[2].humTheta[12]+=3;
        }
    } else {
        if(ballman[2].humTheta[3]<90) {
            ballman[2].humTheta[3]+=3;
            ballman[2].humTheta[5]+=3;
            ballman[2].humTheta[11]+=3;
            ballman[2].humTheta[12]-=3;
        }
    }
    if(ballstate==1) {
        if(ballx<=20) {
            ballman[1].humTheta[3]-=3;
            ballman[1].humTheta[5]-=3;
            ballman[1].humTheta[11]-=3;
            ballman[1].humTheta[12]+=3;
        }
    } else {
        if(ballman[1].humTheta[3]<90) {
            ballman[1].humTheta[3]+=3;
            ballman[1].humTheta[5]+=3;
            ballman[1].humTheta[11]+=3;
            ballman[1].humTheta[12]-=3;
        }
    }
    if(ballstate==2) {
        if(ballx>=32) {
            ballman[3].humTheta[3]-=3;
            ballman[3].humTheta[5]-=3;
            ballman[3].humTheta[11]-=3;
            ballman[3].humTheta[12]+=3;
        }
    } else {
        if(ballman[3].humTheta[3]<90) {
            ballman[3].humTheta[3]+=3;
            ballman[3].humTheta[5]+=3;
            ballman[3].humTheta[11]+=3;
            ballman[3].humTheta[12]-=3;
        }
    }
    if(ballstate==3) {
        if(ballx<=20) {
            ballman[0].humTheta[3]-=3;
            ballman[0].humTheta[5]-=3;
            ballman[0].humTheta[11]-=3;
            ballman[0].humTheta[12]+=3;
        }
    } else {
        if(ballman[0].humTheta[3]<90) {
            ballman[0].humTheta[3]+=3;
            ballman[0].humTheta[5]+=3;
            ballman[0].humTheta[11]+=3;
            ballman[0].humTheta[12]-=3;
        }
    }
    ballman[0].human();
    ballman[1].human();
    ballman[2].human();
    ballman[3].human();
    if(ballstate==0) {
        ballx+=0.26;
        if(ballx>=39)ballstate = 1;
        else bally = 10*sqrt(1 - (pow(ballx-26,2)/(169)));
    }
    if(ballstate==1) {
        ballx-=0.26;
        if(ballx<13) {
            ballstate = 2;
            return;
        }
        bally = 10*sqrt(1 - (pow(ballx-26,2)/(169)));
        ballz = (-7*ballx+351)/13;
    }
    if(ballstate==2) {
        ballx+=0.26;
        if(ballx>39)ballstate = 3;
        else {
            bally = 10*sqrt(1 - (pow(ballx-26,2)/(169)));
        }
    }
    if(ballstate==3) {
        ballx-=0.26;
        if(ballx<13)ballstate = 0;
        else {
            bally = 10*sqrt(1 - (pow(ballx-26,2)/(169)));
            ballz = (7*ballx - 13)/13;
        }
    }
}
void animation() {
    sunLight();
    ballanimation();
    glutPostRedisplay();
}
