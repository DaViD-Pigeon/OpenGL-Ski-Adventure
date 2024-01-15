#ifndef  LSYSTEM_H
#define LSYSTEM_H

#include <stack>

#include <glm/glm.hpp>
#include "shader.h"
#include "Grammar.h"
#include "cylinder.h"
#include "sphere.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace std;
const float Pi1 = 3.1415926;
/*
 *结构体名称：State
 *结构体功能：存储迭代过程的状态信息，包括位置、方向、长度、半径和层数
 */
struct State
{
	glm::vec3 pos;
	glm::vec3 dir;
	float length;
	float radius;
	int level;
};

/*
 *结构体名称：Trunk
 *结构体功能：存储树干的两端、半径、长度
 */
struct Trunk
{
	glm::vec3 start;
	glm::vec3 end;
	float radius;
	float length;
	Trunk() {
		start = end = glm::vec3(0.0f);
	}
};

/*
 *结构体名称：Leaf
 *结构体功能：存储叶子的两端和朝向
 */
struct Leaf
{
	glm::vec3 pos;
	glm::vec3 end;
	glm::vec3 dir;
};

/*
 *   类名称：LSystem
 *   类功能：调用Grammar语法类生成文法并将其“翻译”成一个三维立体的树
 */
class LSystem {
public:
	vector<Trunk> trunks;
	vector<Leaf> leafs;
	LSystem();
	~LSystem();
	void generateFractal(Shader& shader_, glm::mat4& projection, glm::mat4& view, glm::vec3& pos, unsigned int* texture1, unsigned int* texture2);
	double getRadiusFactor(){ return radiusFactor;}
	double getLengthFactor() { return lengthFactor; }
	double getLeafRadius() { return leafRadius; }

	int level;
	double dx, dy, dz;
	double leafRadius;
	double leafLength;
	double length, lengthFactor;
	double radius, radiusFactor;
	State curState;
	Grammar grammar;
	int numTrunks, numLeafs;
	string result;
	//void DrawTree(Shader& shader_, glm::mat4& projection, glm::mat4& view, unsigned int* texture);
};

glm::mat4 calculateRotationMatrix(const glm::vec3& originalVec, const glm::vec3& targetVec);

#endif
