#include "RigidBody2D.h"

void RigidBody2D::Draw()
{
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glRotatef(orientation, 0, 0, 1); //"angle,x,y,z (define as 0 or 1 ) 0 = means not affected on axis.
	glColor3f(color.x,color.y,color.z);

	glBegin(GL_QUADS);
	glVertex3f(-length, height, width); //top left
	glVertex3f(length, height, width); //top right
	glVertex3f(length, -height, width); //bottom right
	glVertex3f(-length, -height, width); //bottom left
	glEnd();

	// Displays A Point on the Object making it easier to see rotation.
	glPointSize(5.0f);
	glColor3f(1.f, 0.f, 0.f);
	glBegin(GL_POINTS);
	glVertex3f(1, 0, 0); // Location of the Point relative to the object Position
	glEnd();
	glPopMatrix();

	// Display Information here
	GameObject::renderBitmapString(position.x - length, position.y, position.z, "  Position.x " + std::to_string(position.x));
	GameObject::renderBitmapString(position.x - length, position.y - 0.3, position.z, "  Position.y " + std::to_string(position.y));
	GameObject::renderBitmapString(position.x - length, position.y - 0.6, position.z, "  Position.z " + std::to_string(position.z));
	GameObject::renderBitmapString(position.x - length, position.y - 0.9, position.z, "  AngularVelocity.x " + std::to_string(AngularVelocity.x));
	GameObject::renderBitmapString(position.x - length, position.y - 1.2, position.z, "  orientation " + std::to_string(orientation));

}

void RigidBody2D::Update(float deltaTime)
{
	CalculateForces();  // Linear (Euler method of calculation to find new position)
	CalculateVelocity(deltaTime);
	SetDisplacements(deltaTime);


}

RigidBody2D::RigidBody2D(float mas, vector3 pos, vector3 col) : GameObject(mas, pos, col)
{
	// Kilogram Force meter    Kg m squared = 9.8067 Newton Meters
	// -- Currently Only Set to find inertia of a Rectangle -- //
	FindInertia(length, height); //std::cout << AngularInertia << std::endl; //Debug
}

RigidBody2D::~RigidBody2D()
{}

void RigidBody2D::CalculateForces()
{
	//Reset Forces And Moments
	LinearTotalForce = vector3(0, 0, 0);
	AngularTorque = vector3(0, 0, 0);


	/* LINEAR FORCEs */
	// --- Forces Acting on an Object ---
	//LinearTotalForce += gravity * mass;
	LinearTotalForce += AngularForceAffectingObject;


	/* ANGULAR MOMENT / Torque */    
	// ---- Formula Torque = r * F * sin (Angle)                       ----   
	// ---- r = Distance between centre of mass and force applied.   ----
	// ---- F = Force being applied                                  ----
	// ---- Sin angle = the angle that the force is being applied at ----
	// 
	// !! Each New Torque must include a position of the force being applied and the amount of Force applied !!
	//AngularTorque += (position + GravityPosition) * (gravity * mass);
	AngularTorque += (position + AngularForceAffectingObjectPosition) * AngularForceAffectingObject; // NewTon meters

	
	/* ACCELERATIONS */
	LinearAcceleration = LinearTotalForce / mass; // A = Force / mass
	AngularAcceleration = AngularTorque / AngularInertia; // alpha (Acceleration) = Torque / Inertia  " In Newton meters
}

void RigidBody2D::CalculateVelocity(float deltaTime)
{
	//Vt + dt = Vt + (at)+dt;  // dt = deltaTime, Vt = Velocity at time, (Vt +dt) -> Future Velocity, at = acceleration at the time.
	LinearVelocity = LinearVelocity + (LinearAcceleration)*deltaTime;
	AngularVelocity += (AngularAcceleration)*deltaTime; // w ( Omega ) = 
	/* Requires proper solving https://cnx.org/contents/MymQBhVV@175.14:51fg7QFb@14/Angular-velocity */
}

void RigidBody2D::SetDisplacements(float deltaTime)
{
	FuturePosition = position + (LinearVelocity)*deltaTime;
	position = FuturePosition;

	
	if (orientation >= 360) orientation = 0;

	// Needs to Tetermine which side is more powerful either x axis force or y axis force and Translate it to orientation.
	orientation = orientation + (AngularVelocity.x) * deltaTime;


	// Dampening
	LinearVelocity *= pow(0.1, deltaTime);
	AngularVelocity *= pow(0.1, deltaTime);
}

float RigidBody2D::SqrNumber(float Number)
{
	return Number * Number;
}

float RigidBody2D::FindInertia(float Length, float Height)
{
	// AngularInertia for 2d " 1/12 = 0.0833" -->   Logic ( 1/12 * m * (Length""2 + Height""2)
	float LengthHeightTotal = (SqrNumber(Length) + SqrNumber(Height));
	AngularInertia = 0.0833 * mass * LengthHeightTotal;
	AngularInertia *= 9.8067; // Conversion to Newton Meters.

	return AngularInertia;
}

float RigidBody2D::radiansToDegrees(float value)
{
	value = value * 180 / 3.14;
	return value;
}