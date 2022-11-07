void keyBoardFunction(unsigned char key,int x,int y) {
    switch(key) {
    case 'g':
        moveForward(look,eye);
        break;
    case '+':
        zoomIn();
        break;
    case '-':
        zoomOut();
        break;
    case '4':
        Yaw(eye,look,up,bita);
        break;
    case '6':
        Yaw(eye,look,up,bita,false);
        break;
    case '8':
        Pitch(eye,look,up,theta);
        break;
    case '2':
        Pitch(eye,look,up,theta,false);
        break;
    case '7':
        Roll(eye,look,up,alpha);
        break;
    case '9':
        Roll(eye,look,up,alpha,false);
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}
