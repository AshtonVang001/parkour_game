#include "_camera.h"

_camera::_camera()
{
    //ctor
}

_camera::~_camera()
{
    //dtor
}

void _camera::camInit()
{
    eye = {0, 0, 3};
    des = {0, 0, 0};
    up =  {0, 1, 0};

    yaw = -90.0f;
    pitch = 0.0f;
    sensitivity = 0.15f;


    step = 0.1f;
}

void _camera::camReset()
{
    eye.x = eye.y = 0;
    eye.z = 10;

    des.x = des.y = des.z = 0;

    up.x = up.z = 0;
    up.y = 1;

    step = 0.5;

    distance = sqrt(pow((eye.x-des.x),2) + pow((eye.y-des.y),2) + pow((eye.z-des.z),2));

    rotAngle.x = rotAngle.y = 0;
}

void _camera::rotateXY()
{
    eye.x = des.x + distance * cos(rotAngle.y * PI/180.0) * sin(rotAngle.x * PI/180.0);
    eye.y = des.y + distance * sin(rotAngle.y * PI/180.0);
    eye.z = des.z + distance * cos(rotAngle.y * PI/180.0) * cos(rotAngle.x * PI/180.0);
}

void _camera::rotateUp()
{

}

void _camera::updateRotation()
{
    float radYaw = yaw * PI / 180.0f;
    float radPitch = pitch * PI / 180.0f;

    des.x = eye.x + cos(radYaw) * cos(radPitch);
    des.y = eye.y + sin(radPitch);
    des.z = eye.z + sin(radYaw) * cos(radPitch);
}


void _camera::moveForward(float amt)
{
    eye.x += amt * cos(yaw * PI / 180.0f);
    eye.z += amt * sin(yaw * PI / 180.0f);
}

void _camera::moveRight(float amt)
{
    eye.x += amt * cos((yaw + 90) * PI / 180.0f);
    eye.z += amt * sin((yaw + 90) * PI / 180.0f);
}

void _camera::addMouseDelta(int dx, int dy)
{
    float sensitivity = 0.1f;
    yaw   += dx * sensitivity;
    pitch -= dy * sensitivity;

    if(pitch > 89) pitch = 89;
    if(pitch < -89) pitch = -89;

    updateRotation();
}


void _camera::setUpCamera()
{
    gluLookAt(eye.x, eye.y, eye.z, des.x, des.y, des.z, up.x, up.y, up.z);
}
