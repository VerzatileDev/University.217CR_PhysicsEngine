#include "SphereCollider.h"

bool SphereCollider::CollisionCheck(glm::vec3 position, glm::vec3 position2, float radius1, float radius2)
{
	bool collision = false;
	// Sum of both radiuses
	float radii = radius1 + radius2;
	
	
	// Pythagoras to calculate the distance between two objects.
	float distance = (position.x - position2.x) * (position.x - position2.x) + (position.y - position2.y) * (position.y - position2.y) + (position.z - position2.z) * (position.z - position2.z);



	if (distance > radii * radii)
	{
		collision = false;
	}
	if (distance <= radii * radii)
	{
		// Here we would Would do a second check to see if
		// Balls are moving towards each other
		/* Formula  netVelocity = sphere1->v - sphere2->v
		   displacement = spehre1->pos - sphere2->pos    ;
		   netVelocity * displacement < 0                ;*/

		   // Which sees if they will still be colliding calling collision true or they are already Moving away from object.
		collision = true;
	}


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
