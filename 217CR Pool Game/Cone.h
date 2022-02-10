#pragma once
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>

class Cone
{
public:
	Cone();
	Cone(glm::vec3 pos, glm::vec3 col);
	~Cone();
	
	void Draw();

private:
	glm::vec3 position;
	glm::vec3 color; /* Color codes https://pemavirtualhub.wordpress.com/2016/06/20/opengl-color-codes/ */
};