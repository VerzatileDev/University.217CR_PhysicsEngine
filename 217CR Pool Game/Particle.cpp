#include "Particle.h"
#include <iostream>

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
	//Give us the Forces applied to an object
	CalculateForces();

	//Calculate the new position for the object after force effects.
	/*
		Vt + dt = Vt +(at) + dt;  // dt = deltaTime, Vt = Velocity at time, (Vt +dt) -> Future Velocity, at = acceleration at the time.
		St + dt = St + (Vt) * dt; // St = Position (St +dt) -> Future position, St +(Vt) *dt  -> Current Position + (velocity of the object * deltaTime)

		deltaTime -> Time taken From previous frame to next.
	*/
	velocity = velocity + (acceleration)*deltaTime;
	futurePosition = position + (velocity)*deltaTime;
	position = futurePosition;

	/* Add this For Keyboard Use */
	velocity *= pow(0.5, deltaTime); // damping
}

Particle::Particle(float m, glm::vec3 pos, glm::vec3 col) : GameObject(pos, col)
{
	mass = m;                           // Weight of the Object which is relative to the world.
	velocity = glm::vec3(0, 0, 0);      // Change of an Objects direction in regards to Time.
	acceleration = glm::vec3(0, 0, 0);  // Throttle on the object (The amount an object accelerates in its worldspace)
	totalForce = glm::vec3(0, 0, 0);    // All the forces effecting the object.
	gravity = glm::vec3(0, -9.807, 0);  // Earth's Gravity (-) downwards Pull.
	wind = glm::vec3(-2, 0, 0);         // Semi directional wind Force.
	futurePosition = glm::vec3(0, 0, 0);// Future position of the object in the world map.
}

Particle::~Particle()
{
}

void Particle::CalculateForces()
{
	totalForce = glm::vec3(0, 0, 0); // Reset Forces
	totalForce += gravity * mass;
	totalForce += wind;
	acceleration = totalForce / mass;

	// Developer Comments "  
	//1. In case the Mass where to change for example some type of impact is the reason to Use *mass and then  /m to get the difference.
	//2. Forces affecting the Object * It is best that each new force is applied seperatly *
}