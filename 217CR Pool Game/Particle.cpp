#include "Particle.h"



Particle::~Particle()
{}

void Particle::Draw()
{
	glPushMatrix();																		  // Defines that new element is being used
	glTranslatef(GameObject::position.x, GameObject::position.y, GameObject::position.z); // Position / Location
	//glRotatef(angle, 0, 0, 1);															// Rotation of the Circle "Orientation"
	int i, x, y;
	// Size
	glColor3f(GameObject::color.x, GameObject::color.y, GameObject::color.z);			// Color
	double twicePi = 2.0 * 3.142;														// Calculate Pi""2
	x = 0, y = 0;
	glBegin(GL_TRIANGLE_FAN);															// BEGIN CIRCLE Initialization
	glVertex2f(x, y);																	// center location of circle
	for (i = 0; i <= 20; i++) {															// i<= number  <-- Means the amount of triangles around the circle.
		glVertex2f(
			(x + (GameObject::radius * cos(i * twicePi / 20))), (y + (GameObject::radius * sin(i * twicePi / 20)))
		);
	}
	glEnd();												 
	
	
	// Displays A Point on the Object making it easier to see rotation. " See Point class for more Information !"
	Point::size = 5.0f;
	Point::pointColor = Colors3f::Red;
	Point::pointLocation = vector3(radius, 0, 0);
	Point::Draw();

	glPopMatrix();

	// Position.x - r states here the text displayed from radius of the object
	// Position.y + 0.3 states the Row for text displayed
	//GameObject::renderBitmapString(position.x - radius, position.y, position.z, "  Position.x " + std::to_string(position.x));
	//GameObject::renderBitmapString(position.x - radius, position.y - 0.3 , position.z, "  Position.y " + std::to_string(position.y));
	//GameObject::renderBitmapString(position.x - radius, position.y - 0.6, position.z, "  Position.z " + std::to_string(position.z));
	
}

void Particle::Update(float deltaTime)
{
	if(UserInput) CheckForKeyboard(deltaTime);  /* Keyboard Force User Applied.*/

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

Particle::Particle(float mas, vector3 pos, vector3 col, float rad, bool KeyboardUse, bool ShowingDetailsOnObject) : GameObject(mas, pos, col, rad)
{
	UserInput = KeyboardUse;
	ShowDetails = ShowingDetailsOnObject; // True false "Show dot on Object, see rotation direction / Details of Object : Position, Velocity etc.
	//radius = rad;
}


void Particle::CalculateForces()
{
	// https://wright.nasa.gov/airplane/drageq.html <-- Drag Force Reference.
	// DragForce = 1/2 * (Density of Fluid) * (Speed relative to the Fluid) * (Cross Sectional Areas) * (drag coefficient)
	// This is simplified version avoiding the use of cross Section and Coefficient
	vector3 DragForce = 0.50f * Drag * (VarletVelocity * VarletVelocity) * 0.47f; // <-- Drag Coefficient of a Sphere.
	/* Calculate Acceleration based on newtons second law*/
	vector3 DragAcceleration = DragForce / mass; // a = f/m
	NewAcceleration = GravAcceleration - DragAcceleration;
}




void Particle::CheckForKeyboard(float deltaTime)
{
	/* Consider !! Having Force = 1.f Instead of applying + each time !!*/
	//if (GameObject::NonACII_keyMap[GLUT_KEY_UP] == true)
		//keyboardForce.y += 1.f * deltaTime;
		//keyboardForce.y = 5f; //<-- Use this for more strict control of particle, with gravity.
	//else keyboardForce.y = 0;
	//if (GameObject::NonACII_keyMap[GLUT_KEY_DOWN] == true)
		//keyboardForce.y -= 1.f * deltaTime;
	//if (GameObject::NonACII_keyMap[GLUT_KEY_RIGHT] == true)
		//keyboardForce.x -= 1.f * deltaTime;
	//else if (GameObject::NonACII_keyMap[GLUT_KEY_LEFT] == true)
		//keyboardForce.x += 1.f * deltaTime;
	//else keyboardForce.x = 0;
}

float Particle::SqrNumber(float Number)
{
	return Number * Number;
}