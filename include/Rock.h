#ifndef ROCK_H
#define ROCK_H

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <vector>
#include <time.h>
#include "shader.h"

#define X_SEGMENTS 60 // 增加细分以创建更多的面
#define Y_SEGMENTS 60
const GLfloat phi = 3.14159265358979323846f;

class Rock {
public:
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    std::vector<float> rockVertices;
    std::vector<unsigned int> rockIndices;
    float textureCoords[10000]; // 可能需要更多的纹理坐标空间
    int tc_size;
    glm::vec3 Color;
    unsigned int NBO;
    unsigned int TBO;

    Rock(float radius, glm::vec3 Color);
    void draw(Shader& shader_, glm::mat4& projection, glm::mat4& view, glm::mat4& model, unsigned int* texture);
    ~Rock();
};

#endif