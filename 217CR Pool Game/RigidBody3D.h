#pragma once
#include "GameObject.h"

class RigidBody3D : public GameObject
{
private:


public:
	void Draw();
	void Update(float);
	RigidBody3D(float mas, vector3 pos, vector3 col);
	~RigidBody3D();

	// Return Values functions
};