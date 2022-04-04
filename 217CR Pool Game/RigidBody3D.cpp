#include "RigidBody3D.h"

void RigidBody3D::Draw()
{
	glPushMatrix();																		  // Defines that new element is being used
	glTranslatef(GameObject::position.x, GameObject::position.y, GameObject::position.z); // Location
	glRotatef(orientation, 0, 0, 1);
	//glRotatef(orientation, 0, 1, 0);
	//glRotatef(orientation, 1, 0, 0);  // Use these For Full 3D Orientation angle Setting
	glColor3f(GameObject::color.x, GameObject::color.y, GameObject::color.z);             // RGB ( Red,BLue, Green)
	glutSolidSphere(radius, 30, 30);													  // Radius /slices /stacks
	glPopMatrix();																		  // Pops the current matrix stack, replacing the current matrix with one below it on the stack..

}

void RigidBody3D::Update(float deltaTime)
{
	//std::cout << AngularInertia << std::endl; // Use this to test a single Object such as Circle or Quad2D
	CalculateForces();							// Linear (Euler method of calculation to find new position)
	CalculateVelocity(deltaTime);
	SetDisplacements(deltaTime);
	// These Are Used For RigidBody Details When Applied to an Object.
	
}

RigidBody3D::RigidBody3D()
{
	GetInertia(Length, Height, Width);
}

RigidBody3D::RigidBody3D(float mas, vector3 pos, vector3 col, int UsingRigidBody3D) : GameObject(mas, pos, col)
{
	UsingRigidBody3DType = UsingRigidBody3D; // Tells what type of RigidBody is used.
	GetInertia(Length, Height, Width);
}

RigidBody3D::~RigidBody3D()
{}

void RigidBody3D::CalculateForces()
{
	//Reset Forces And Moments
	LinearTotalForce = vector3(0, 0, 0);
	AngularTorque = vector3(0, 0, 0);


	/* LINEAR SUM FORCES */
	/*  ! ADD NEW FORCES HERE !  <-- Make sure the Force applied is also available in ANGULAR MOMENT / TORQUE !*/
	LinearTotalForce += gravity * GameObject::mass;
	LinearTotalForce += AngularForceAffectingObject;
	LinearTotalForce += KeyboardForce;


	/* ANGULAR MOMENT / Torque */
	// ------------------------------------------------------------------
	// ----        Formula Torque = r * F * sin (Angle)              ----   
	// ----  r = Distance between centre of mass and force applied.  ----
	// ----             F = Force being applied                      ----
	// ---- Sin angle = the angle that the force is being applied at ----
	// ------------------------------------------------------------------
	// !! Each New Torque must include a position of the force being applied and the amount of Force applied !!

	/*  ! ADD NEW FORCES HERE !  <-- Make sure the Force applied is also available in Linear Motion (Force)*/
	AngularTorque += (GameObject::position + GravityPosition) * (gravity * GameObject::mass);
	AngularTorque += (GameObject::position + AngularForceAffectingObjectPosition) * AngularForceAffectingObject; // NewTon meters
	AngularTorque += (GameObject::position + KeyboardForcePosition) * KeyboardForce;


	/* ACCELERATIONS */
	LinearAcceleration = LinearTotalForce / GameObject::mass; // A = Force / mass
	AngularAcceleration = AngularTorque / AngularInertia; // alpha (Acceleration) = Torque / Inertia  " In Newton meters
}

void RigidBody3D::CalculateVelocity(float deltaTime)
{
	/* LINEAR VELOCITY FORMULA */
	// Vt + dt = Vt + (at)+dt;  
	// dt = deltaTime, Vt = Velocity at time, (Vt +dt) -> Future Velocity, at = acceleration at the time.
	LinearVelocity += (LinearAcceleration)*deltaTime;

	/* ANGULAR VELOCITY FORMULA*/
	// w ( Omega ) = ...   Based on --> /* Requires proper solving https://cnx.org/contents/MymQBhVV@175.14:51fg7QFb@14/Angular-velocity */
	AngularVelocity += (AngularAcceleration)*deltaTime;
}

void RigidBody3D::SetDisplacements(float deltaTime)
{
	/* SET LINEAR MOTION DISPLACEMENT */
	FuturePosition = GameObject::position + (LinearVelocity)*deltaTime;
	GameObject::position = FuturePosition;



	if (orientation >= 360 || orientation <= -360) orientation = 0; // When 360 or -360 degrees is reached Reset the Orientation back to 0.
	orientation = orientation + (AngularVelocity.x) * deltaTime; // Needs to Tetermine which side is more powerful either x axis force or y axis force and Translate it to orientation.


	// Dampening --> Force object to slowly reduce its own force being applied (Avoiding infinite Linear motion / Angular Motion)
	LinearVelocity *= pow(0.1, deltaTime);
	AngularVelocity *= pow(0.1, deltaTime);
	
}

float RigidBody3D::GetInertia(float Length, float Height, float width)
{
	// Hallow Sphere
	if (UsingRigidBody3DType == 4) {
		// Formula Inertia = 2/3 * mass * radius""2;
		AngularInertia += 0.6f * mass * (SqrNumber(radius));
	}
	
	// Solid Sphere
	if (UsingRigidBody3DType == 5) {
		// Formula :  Inertia = 2/5 * mass * radius""2
		AngularInertia += 0.4f * mass * (SqrNumber(radius));
	}

	// Solid Cubanoid
	if (UsingRigidBody3DType == 6) {
		//  Formula : Inertia = 1/12 * mass * (Width""2 + (width + height +length)""2)

		float volume = width + Height + Length;
		AngularInertia += 0.083f * mass * (SqrNumber(width) + SqrNumber(volume));
		//https://www.fxsolver.com/browse/formulas/Moment+of+inertia+of+a+solid+cuboid+%28+Axis+of+rotation+at+the+height+%29
	}

	return AngularInertia;
}

float RigidBody3D::SqrNumber(float Number)
{
	return Number * Number;
}