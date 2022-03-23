#pragma once
#include "GameObject.h"
#include "SphereCollider.h"

class Sphere : public GameObject, public SphereCollider
{
private:
	
protected:
	float radius = 1.0f;
	bool UserInput = false;
	void CheckInput(float deltaTime);
public:
	Sphere();														  // Default Constructor without GameObject
	Sphere(float mas, vector3 pos, vector3 col, bool KeyboardUse);    // Constructor with GameObject
	~Sphere();														  // Destructor
	void Draw();													  // Object Drawn Details
	void Update(float);												  // Object Updates Taking in deltaTime
};