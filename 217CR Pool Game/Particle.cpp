#include "Particle.h"

void Particle::Draw()
{
	glPushMatrix();
	glColor3f(color.x, color.y, color.z);
	glTranslatef(position.x, position.y, position.z);
	glutSolidSphere(0.5f, 10, 10);
	glPopMatrix();
}

void Particle::Update(float deltaTime)
{
}

Particle::Particle(float m, glm::vec3 pos, glm::vec3 col) : GameObject(pos, col)
{
	mass = m;
	velocity = glm::vec3(0, 0, 0);
	acceleration = glm::vec3(0, 0, 0);
	totalForce = glm::vec3(0, 0, 0);
	gravity = glm::vec3(0, 9.807, 0);
}

Particle::~Particle()
{
}

void Particle::CalculateForces()
{
	totalForce = glm::vec3(0, 0, 0); // Reset Force applied

	totalForce += gravity * mass; // Add Forces
}
