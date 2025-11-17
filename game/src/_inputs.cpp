#include "_inputs.h"

_inputs::_inputs()
{
    //ctor
    isRotationActive = false;
    isTranslationActive = false;
    //isScalingActive = false;
}






_inputs::~_inputs()
{
    //dtor
}





void _inputs::keyPressed(_model* mdl)
{
    switch(wParam) {
    case VK_LEFT:
        mdl->rotateY += 1.0;
        break;
    case VK_RIGHT:
        mdl->rotateY -= 1.0;
        break;
    case VK_UP:
        mdl->rotateX += 1.0;
        break;
    case VK_DOWN:
        mdl->rotateX -= 1.0;
        break;
    case VK_ADD:
        mdl->rotateZ += 1.0;
        break;
    case VK_SUBTRACT:
        mdl->rotateZ -= 1.0;
        break;
    }
}

void _inputs::keyPressed(_parallax* prlx) {
    switch(wParam) {
    case VK_LEFT:
        prlx->prlxScrollAuto("right", 0.005);
        break;
    case VK_RIGHT:
        prlx->prlxScrollAuto("left", 0.005);
        break;
    case VK_UP:
        //prlx->
        break;
    case VK_DOWN:
        //prlx->
        break;
    case VK_ADD:
        //prlx->
        break;
    case VK_SUBTRACT:
        //prlx->
        break;
    }
}

void _inputs::keyPressed(_skyBox* sky)
{
    switch(wParam) {
    case VK_LEFT:
        sky->rotation.y -= 1.0;
        break;
    case VK_RIGHT:
        sky->rotation.y += 1.0;
        break;
    case VK_UP:
        sky->rotation.x += 1.0;
        break;
    case VK_DOWN:
        sky->rotation.x -= 1.0;
        break;
    case VK_ADD:
        //prlx->
        break;
    case VK_SUBTRACT:
        //prlx->
        break;
    }
}

void _inputs::keyPressed(_sprite* mySprite)
{
    switch(wParam) {
    case VK_RIGHT:
        mySprite->actionTrigger = mySprite->WALKRIGHT;
        break;
    case VK_LEFT:
        mySprite->actionTrigger = mySprite->WALKLEFT;
        break;
    }
}

void _inputs::keyPressed(_camera* myCamera)
{
    //cout << wParam << endl;           //to get keyboard input

    switch(wParam) {
    case 83:
        myCamera->camMoveFdBd(1);
        break;
    case 87:
        myCamera->camMoveFdBd(-1);
        break;
    case 68:
        myCamera->camMoveLtRt(1);
        break;
    case 65:
        myCamera->camMoveLtRt(-1);
        break;

    /**
    case 73:        //i
        myCamera->rotAngle.y -= 1.0;
        myCamera->rotateXY();
        break;
    case 74:        //j
        myCamera->rotAngle.x += 1.0;
        myCamera->rotateXY();
        break;
    case 75:        //k
        myCamera->rotAngle.y += 1.0;
        myCamera->rotateXY();
        break;
    case 76:        //l
        myCamera->rotAngle.x -= 1.0;
        myCamera->rotateXY();
        break;
    case 32:        //space bar
        myCamera->camReset();
        break;
    **/
    }


    /*********************************************************
    if(GetKeyState('W') & 0x8000) {myCamera->camMoveFdBd(-1);}
    if(GetKeyState('S') & 0x8000) {myCamera->camMoveFdBd(1);}
    if(GetKeyState('A') & 0x8000) {myCamera->camMoveLtRt(-1);}
    if(GetKeyState('D') & 0x8000) {myCamera->camMoveLtRt(1);}
    *********************************************************/
}

void _inputs::keyPressed(_3DModelLoader* Ply, _3DModelLoader* Wpn)
{
    switch(wParam) {
        case 83:
            Wpn->actionTrigger = Ply->actionTrigger = Ply->RUN;
            break;
        case 32:
            Wpn->actionTrigger = Ply->actionTrigger = Ply->JUMP;
            break;
        case 68:
            Wpn->actionTrigger = Ply->actionTrigger = Ply->ATTACK;
            break;
        case 65:
            Wpn->actionTrigger = Ply->actionTrigger = Ply->PAIN;
            break;
        default:
            Wpn->actionTrigger = Ply->actionTrigger = Ply->STAND;
            break;
    }
}






void _inputs::keyUp()
{
    switch(wParam)
    {
        default: break;
    }
}

void _inputs::keyUp(_sprite* mySprite) {
        mySprite->actionTrigger = mySprite->STAND;
}






void _inputs::mouseEventDown(_model* mdl, double x, double y)
{
    prev_MouseX = x;
    prev_MouseY = y;

    switch(wParam)
    {
    case MK_LBUTTON:
        isRotationActive = true;                            //activate rotation flag
        break;
    case MK_RBUTTON:
        isTranslationActive = true;                         //activate translation flag
        break;
    case MK_MBUTTON:
        break;
    }
}






void _inputs::mouseEventUp()
{
    isRotationActive = false;                               //deactivate flags
    isTranslationActive = false;
}






void _inputs::mouseWheel(_model* mdl, double delta)
{
    mdl->posZ += delta / 100.0;                             //zoom model when wheel in action
}






void _inputs::mouseMove(_model* mdl, double x, double y)
{
    if(isRotationActive){                                   //if rotation
        mdl->rotateY += (x - prev_MouseX) / 3.0;            //around y axis
        mdl->rotateX += (y - prev_MouseY) / 3.0;            //around x axis
    }
    if(isTranslationActive){                                //if translation
        mdl->posX += (x - prev_MouseX) / 100.0;             //change x position
        mdl->posY -= (y - prev_MouseY) / 100.0;             //change y position
    }

    prev_MouseX = x;                                        //reset mouse x
    prev_MouseY = y;                                        //reset mouse y
}

void _inputs::mouseMove(_camera* myCamera, double x, double y)
{

    myCamera->rotAngle.y = (y / 10.0);
    myCamera->rotAngle.x = (x / 10.0);
    //myCamera->rotateXY();

}
