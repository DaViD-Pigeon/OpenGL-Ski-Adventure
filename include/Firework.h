#ifndef __FIREWORK_H__
#define __FIREWORK_H__

#define GLEW_STATIC
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader.h"
#include <vector>

#define PARTICLE_NUM 2000
#define PARTICLE_SIZE 0.25
#define NOISE (0.5)
#define INIT_POS glm::vec3(0.0f, 0.0f, 0.0f)
#define INIT_COLOR glm::vec3(1.0f, 1.0f, 1.0f)

class Particle {
public:
    // 粒子的位置，颜色和速度
    glm::vec3 position, color, velocity;
    // 粒子的半径，形成时间，是否活跃
    float radius, birthTime;
    bool isActive;

    // 构造函数，允许通过参数设置初始位置、颜色和半径
    Particle(glm::vec3 initPosition = INIT_POS, glm::vec3 initColor = INIT_COLOR, float initRadius = PARTICLE_SIZE);
};

class Firework {
public:
    // 粒子流中的所有粒子
    Particle particles[PARTICLE_NUM];
    // 粒子流的位置，颜色和流动方向
    glm::vec3 position, color, flowDirection;
    // 粒子流的形成时间，持续时间，时间间隔，流动力度
    float birthTime, flowLastTime, deltaTime, flowForce;
    // 是否活跃，有效性标志
    bool isActive;
    int validity;
    // 存储粒子位置、半径、速度和形成时间的数组
    float positionRadiusVelocityTime[PARTICLE_NUM * 8];

    // 构造函数，通过参数设置初始位置、颜色、流动方向、流动力度和持续时间
    Firework(glm::vec3 initPosition, glm::vec3 initColor, glm::vec3 initFlowDirection, float initFlowForce, float initFlowLastTime);
    void update();
    // 绘制粒子流的方法，接收着色器和变换矩阵参数
    void drawFlow(Shader &shader_, glm::mat4 &projection, glm::mat4 &view, glm::mat4 &model);
};

#endif // __PARTICLE_H__
