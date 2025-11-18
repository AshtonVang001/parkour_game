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

void _inputs::keyPressed(_camera* myCamera, float deltaTime)
{
    //cout << wParam << endl;           //to get keyboard input


    float moveSpeed = 10.0f * deltaTime;        //this num changes mvmnt speed

    // Sprint
    if (keys[16])
        moveSpeed *= 2;

    // Forward / Back
    if (keys['W'])
        myCamera->moveForward(moveSpeed);
    if (keys['S'])
        myCamera->moveForward(-moveSpeed);

    // Left / Right
    if (keys['A'])
        myCamera->moveRight(-moveSpeed);
    if (keys['D'])
        myCamera->moveRight(moveSpeed);
}

/*
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
*/




void _inputs::keyUp()
{
    switch(wParam)
    {
        default: break;
    }
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

void _inputs::mouseMove(_camera* cam, double x, double y)
{

    /*float cx = screenWidth / 2;
    float cy = screenHeight / 2;

    float dx = x - cx;
    float dy = y - cy;

    cam->yaw += dx * cam->sensitivity;
    cam->pitch -= dy * cam->sensitivity;

    cam->updateRotation();

    //recenter the mouse
    SetCursorPos(cx, cy);*/

}
