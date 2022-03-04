#pragma once // allow C preprocessor to include a header file when it is needed and to ignore an #include directive otherwise
#include "GameObject.h"

class Quad2D : public GameObject // Libraries From GameObject
{
public:
	Quad2D(); // Default constructor
	Quad2D(glm::vec3 pos, glm::vec3 col); // Default constructor
	~Quad2D();
	void Draw();
	void Update(float);
};