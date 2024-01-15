#ifndef __PLAYER_H__
#define __PLAYER_H__

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
class Player{
public:
    glm::vec3 Position;
    glm::vec3 Front;
    float Speed;
    Player();
};
#endif // 
