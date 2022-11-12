void ballanimation() {
    if(ballstate==0) {
            ballman[0].humTheta[3]++;
        ballx+=0.3;
        if(ballx>39)ballstate = 1;
        else bally = 10*sqrt(1 - (pow(ballx-26,2)/(169)));
    }
    if(ballstate==1) {
        ballx-=0.3;
        if(ballx<13) {
            ballstate = 2;
            return;
        }
        bally = 10*sqrt(1 - (pow(ballx-26,2)/(169)));
        ballz = (-7*ballx+351)/13;
    }
    if(ballstate==2) {
        ballx+=0.3;
        if(ballx>39)ballstate = 3;
        else {
            bally = 10*sqrt(1 - (pow(ballx-26,2)/(169)));
        }
    }
    if(ballstate==3){
        ballx-=0.3;
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
