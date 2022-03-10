#pragma once
#include "GameObject.h"

class Particle : public GameObject
{
private:
	vector3 acceleration;
	vector3 velocity;
	// Position From GameObject
	vector3 totalForce;
	vector3 gravity;
	vector3 futurePosition;
	vector3 wind;
	vector3 keyboardForce;
	float r = 0.9f;

public:
	void Draw();
	void Update(float);
	Particle(float m, vector3 pos, vector3 col);
	~Particle();
	void CalculateForces();
};