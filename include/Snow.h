#ifndef __SNOW_H__
#define __SNOW_H__

#define GLEW_STATIC
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include <vector>

#define SNOW_NUM 5000
#define SNOW_SIZE 0.08
#define SNOW_NOISE (0.5)
#define SNOW_COLOR glm::vec3(0.95f, 0.95f, 0.95f)

class SnowParticle {
public:
    // 粒子的位置，颜色和速度
    glm::vec3 position, color, velocity;
    // 粒子的半径，形成时间，是否活跃
    float radius, birthTime;
    bool isActive;
    // 构造函数，允许通过参数设置初始位置、颜色和半径
    SnowParticle(glm::vec3 initPosition = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 initColor = SNOW_COLOR, float initRadius = SNOW_SIZE);
};

class SnowStorm {
public:
    // 粒子流中的所有粒子
    SnowParticle particles[SNOW_NUM];
    // 粒子流的位置，颜色和流动方向
    glm::vec3 color, flowDirection;
    glm::vec3 position;
    // 粒子流的形成时间，持续时间，时间间隔，流动力度
    float birthTime, flowLastTime, deltaTime, flowForce;
    // 是否活跃，有效性标志
    bool isActive;
    int validity;
    // 存储粒子位置、半径、速度和形成时间的数组
    float positionRadiusVelocityTime[SNOW_NUM * 8];

    // 构造函数，通过参数设置初始位置、颜色、流动方向、流动力度和持续时间
    SnowStorm(glm::vec3 initPosition, glm::vec3 initColor, glm::vec3 initFlowDirection, float initFlowForce, float initFlowLastTime);
    void updatePosition(float z);
    void updateBirthTime();
    void update(float z);
    void drawFlow(Shader &shader_, glm::mat4 &projection, glm::mat4 &view, glm::mat4 &model);
};


#endif // __SNOW_H__