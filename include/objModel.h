#ifndef _MODEL
#define _MODEL
#define GLEW_STATIC
#include <vector>
#include <glm/glm.hpp>
// #include <glad/glad.h>
#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Shader.h"
class Model {
private:
    /* data */
    
public:
    unsigned int vertexBuffer;
    unsigned int VAO;

    unsigned int normalBuffer;
    std::vector< glm::vec3 > vertex;
    std::vector< glm::vec2 > texture;
    std::vector< glm::vec3 > norm;
    Model(const char * path);
    ~Model();
    void draw(Shader &shader_ ,glm::mat4 & projection, glm::mat4 &view, glm::mat4 &model);
    void use();
    int get_vertex_num() { return vertex.size(); }
};
#endif