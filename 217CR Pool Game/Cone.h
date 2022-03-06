#pragma once
#include "GameObject.h"

class Cone : public GameObject
{
public:
	Cone();
	Cone(float mas, vector3 pos, vector3 col);
	~Cone();
	void Draw();
};