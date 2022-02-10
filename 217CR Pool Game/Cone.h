#pragma once
#include "GameObject.h"

class Cone : public GameObject
{
public:
	Cone();
	Cone(glm::vec3 pos, glm::vec3 col);
	~Cone();
	void Draw();
};