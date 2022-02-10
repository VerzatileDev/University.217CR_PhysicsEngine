#include "Cube.h"

Cube::Cube()
{
}

Cube::Cube(glm::vec3 pos, glm::vec3 col)
{
	position = pos;
	color = col;
}

Cube::~Cube() // Destructor Called If out of scope. (Out of the Playable Space)
{
}

void Cube::Draw()
{
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glColor3f(color.x, color.y, color.z); // In RGB (Red, Blue, Green)
	glutSolidCube(1.0f); // Size
	glPopMatrix();// Restores Unrotated objects
}