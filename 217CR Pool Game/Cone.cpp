#include "Cone.h"

Cone::Cone()
{}

Cone::Cone(float mas, vector3 pos, vector3 col) : GameObject(mas, pos, col)
{}

Cone::~Cone()
{}

void Cone::Draw()
{
	glPushMatrix();                                  // Defines that new element is being used
	glColor3f(color.x, color.y, color.z);            // Color Defined In Main Initilization by GameObject
	glTranslatef(position.x, position.y, position.z);// Coordinate in world space
	glRotatef(orientation, 1, 0, 0);                 // Angle,  (Specified Coordinates to start rotation around ) -> " x, y, z "
	glutSolidCone(0.25, 0.75, 30, 30);               // Base, height, slices (Sides of the cone "The More the more rounded" min 3 to 32"), stacks(Bottom to Top horizontal lines across)
	glPopMatrix();                                   // Pops the current matrix stack, replacing the current matrix with one below it on the stack..
}

void Cone::Update(float deltaTime)
{}