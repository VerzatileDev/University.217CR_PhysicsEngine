#pragma once
#include "GameObject.h"

class SphereCollider
{
protected:
	vector3 SphereColliderPosition;
	vector3 SphereColliderColor;
	float radius = 1.0f; // Initial Value
public:
	static bool CollisionCheck(glm::vec3 position, glm::vec3 position2, float radius1, float radius2); //Collision Check returns boolean depending if the Collision happened or not.
	SphereCollider(vector3 SphereColliderPos, vector3 SphereColliderCol, float rad); // Constructor
	SphereCollider(); // deafault Constructor
	~SphereCollider(); // Destructor
	void Draw();
};