#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Color_Utils.h" // Defines Usable color3f / color4f

class Point
{
protected:
	float size = 5.0f;
	glm::vec3 pointColor;
	glm::vec3 pointLocation;
public:
	void Draw();
	void Update(float);
	Point();
	~Point();
};