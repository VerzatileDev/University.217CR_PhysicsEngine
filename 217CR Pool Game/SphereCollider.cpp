#include "SphereCollider.h"

int SphereCollider::CollideCheck(SphereCollider)
{
	return 0;
}

SphereCollider::SphereCollider(vector3 SphereColliderPosition, vector3 SphereColliderColor, float radius)
{

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
