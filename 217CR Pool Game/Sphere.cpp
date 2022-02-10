#include "Sphere.h"

Sphere::Sphere()
{}

Sphere::Sphere(glm::vec3 pos, glm::vec3 col) : GameObject(pos, col)
{}

Sphere::~Sphere()
{}

void Sphere::Draw()
{
	glPushMatrix(); // Defines that new element is being used
	glTranslatef(position.x, position.y, position.z); // Location
	glColor3f(color.x, color.y, color.z); // RGB ( Red,BLue, Green)
	glutSolidSphere(1.0f, 10, 10); //size
	glPopMatrix(); // Pops the current matrix stack, replacing the current matrix with one below it on the stack..
}
