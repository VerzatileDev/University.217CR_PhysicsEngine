#pragma once
#include "GameObject.h"
#include "Point.h"

class Particle : public GameObject
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
	
	// Calculation
	void CheckForKeyboard(float deltaTime);
	void CalculateForces();

protected:
	bool UserInput = false;
	bool ShowDetails = false;
	//float radius = 0.3f;                          // Radius of the Particle " Hard Code "


public:
	void Draw();
	void Update(float);
	Particle();
	Particle(float m, vector3 pos, vector3 col, float rad, bool KeyboardUse,bool ShowingDetailsOnObject);
	~Particle();
};