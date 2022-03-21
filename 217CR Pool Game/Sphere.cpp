#include "Sphere.h"

void Sphere::CheckInput(float deltaTime)
{
	if (GameObject::NonACII_keyMap[GLUT_KEY_UP] == true) {
		position.y += 1.f * deltaTime;
	}
	if (GameObject::NonACII_keyMap[GLUT_KEY_DOWN] == true) {
		position.y -= 1.f * deltaTime;
	}
	if (GameObject::NonACII_keyMap[GLUT_KEY_LEFT] == true) {
		position.x += 1.f * deltaTime;
	}
	if (GameObject::NonACII_keyMap[GLUT_KEY_RIGHT] == true) {
		position.x -= 1.f * deltaTime;
	}
}

Sphere::Sphere()
{}

Sphere::Sphere(float mas, vector3 pos, vector3 col, bool KeyboardUse) : GameObject(mas, pos, col), SphereCollider()
{
	UserInput = KeyboardUse;
}

Sphere::~Sphere()
{}

void Sphere::Draw()
{
	glPushMatrix();																		  // Defines that new element is being used
	glTranslatef(GameObject::position.x, GameObject::position.y, GameObject::position.z); // Location
	glColor3f(GameObject::color.x, GameObject::color.y, GameObject::color.z);             // RGB ( Red,BLue, Green)
	glutSolidSphere(radius, 30, 30);													  // Radius /slices /stacks
	glPopMatrix();																		  // Pops the current matrix stack, replacing the current matrix with one below it on the stack..
	

	/* ! Note that Constructor Method will not work ! Update them Manually*/
	// Update Positions Of the Collider / radius
	SphereColliderPosition = GameObject::position;
	SphereCollider::radius = radius;
	SphereCollider::Draw();
}

void Sphere::Update(float deltaTime)
{
	if(UserInput) CheckInput(deltaTime);
}