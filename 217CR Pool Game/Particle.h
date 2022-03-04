#pragma once
#include "GameObject.h"

class Particle : public GameObject
{
private:
	float mass;

	glm::vec3 acceleration;
	glm::vec3 velocity;
	// Position From GameObject
	glm::vec3 totalForce;
	glm::vec3 gravity;
	glm::vec3 futurePosition;
	glm::vec3 wind;

public:
	void Draw();
	void Update(float);
	Particle(float m, glm::vec3 pos, glm::vec3 col);
	~Particle();
	void CalculateForces();
};