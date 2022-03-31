#include "SphereCollider.h"

bool SphereCollider::CollisionCheck(glm::vec3 position, glm::vec3 position2, float radius1, float radius2)
{
	bool collision = false;
	// Sum of both radiuses
	float radii = radius1 + radius2;
	
	
	// Pythagoras to calculate the distance between two objects.
	float distance = sqrt((position.x - position2.x) * (position.x - position2.x) + (position.y - position2.y) * (position.y - position2.y) + (position.z - position2.z) * (position.z - position2.z));



	if (distance > radii) collision = false;
	if (distance <= radii) collision = true;


	//std::cout << collision << " its true ?" << std::endl;
	return collision; // Return Value if it is colliding or not..
}

SphereCollider::SphereCollider(vector3 SphereColliderPos, vector3 SphereColliderCol, float rad)
{
	SphereColliderColor = SphereColliderCol;
	SphereColliderPosition = SphereColliderPos;
	radius = rad;
}

SphereCollider::SphereCollider()
{
}

SphereCollider::~SphereCollider()
{
}

void SphereCollider::Draw()
{
	glPushMatrix();
	glColor3f(SphereColliderColor.x, SphereColliderColor.y, SphereColliderColor.z); //Magenta is the best debug colour!
	glTranslatef(SphereColliderPosition.x, SphereColliderPosition.y, SphereColliderPosition.z);
	glutWireSphere(radius, 10, 10);
	glPopMatrix();
}
