#ifndef _CAMERA_H
#define _CAMERA_H

#include <_common.h>
#include <_collisionCheck.h>
#include <_gltfLoader.h>
#include <gltfModel.h>

class gltfModel;
class _collisionCheck;

class _camera
{
    public:
        _camera();
        virtual ~_camera();

        vec3 eye;                   //eye position
        vec3 des;                   //where you are looking at
        vec3 up;                    //camera head orientation

        float step;                 //camera speed
        vec3 rotAngle;              //rotation of camera
        float distance;             //eye to source

        enum {FORWARD, BACKWARD, LEFT, RIGHT};

        float gravity;  // gravity strength
        float groundOffset;

        float yaw, pitch;
        float sensitivity;

        vec3 velocity;
        vec3 pos;

        void camInit();             //initialize camera
        void camReset();            //reset camera
        void update(float deltaTime, _collisionCheck* colCheck, gltfModel* groundMesh);
        void updateRotation();

        void addMouseDelta(int dx, int dy);

        void rotateXY();            //rotate XY direction
        void rotateUp();            //rotate up & down

        void moveForward(float amt);  //move camera forward & backward
        void moveRight(float amt);  //move camera left & right

        void setUpCamera();         //set camera using glulookat

    protected:

    private:
};

#endif // _CAMERA_H
