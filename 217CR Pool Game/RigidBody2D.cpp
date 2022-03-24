#include "RigidBody2D.h"

void RigidBody2D::Draw()
{
	/* !!  ONly Use this For Testing Purposes  !!*/
	glPushMatrix();

	glTranslatef(GameObject::position.x, GameObject::position.y, GameObject::position.z);
	glRotatef(orientation, 0, 0, 1);	  //"angle,x,y,z (define as 0 or 1 ) 0 = means not affected on axis.
	glColor3f(GameObject::color.x, GameObject::color.y, GameObject::color.z); // Color Defined In Main Initilization by GameObject
	glBegin(GL_QUADS);                    // Draw a plane element from the represented 4 point.
	glVertex3f(-length, height, width);	  //top left
	glVertex3f(length, height, width);    //top right
	glVertex3f(length, -height, width);   //bottom right
	glVertex3f(-length, -height, width);  //bottom left
	glEnd();							  // End the Initilization of Quad " Plane " Points
	
	
	// Displays A Point on the Object making it easier to see rotation.
	Point::size = 5.0f;
	Point::pointColor = Colors3f::Cyan;
	Point::pointLocation = vector3(length, 0, 0);
	Point::Draw();

	glPopMatrix();

	// Display Information here
	GameObject::renderBitmapString(GameObject::position.x - length, GameObject::position.y, GameObject::position.z, "  Position.x " + std::to_string(GameObject::position.x));
	GameObject::renderBitmapString(GameObject::position.x - length, GameObject::position.y - 0.3, GameObject::position.z, "  Position.y " + std::to_string(GameObject::position.y));
	GameObject::renderBitmapString(GameObject::position.x - length, GameObject::position.y - 0.6, GameObject::position.z, "  Position.z " + std::to_string(GameObject::position.z));
	GameObject::renderBitmapString(GameObject::position.x - length, GameObject::position.y - 0.9, GameObject::position.z, "  AngularVelocity.x " + std::to_string(AngularVelocity.x));
	GameObject::renderBitmapString(GameObject::position.x - length, GameObject::position.y - 1.2, GameObject::position.z, "  LinearVelocity.x " + std::to_string(LinearVelocity.x));
	GameObject::renderBitmapString(GameObject::position.x - length, GameObject::position.y - 1.5, GameObject::position.z, "  orientation " + std::to_string(orientation));

}

void RigidBody2D::Update(float deltaTime)
{
	//std::cout << AngularInertia << std::endl; // Use this to test a single Object such as Circle or Quad2D
	CalculateForces();							// Linear (Euler method of calculation to find new position)
	CalculateVelocity(deltaTime);
	SetDisplacements(deltaTime);
												// These Are Used For RigidBody Details When Applied to an Object.
	ShowLinearVelocity = LinearVelocity;
	ShowAngularVelocity = AngularVelocity;		// <-- These Elements are Used in External Class such as Quad2D and Circle !!
}

RigidBody2D::RigidBody2D(float mas, vector3 pos, vector3 col, int UsingRigidBody2D) : GameObject(mas, pos, col), Point()
{
	UsingRigidBody2DType = UsingRigidBody2D; // <-- Initialized Through Other Objects Generally if Non on Rigidbody2D itself is used it will not Draw Object !!
	// Kilogram Force meter    Kg m squared = 9.8067 Newton Meters
	// -- Currently Only Set to find inertia of a Rectangle -- //
	FindInertia(length, height); //std::cout << AngularInertia << std::endl; //Debug
}

RigidBody2D::RigidBody2D()
{
	FindInertia(length, height); // <-- Circle Inertia Should be Seperate ! Remember to Change ! " Though it works still Better Practise"
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
	FuturePosition = GameObject::position + (LinearVelocity)*deltaTime;
	GameObject::position = FuturePosition;

	

	if (orientation >= 360 || orientation <= -360) orientation = 0; // When 360 or -360 degrees is reached Reset the Orientation back to 0.
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
	
	//< --For rectangle -->//  <-- Currently For non Uses same as Rectangle.
	// AngularInertia for 2d " 1/12 = 0.0833" -->   Logic ( 1/12 * m * (Length""2 + Height""2)
	if (UsingRigidBody2DType == 2) 
	{
		float LengthHeightTotal = (SqrNumber(Length) + SqrNumber(Height));
		AngularInertia = 0.0833 * GameObject::mass * LengthHeightTotal;
		AngularInertia *= 9.8067; // Conversion to Newton Meters.
	}
	

	//<-- For Circle -->//
	
	//inertia = pi / radius""4 / 4
	// or If with a diameter then :   Inertia = pi / Diameter""4 / 64 // WHere Diameter is 2 * Radius
	if (UsingRigidBody2DType == 1)
	{
		AngularInertia = 3.14159; // Pi = 3.14159
		float RadiusSqrSqr = (SqrNumber((SqrNumber(RigidBodyRadius))));
		AngularInertia /= RadiusSqrSqr;
		AngularInertia /= 4;
	}

	

	// If object etc Hexagon, diamond, Polygon, Triangle
	//std::cout << "I'm Called now" << std::endl;
	return AngularInertia;
}

float RigidBody2D::radiansToDegrees(float value)
{
	value *= 180;
	value /= 3.14;
	return value;
}