#pragma once
#include "GameObject.h"
#include "SphereCollider.h"

class Sphere : public GameObject, public SphereCollider
{
private:
	
protected:
	
	bool UserInput = false;
	bool ShowDetails = false;
	int RigidBodyUsed = 0;
	void CheckInput(float deltaTime);
public:
	Sphere();																										  // Default Constructor without GameObject
	Sphere(float mas, vector3 pos, vector3 col, float rad, bool KeyboardUse, int UsingRigidBody3D, bool ShowingDetailsOnObject); // Constructor with GameObject
	~Sphere();																										  // Destructor
	void Draw();																								      // Object Drawn Details
	void Update(float);																								  // Object Updates Taking in deltaTime
	float radius = 1.0f; // Default Radius
};