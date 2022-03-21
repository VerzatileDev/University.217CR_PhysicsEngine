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
	GameObject::renderBitmapString(position.x - length, position.y - 1.2, position.z, "  LinearVelocity.x " + std::to_string(LinearVelocity.x));
	GameObject::renderBitmapString(position.x - length, position.y - 1.5, position.z, "  orientation " + std::to_string(orientation));

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


	/* LINEAR SUM FORCES */

	/*  ! ADD NEW FORCES HERE !  <-- Make sure the Force applied is also available in ANGULAR MOMENT / TORQUE !*/
	LinearTotalForce += gravity * mass;
	LinearTotalForce += AngularForceAffectingObject;


	                 /* ANGULAR MOMENT / Torque */  
	// ------------------------------------------------------------------
	// ----        Formula Torque = r * F * sin (Angle)              ----   
	// ----  r = Distance between centre of mass and force applied.  ----
	// ----             F = Force being applied                      ----
	// ---- Sin angle = the angle that the force is being applied at ----
	// ------------------------------------------------------------------
	// !! Each New Torque must include a position of the force being applied and the amount of Force applied !!
	
	/*  ! ADD NEW FORCES HERE !  <-- Make sure the Force applied is also available in Linear Motion (Force)*/
	AngularTorque += (position + GravityPosition) * (gravity * mass);
	AngularTorque += (position + AngularForceAffectingObjectPosition) * AngularForceAffectingObject; // NewTon meters

	
	/* ACCELERATIONS */
	LinearAcceleration = LinearTotalForce / mass; // A = Force / mass
	AngularAcceleration = AngularTorque / AngularInertia; // alpha (Acceleration) = Torque / Inertia  " In Newton meters
}

void RigidBody2D::CalculateVelocity(float deltaTime)
{
	/* LINEAR VELOCITY FORMULA */
	// Vt + dt = Vt + (at)+dt;  
	// dt = deltaTime, Vt = Velocity at time, (Vt +dt) -> Future Velocity, at = acceleration at the time.
	LinearVelocity += (LinearAcceleration)*deltaTime;

	/* ANGULAR VELOCITY FORMULA*/
	// w ( Omega ) = ...   Based on --> /* Requires proper solving https://cnx.org/contents/MymQBhVV@175.14:51fg7QFb@14/Angular-velocity */
	AngularVelocity += (AngularAcceleration)*deltaTime;
	
}

void RigidBody2D::SetDisplacements(float deltaTime)
{
	/* SET LINEAR MOTION DISPLACEMENT */
	FuturePosition = position + (LinearVelocity)*deltaTime;
	position = FuturePosition;

	

	if (orientation >= 360) orientation = 0; // When 360 degrees is reached Reset the Orientation back to 0.
	//if (orientation < 0) orientation = 360;
	orientation = orientation + (AngularVelocity.x) * deltaTime; // Needs to Tetermine which side is more powerful either x axis force or y axis force and Translate it to orientation.


	// Dampening --> Force object to slowly reduce its own force being applied (Avoiding infinite Linear motion / Angular Motion)
	LinearVelocity *= pow(0.1, deltaTime);
	AngularVelocity *= pow(0.1, deltaTime);
}

float RigidBody2D::SqrNumber(float Number)
{
	return Number * Number;
}

float RigidBody2D::FindInertia(float Length, float Height)
{
	// AngularInertia for 2d " 1/12 = 0.0833" -->   Logic ( 1/12 * m * (Length""2 + Height""2)     <-- For rectangle
	float LengthHeightTotal = (SqrNumber(Length) + SqrNumber(Height));
	AngularInertia = 0.0833 * mass * LengthHeightTotal;
	AngularInertia *= 9.8067; // Conversion to Newton Meters.

	return AngularInertia;
}

float RigidBody2D::radiansToDegrees(float value)
{
	value *= 180;
	value /= 3.14;
	return value;
}