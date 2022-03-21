#pragma once
#include "GameObject.h"
#include "SphereCollider.h"

class Sphere : public GameObject, public SphereCollider
{
private:
	void CheckInput(float deltaTime);
protected:
	float radius = 1.0f;
	bool UserInput;
public:
	Sphere();														  // Default Constructor without GameObject
	Sphere(float mas, vector3 pos, vector3 col, bool KeyboardUse);    // Constructor with GameObject
	~Sphere();														  // Destructor
	void Draw();													  // Object Drawn Details
	void Update(float);												  // Object Updates Taking in deltaTime
};