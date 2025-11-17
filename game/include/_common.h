#ifndef _COMMON_H
#define _COMMON_H

#include <GL/glew.h>

#include <windows.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fstream>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SOIL2.h>

#define PI 3.14159265358979

using namespace std;

typedef struct{

    float x;
    float y;

} vec2;

typedef struct{

    float x;
    float y;
    float z;

} vec3;

typedef struct{

    float r;
    float g;
    float b;

} col3;

typedef struct{

    float r;
    float g;
    float b;
    float a;

} col4;


#endif // _COMMON_H
