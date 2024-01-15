# ifndef __GROUND_SURFACE_H__
# define __GROUND_SURFACE_H__
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <vector>
#include "shader.h"

class GroundSurface{
public:
    unsigned int groundVAO;
    unsigned int groundVBO;
    unsigned int groundNBO;
    unsigned int groundEBO;
    unsigned int groundTBO;
    std::vector<float>groundVertices;
    std::vector<unsigned int>groundIndices;
    std::vector<float>groundNormals;
    std::vector<float>groundTextureCoords;

    GroundSurface(float start_x, float start_z, float end_x, float end_z, float y);
    void draw(Shader &shader_ ,glm::mat4 & projection, glm::mat4 &view, glm::mat4 &model,unsigned int texture);
    ~GroundSurface();

};


# endif