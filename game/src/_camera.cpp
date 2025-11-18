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
    eye.x = eye.y = 0;
    eye.z = 10;

    des.x = des.y = des.z = 0;

    up.x = up.z = 0;
    up.y = 1;

    step = 0.5;

    distance = sqrt(pow((eye.x-des.x),2) + pow((eye.y-des.y),2) + pow((eye.z-des.z),2));

    rotAngle.x = rotAngle.y = 0;

    verticalVel = 0.0f;
    isJumping = false;
    gravity = -40.0f;   // stronger than real gravity for game feel
    groundY = eye.y;

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
    // Clamp vertical rotation to prevent flipping
    if (rotAngle.y > 89.0f) rotAngle.y = 89.0f;
    if (rotAngle.y < -89.0f) rotAngle.y = -89.0f;

    // Convert angles to radians
    float yaw = rotAngle.x * PI / 180.0f;   // left-right
    float pitch = rotAngle.y * PI / 180.0f; // up-down

    // Calculate direction vector
    des.x = eye.x + cos(pitch) * sin(yaw);
    des.y = eye.y + sin(pitch);
    des.z = eye.z + cos(pitch) * cos(yaw);
}


void _camera::rotateUp()
{

}

void _camera::camMoveFdBd(float dir)
{
    // Forward vector (ignore Y)
    vec3 forward = des - eye;
    forward.y = 0;
    float len = sqrt(forward.x*forward.x + forward.z*forward.z);
    if (len != 0)
    {
        forward.x /= len;
        forward.z /= len;
    }

    // Move in the correct direction: W = +dir
    eye.x += forward.x * dir;
    eye.z += forward.z * dir;
    des.x += forward.x * dir;
    des.z += forward.z * dir;
}

void _camera::camMoveLtRt(float dir)
{
    // Forward vector (ignore Y)
    vec3 forward = des - eye;
    forward.y = 0;
    float len = sqrt(forward.x*forward.x + forward.z*forward.z);
    if (len != 0)
    {
        forward.x /= len;
        forward.z /= len;
    }

    // Right vector (perpendicular in XZ plane)
    vec3 right;
    right.x = forward.z;
    right.y = 0;
    right.z = -forward.x;

    // Move in the correct direction: D = +dir, A = -dir
    eye.x += right.x * dir;
    eye.z += right.z * dir;
    des.x += right.x * dir;
    des.z += right.z * dir;
}



void _camera::setUpCamera()
{
    gluLookAt(eye.x, eye.y, eye.z, des.x, des.y, des.z, up.x, up.y, up.z);
}

void _camera::jump()
{
    if (!isJumping) {
        verticalVel = 15.0f;   // jump strength
        isJumping = true;
    }
}

void _camera::updateVertical(float deltaTime)
{
    if (isJumping) {
        verticalVel += gravity * deltaTime;    // gravity
        eye.y += verticalVel * deltaTime;
        des.y += verticalVel * deltaTime;

        if (eye.y <= groundY) {               // landed
            eye.y = groundY;
            des.y = groundY;
            verticalVel = 0.0f;
            isJumping = false;
        }
    }
}
