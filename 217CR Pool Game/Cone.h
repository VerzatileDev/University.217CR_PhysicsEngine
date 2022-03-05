#pragma once
#include "GameObject.h"

class Cone : public GameObject
{
public:
	Cone();
	Cone(float mas, glm::vec3 pos, glm::vec3 col);
	~Cone();
	void Draw();
};