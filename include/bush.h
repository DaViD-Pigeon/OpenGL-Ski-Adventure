#ifndef bush_H
#define bush_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <vector>
#include <time.h>
#include "shader.h"

const GLfloat pi = 3.14159265358979323846f;
#define X_SEGMENTS 30
#define Y_SEGMENTS 30

class bush {
public:
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    std::vector<float> bushVertices;
    std::vector<unsigned int> bushIndices;
    float textureCoords[10000];
    int tc_size;
    glm::vec3 Color;
    unsigned int NBO;
    unsigned int TBO;

    bush(float baseRadius, glm::vec3 Color);
    void draw(Shader& shader_, glm::mat4& projection, glm::mat4& view, glm::mat4& model, unsigned int* texture);
    ~bush();
};

#endif