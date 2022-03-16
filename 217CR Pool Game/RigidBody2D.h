#pragma once
#include "GameObject.h"
// IN GAMEOBJECT glm::vec3 is defined as vector3 !

class RigidBody2D : public GameObject
{
private:
	/* Linear Motion*/
	// Mass / Position from GameObject
	vector3 LinearAcceleration = vector3(0,0,0);
	vector3 LinearVelocity = vector3(0, 0, 0);
	vector3 FuturePosition = vector3(0, 0, 0);
	vector3 LinearTotalForce = vector3(0, 0, 0);
	vector3 gravity = vector3(0, -0.5f, 0);

	/* Rotational Motion.*/
	float AngularInertia = 0.0;
	float orientation = 0.0;
	vector3 AngularAcceleration = vector3(0, 0, 0);
	vector3 AngularVelocity = vector3(0, 0, 0);
	vector3 AngularTorque = vector3(0, 0, 0);
	vector3 GravityPosition = vector3(0, 0, 0);

	vector3 AngularForceAffectingObject = vector3(2, 0, 0);
	vector3 AngularForceAffectingObjectPosition = vector3(1, 1 , 0);

	// Shape Information ? // circle, triangle, box

	// Rectangle Information (HardCode)
	float width = 0;
	float length = 1;
	float height = 1;

	/* CALCULATION */
	float SqrNumber(float Number);
	float FindInertia(float Length, float Height);
	void CalculateForces(); // Find Forces Applied to Object
	void CalculateVelocity(float deltaTime);
	void SetDisplacements(float deltaTime);
	float radiansToDegrees(float value);

public:
	// ! MAKE RETURNS VALUES OF POSITION AVAILABLE TO BE CALLED !
	void Draw();
	void Update(float);
	RigidBody2D(float mas, vector3 pos, vector3 col);
	~RigidBody2D();
	// Return position values / Radius of objects rigidbody functions.
};