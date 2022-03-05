#pragma once
#include "GameObject.h"

class Sphere : public GameObject
{
public:
	Sphere(); // Default constructor
	Sphere(float mas, glm::vec3 pos, glm::vec3 col); // Specified Constructor Initialz of the Sphere.
	~Sphere();
	void Draw();
};