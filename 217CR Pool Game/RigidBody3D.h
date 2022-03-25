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

	glm::mat4 Angularinertia = glm::mat4(1.0f);
	float SqrNumber(float Number);

protected:
	float radius = 1.0f;
	float orientation = 0.0;
	int UsingRigidBody3DType = 3; // 3 Means No RigidBody Type is used !!
public:
	void Draw();															// Object Initilization and set of details
	void Update(float);														// Object Updates Taking in deltaTime
	RigidBody3D();															// Default Constructor Use when Nessecary to add to Other Objects..
	RigidBody3D(float mas, vector3 pos, vector3 col, int UsingRigidBody3D);	// Constructor With GameObject
	~RigidBody3D();															// Destructor

	glm::mat4 GetInertia(float Length, float Height, float width);
	void CalculateForces();
	// Return Values functions
};