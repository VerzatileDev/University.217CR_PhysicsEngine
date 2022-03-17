#include "Particle.h"

Particle::Particle(float mas, vector3 pos, vector3 col) : GameObject(mas, pos, col)
{}

Particle::~Particle()
{}

void Particle::Draw()
{
	glPushMatrix();
	glColor3f(color.x, color.y, color.z);
	glTranslatef(position.x, position.y, position.z);
	glutSolidSphere(r, 20, 20);
	
	// Displays A Point on the Object making it easier to see rotation.
	glPointSize(5.0f);
	glColor3f(1.f, 0.f, 0.f);
	glBegin(GL_POINTS);
	glVertex3f(r, 0, 0); // Location of the Point relative to the object
	glEnd();
	glPopMatrix();

	// Position.x - r states here the text displayed from radius of the object
	// Position.y + 0.3 states the Row for text displayed
	GameObject::renderBitmapString(position.x - r, position.y, position.z, "  Position.x " + std::to_string(position.x));
	GameObject::renderBitmapString(position.x - r, position.y - 0.3 , position.z, "  Position.y " + std::to_string(position.y));
	GameObject::renderBitmapString(position.x - r, position.y - 0.6, position.z, "  Position.z " + std::to_string(position.z));
	GameObject::renderBitmapString(position.x - r, position.y - 0.9, position.z, "  LinearForce.x " + std::to_string(LinearTotalForce.x));
	GameObject::renderBitmapString(position.x - r, position.y - 1.2, position.z, "  LinearVelocity.x " + std::to_string(LinearVelocity.x));
}

void Particle::Update(float deltaTime)
{
	CheckForKeyboard(deltaTime);  /* Keyboard Force User Applied.*/
	CalculateForces();            // Find Forces Being applied to the Object
	CalculateVelocity(deltaTime); // Find the displacement of the acceleration.
	SetDisplacements(deltaTime);  // Find the New Position of the Object After Forces being applied.
}

void Particle::CalculateForces()
{
	LinearTotalForce = vector3(0, 0, 0); // Reset Force
	LinearTotalForce += gravity * mass;
	LinearTotalForce += wind;
	LinearTotalForce += keyboardForce; // std::cout << keyboardForce.y << std::endl;// Debug
	
	/* ACCELERATION */
	LinearAcceleration = LinearTotalForce / mass; // acceleration = Force/ mass

	// Developer Comments "  
	//1. In case the Mass were to change, for example some type of impact is the reason to Use *mass and then  /m to get the difference.
	//2. Forces affecting the Object * It is best that each new force is applied seperatly *
}

void Particle::CalculateVelocity(float deltaTime)
{
	/*
		Vt + dt = Vt +(at) + dt;  // dt = deltaTime, Vt = Velocity at time, (Vt +dt) -> Future Velocity, at = acceleration at the time.
		deltaTime -> Time taken From previous frame to next.
	*/
	LinearVelocity += (LinearAcceleration)*deltaTime;
	//std::cout << velocity.y << std::endl; // Debug
}

void Particle::SetDisplacements(float deltaTime)
{
	FuturePosition = position + (LinearVelocity)*deltaTime;
	position = FuturePosition;

	// Dampening " Makes sure that the object stops moving forever. To test Use Keyboard Only.
	LinearVelocity *= pow(0.1, deltaTime);
}

void Particle::CheckForKeyboard(float deltaTime)
{
	/* Consider !! Having Force = 1.f Instead of applying + each time !!*/
	if (GameObject::NonACII_keyMap[GLUT_KEY_UP] == true)
		keyboardForce.y += 1.f * deltaTime;
		//keyboardForce.y = 5f; //<-- Use this for more strict control of particle, with gravity.
	else keyboardForce.y = 0;
	//if (GameObject::NonACII_keyMap[GLUT_KEY_DOWN] == true)
	//	keyboardForce.y -= 1.f * deltaTime;
	if (GameObject::NonACII_keyMap[GLUT_KEY_RIGHT] == true)
		keyboardForce.x -= 1.f * deltaTime;
	else if (GameObject::NonACII_keyMap[GLUT_KEY_LEFT] == true)
		keyboardForce.x += 1.f * deltaTime;
	else keyboardForce.x = 0;
}