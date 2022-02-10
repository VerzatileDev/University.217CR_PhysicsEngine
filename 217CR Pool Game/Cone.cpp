#include "Cone.h"

Cone::Cone()
{
}

Cone::Cone(glm::vec3 pos, glm::vec3 col)
{
	position = pos;
	color = col;
}

Cone::~Cone()
{
}

void Cone::Draw()
{
	glPushMatrix(); // Defines that new element is being used
	glColor3f(color.x, color.y, color.z);
	glTranslatef(position.x, position.y, position.z); // Coordinate in world space
	glRotatef(-65, 1, 0, 0); // Angle,  (Specified Coordinates to start rotation around ) -> " x, y, z "
	glutSolidCone(0.5, 0.75, 30, 30);
	glPopMatrix(); // Sets the Element
}