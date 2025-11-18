#ifndef _MENUS_H
#define _MENUS_H

#include <_textureLoader.h>


class _menus
{
    public:
        _menus();
        virtual ~_menus();

        _textureLoader *myTex = new _textureLoader();


        void initImage(char*);
        void menuDraw(float,float);
        void helpDraw(float, float);
        void popUpDraw(float, float, char*);


        void HUD(char*, double);

        float  screenWidth, screenHeight;

        float texCrop = 1.0;
        float verCrop = 1.0;
        float xMax = 1.0;
        float xMin = 0.0;
        float yMax = 1.0;
        float yMin = 0.0;

    protected:

    private:
};

#endif // _MENUS_H
