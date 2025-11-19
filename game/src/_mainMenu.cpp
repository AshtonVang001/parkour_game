#include "_mainMenu.h"
#include "gltfModel.h"
#include "_gltfLoader.h"
#include <iostream>

_mainMenu::_mainMenu()
{
    myTime = new _timer();

    // Set all pointers null until initGL()
    myLight = nullptr;
    myModel = nullptr;
    myInput = nullptr;
    myTexture = nullptr;
    myPrlx = nullptr;
    mySkyBox = nullptr;
    mySprite = nullptr;
    mdl3D = nullptr;
    mdl3DW = nullptr;
    myCam = nullptr;
    myCol = nullptr;
    snds = nullptr;

    myGltfModel = nullptr;
}

_mainMenu::~_mainMenu()
{
    delete myTime;

    delete myLight;
    delete myModel;
    delete myInput;
    delete myTexture;
    delete myPrlx;
    delete mySkyBox;
    delete mySprite;
    delete mdl3D;
    delete mdl3DW;
    delete myCam;
    delete myCol;
    delete snds;
    delete myGltfModel;
}

void _mainMenu::reSizeScene(int width, int height)
{
    float aspectRatio = (float)width / (float)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fov, aspectRatio, 0.1f, 1000.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    this->width = width;
    this->height = height;
}

void _mainMenu::initGL()
{
    // ---- Standard OpenGL setup ----
    glShadeModel(GL_SMOOTH);
    glClearColor(0,0,0,0);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // ---- Create subsystems ----
    myLight  = new _light();
    myModel  = new _model();
    myInput  = new _inputs();
    myTexture = new _textureLoader();
    myPrlx   = new _parallax();
    mySkyBox = new _skyBox();
    mySprite = new _sprite();
    mdl3D    = new _3DModelLoader();
    mdl3DW   = new _3DModelLoader();
    myCam    = new _camera();
    myCol    = new _collisionCheck();
    snds     = new _sounds();

    myTime->startTime = clock();

    // ---- Light ----
    myLight->setLight(GL_LIGHT0);

    // ---- Camera ----
    myCam->camInit();

    // ---- Sounds ----
    snds->initSounds();
    snds->playSound("sounds/untitled.mp3");

    menuTex->loadTexture("images/menuTexture.png");
}



void _mainMenu::updateScene()
{
    myTime->updateDeltaTime();

    static float smoothDT = 0.16f;
    smoothDT = (smoothDT * 0.9f) + (myTime->deltaTime * 0.1f);

    //myCam->updateVertical(myTime->deltaTime);
    myCam->rotateXY();

    animTime += myTime->deltaTime;

    if (myInput && myCam) {
        myInput->keyPressed(myCam, smoothDT);
        //myCam->update(smoothDT, myCol, ground);
    }
}


void _mainMenu::drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // Camera
    myCam->setUpCamera();



    // Draw UI
    glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, 1, 0, 1, -1, 1);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glDisable(GL_DEPTH_TEST);

        menuTex->bindTexture();

        glBegin(GL_QUADS);
            glTexCoord2f(0, 1); glVertex2f(0, 0);   // bottom-left
            glTexCoord2f(1, 1); glVertex2f(1, 0);   // bottom-right
            glTexCoord2f(1, 0); glVertex2f(1, 1);   // top-right
            glTexCoord2f(0, 0); glVertex2f(0, 1);   // top-left
        glEnd();

    glEnable(GL_DEPTH_TEST);
}

int _mainMenu::winMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_KEYDOWN:
        myInput->wParam = wParam;
        myInput->keyPressed(mySkyBox);
        //myInput->keyPressed(myCam);
        myInput->keys[wParam] = true;
        break;

    case WM_KEYUP:
        myInput->wParam = wParam;
        myInput->keys[wParam] = false;
        break;

    case WM_LBUTTONDOWN:
        //myInput->mouseEventDown(model, LOWORD(lParam), HIWORD(lParam));
        clickCount = clickCount % 10;

        b[clickCount].src.x = mdl3D->pos.x;
        b[clickCount].src.y = mdl3D->pos.y;
        b[clickCount].src.z = mdl3D->pos.z;

        b[clickCount].des.x = msX;
        b[clickCount].des.y = -msY;
        b[clickCount].des.z = msZ;

        b[clickCount].t = 0;
        b[clickCount].actionTrigger = b[clickCount].SHOOT;
        b[clickCount].isAlive = true;

        clickCount++;

        snds->playSound("sounds/untitled2.mp3");
        break;

    case WM_MOUSEMOVE:
        myInput->mouseMove(myCam, LOWORD(lParam), HIWORD(lParam));
        break;

    case WM_MOUSEWHEEL:
        myInput->mouseWheel(myModel, (double)GET_WHEEL_DELTA_WPARAM(wParam));
        break;
    }

    return 0;
}
