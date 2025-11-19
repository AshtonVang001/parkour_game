#include "_Menu.h"
#include "gltfModel.h"
#include "_gltfLoader.h"
#include <iostream>

_Menu::_Menu()
{
    myTime = new _timer();
    clickCount = 0;

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

_Menu::~_Menu()
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

void _Menu::reSizeScene(int width, int height)
{
    float aspectRatio = (float)width / (float)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspectRatio, 0.1f, 1000.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    this->width = width;
    this->height = height;
}

void _Menu::initGL()
{
    // ... same as _Scene::initGL ...
}

void _Menu::updateScene()
{
    // ... same as _Scene::updateScene ...
}

void _Menu::drawScene()
{
    // ... same as _Scene::drawScene ...
}

int _Menu::winMsg(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    // ... same as _Scene::winMsg ...
}
