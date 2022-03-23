#pragma once
#include "GameObject.h"
#include "Color_Utils.h"
#include "Sphere.h"


class RigidBody3D : public GameObject, public Sphere
{
private:
	vector3 currentcolor;
public:
	void Draw();										// Object Initilization and set of details
	void Update(float);									// Object Updates Taking in deltaTime
	RigidBody3D();										// Default Constructor Use when Nessecary to add to Other Objects..
	RigidBody3D(float mas, vector3 pos, vector3 col);	// Constructor With GameObject
	~RigidBody3D();										// Destructor

	// Return Values functions
};