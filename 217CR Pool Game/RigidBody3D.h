#pragma once
#include "GameObject.h"
#include "Color_Utils.h"


class RigidBody3D : public GameObject
{
private:
	// Varlet Integration 

	// Position from GameObject
	// Mass from gameObject
	vector3 VarletVelocity = vector3(0.0, 1.0, 0.0);
	vector3 VarletAcceleration = vector3(0.0, 0.0, 0.0);
	vector3 NewAcceleration = vector3(0.0, 0.0, 0.0);
	vector3 GravAcceleration = vector3(0.0, -9.81, 0.0);
	float Drag = 0.1f;
	// vector3 DragForce = vector3(0.0, 0.0, 0.0); 
	// vector3 GravityAcceleration = vector3(0.0, 0.0, 0.0);

protected:
	float radius = 1.0f;
	float orientation = 0.0;
public:
	void Draw();										// Object Initilization and set of details
	void Update(float);									// Object Updates Taking in deltaTime
	RigidBody3D();										// Default Constructor Use when Nessecary to add to Other Objects..
	RigidBody3D(float mas, vector3 pos, vector3 col);	// Constructor With GameObject
	~RigidBody3D();										// Destructor

	void CalculateForces();
	// Return Values functions
};