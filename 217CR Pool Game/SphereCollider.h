#pragma once
#include "GameObject.h"

class SphereCollider : GameObject
{
private:
	float radius = 1.0;
	// position from gameObject  And is same as the initial Sphere.

public:
	int CollideCheck(SphereCollider); //Collision Check returns boolean depending if the Collision happened or not.
	SphereCollider(float mas, vector3 pos, vector3 col); // Constructor
	~SphereCollider(); // Destructor

	void Draw();

};