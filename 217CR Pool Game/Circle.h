#pragma once
#include "GameObject.h"

class Circle : public GameObject
{
public:
	void Draw();
	Circle();
	Circle(float mas, vector3 pos, vector3 col);
	~Circle();
};