#pragma once
#include "GameObject.h"

class Sphere : public GameObject
{
public:
	Sphere();                                       // Default Constructor without GameObject
	Sphere(float mas, glm::vec3 pos, glm::vec3 col);// Constructor with GameObject
	~Sphere();									    // Destructor
	void Draw();									// Object Drawn Details
	void Update(float);								// Object Updates Taking in deltaTime
};