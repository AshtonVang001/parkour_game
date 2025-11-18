#include "_menus.h"
#include <_textureloader.h>
#include <windows.h>
#include <gl/gl.h>

_menus::_menus()
{
    screenWidth = (float)GetSystemMetrics(SM_CXSCREEN);
    screenHeight = (float)GetSystemMetrics(SM_CYSCREEN);

    if (!myTex) {
        try { myTex = new _textureLoader(); } catch (...) { myTex = nullptr; }
    }
}

_menus::~_menus()
{
    if (myTex) { delete myTex; myTex = nullptr; }
}

void _menus::initImage(char* fileName)
{
    if (!myTex) {
        try { myTex = new _textureLoader(); } catch (...) { myTex = nullptr; }
    }
    if (myTex) myTex->loadTexture(fileName);
}

void _menus::menuDraw(float width, float height)
{
    if (!myTex) return;

    myTex->bindTexture();

    glBegin(GL_QUADS);    // Render menu rectangle (WHITE)
        glTexCoord2f(xMin, yMin); glVertex2f(0.0f, height);
        glTexCoord2f(xMax, yMin); glVertex2f(width, height);
        glTexCoord2f(xMax, yMax); glVertex2f(width, 0.0f);
        glTexCoord2f(xMin, yMax); glVertex2f(0.0f, 0.0f);
    glEnd();
}

void _menus::popUpDraw(float width, float height, char* fileName)
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0, width, 0.0, height, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    if (!myTex) {
        try { myTex = new _textureLoader(); } catch (...) { myTex = nullptr; }
    }
    if (myTex) {
        myTex->loadTexture(fileName);
        myTex->bindTexture();

        glBegin(GL_QUADS);    // Render popup rectangle
            glTexCoord2f(xMin, yMax); glVertex2f(width / 4.0f, height / 4.0f);          // Bottom-left
            glTexCoord2f(xMax, yMax); glVertex2f(3.0f * width / 4.0f, height / 4.0f);    // Bottom-right
            glTexCoord2f(xMax, yMin); glVertex2f(3.0f * width / 4.0f, 3.0f * height / 4.0f);  // Top-right
            glTexCoord2f(xMin, yMin); glVertex2f(width / 4.0f, 3.0f * height / 4.0f);      // Top-left
        glEnd();
    }

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

void _menus::HUD(char* fileName, double hitCtr)
{
    if (hitCtr == 0.0)
    {
        texCrop = 1.0f;
        verCrop = 1.0f;
    }
    else if (hitCtr == 1.0)
    {
        texCrop = 1.5f;
        verCrop = 1.38f;
    }
    else if (hitCtr == 2.0)
    {
        texCrop = 3.0f;
        verCrop = 2.22f;
    }

    if (!myTex) {
        try { myTex = new _textureLoader(); } catch (...) { myTex = nullptr; }
    }
    if (!myTex) return;

    myTex->loadTexture(fileName);
    myTex->bindTexture();

    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f); glVertex2f(0.025f, 0.92f);
        glTexCoord2f(1.0f / texCrop, 1.0f); glVertex2f(0.15f / verCrop, 0.92f);
        glTexCoord2f(1.0f / texCrop, 0.0f); glVertex2f(0.15f / verCrop, 0.975f);
        glTexCoord2f(0.0f, 0.0f); glVertex2f(0.025f, 0.975f);
    glEnd();
}
