#pragma once
#include "GameObject.h"
// IN GAMEOBJECT glm::vec3 is defined as vector3 !

class RigidBody2D : public GameObject
{
private:
	float mass;
	vector3 linearAcceleration;
	vector3 linearVelocity;
	vector3 rigidbody2dPosition;
	vector3 linearForces;

	// Rotational Motion.
	float rotationalInertia; // -- In case 3D inertia must be a matrix.
	vector3 angularAcceleration;
	vector3 angularVelocity;
	float orientation;
	// Shape Information ?? // circle, triangle, box
	vector3 angularForces;

	// Rectangle Information (HardCode)
	float width = 1;
	float length = 1;

public:
	// ! MAKE RETURNS VALUES OF POSITION AVAILABLE TO BE CALLED !
	
	void Draw();
	void Update(float);
	RigidBody2D(float mas, vector3 pos, vector3 col);
	~RigidBody2D();

	// Force Calculation Functions


	// Return position values / Radius of objects rigidbody functions.

};