#pragma once
#include <vector>
#include <GL/glew.h>
#include <GL/gl.h>
#include <SOIL2.h>


class GltfModel {
public:
    std::vector<float> vertices;
    std::vector<float> normals;
    std::vector<float> uvs;
    std::vector<unsigned int> indices;

    std::vector<float> texcoords;
    GLuint tbo = 0;
    GLuint textureID = 0;


    GLuint vbo = 0;
    GLuint ebo = 0;
    GLuint vao = 0;
    GLuint nbo = 0;


    void uploadToGPU();
    void draw();
};
