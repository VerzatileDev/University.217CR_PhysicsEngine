#include "RigidBody3D.h"

void RigidBody3D::Draw()
{
	glPushMatrix();																		  // Defines that new element is being used
	glTranslatef(GameObject::position.x, GameObject::position.y, GameObject::position.z); // Location
	glRotatef(orientation, 1, 0, 0);
	glColor3f(GameObject::color.x, GameObject::color.y, GameObject::color.z);             // RGB ( Red,BLue, Green)
	glutSolidSphere(radius, 30, 30);													  // Radius /slices /stacks
	glPopMatrix();																		  // Pops the current matrix stack, replacing the current matrix with one below it on the stack..

}

void RigidBody3D::Update(float deltaTime)
{
	// For 2D basis https://www.gamedev.net/tutorials/programming/math-and-physics/a-verlet-based-approach-for-2d-game-physics-r2714/

	// Resource for Velocity Varlet Integration for 3D basis.
	// https://resources.saylor.org/wwwresources/archived/site/wp-content/uploads/2011/06/MA221-6.1.pdf //
	/*    Velocity Varlet       */
	// Half Step Velocity		1)
	// Calcualte New Position   2)
	// Derive Acceleration      3)
	// newVelocity = Half Step Velocity + newAcceleration Recived from 3)
	/* Where Acceleration and Velocity is used for the next run.*/
	



	// newPosition = oldPosition + oldVelocity * DeltaTime + 0.5 <--"(1/2)" * oldacceleration * deltaTime""2 // FutureTime "Approximate"
	vector3 newPosition = GameObject::position + VarletVelocity * deltaTime + 0.5f * VarletAcceleration * deltaTime * deltaTime;
	
	// dragForce - Where we calculate the force against the acceleration or per say Position Change of the Object.
	// dragAcceleration = force / mass   // a = f/m
	// newAcceleration = GravityAcceleration - dragAcceleration
	CalculateForces();

	// newVelocity = oldvelocity + 0.5 * oldAcceleration + newAcceleration * Time;
	vector3 newVelocity = VarletVelocity + 0.5f * (VarletAcceleration + NewAcceleration) * deltaTime;

	// Set new Calculations to old values;
	VarletAcceleration = NewAcceleration;
	VarletVelocity = newVelocity;

	// Set The new Profound Position = furtureposition;
	GameObject::position = newPosition;

}

RigidBody3D::RigidBody3D()
{}

RigidBody3D::RigidBody3D(float mas, vector3 pos, vector3 col) : GameObject(mas, pos, col)
{
	
}

RigidBody3D::~RigidBody3D()
{}

void RigidBody3D::CalculateForces()
{
	// https://wright.nasa.gov/airplane/drageq.html <-- Drag Force Reference.
	// DragForce = 1/2 * (Density of Fluid) * (Speed relative to the Fluid) * (Cross Sectional Areas) * (drag coefficient)
	// This is simplified version avoiding the use of cross Section and Coefficient
	vector3 DragForce = 0.50f * Drag * (VarletVelocity * VarletVelocity) * 0.47f; // <-- Drag Coefficient of a Sphere.
	/* Calculate Acceleration based on newtons second law*/
	vector3 DragAcceleration = DragForce / mass; // a = f/m
	NewAcceleration = GravAcceleration - DragAcceleration;
}