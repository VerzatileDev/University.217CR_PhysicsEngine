#include "Sphere.h"

Sphere::Sphere()
{}

Sphere::Sphere(float mas, glm::vec3 pos, glm::vec3 col) : GameObject(mas, pos, col)
{}

Sphere::~Sphere()
{}

void Sphere::Draw()
{
	glPushMatrix();                                   // Defines that new element is being used
	glTranslatef(position.x, position.y, position.z); // Location
	glColor3f(color.x, color.y, color.z);             // RGB ( Red,BLue, Green)
	glutSolidSphere(1.0f, 30, 30);                    // Radius /slices /stacks
	glPopMatrix();                                    // Pops the current matrix stack, replacing the current matrix with one below it on the stack..
}

void Sphere::Update(float deltaTime)
{}