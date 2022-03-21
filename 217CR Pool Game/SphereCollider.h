#pragma once
#include "GameObject.h"

class SphereCollider
{
protected:
	vector3 SphereColliderPosition;
	vector3 SphereColliderColor;
	float radius = 1.0f;
public:
	int CollideCheck(SphereCollider); //Collision Check returns boolean depending if the Collision happened or not.
	SphereCollider(vector3 SphereColliderPosition, vector3 SphereColliderColor, float radius); // Constructor
	SphereCollider(); // deafault Constructor
	~SphereCollider(); // Destructor
	void Draw();
};