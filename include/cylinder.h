#ifndef CYLINDER_H
#define CYLINDER_H

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <vector>
#include "shader.h"

#define X_SEGMENTS 30
#define Y_SEGMENTS 1  // 对于圆柱体，Y_SEGMENTS可以是1，因为我们不需要在Y方向上细分

const GLfloat Pi = 3.1415926535897932384f;

class Cylinder {
public:
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    std::vector<float> cylinderVertices;
    std::vector<float> cylinderNormals;
    std::vector<unsigned int> cylinderIndices;
    float textureCoords[10000];
    int tc_size;
    glm::vec3 Color;
    unsigned int NBO;
    unsigned int TBO;

    //Cylinder(float radius, float height, glm::vec3 Color);
    Cylinder(glm::vec3 start, glm::vec3 end, float radius, glm::vec3 Color);
    void draw(Shader& shader_, glm::mat4& projection, glm::mat4& view, glm::mat4& model, unsigned int* texture);
    ~Cylinder();
};

#endif