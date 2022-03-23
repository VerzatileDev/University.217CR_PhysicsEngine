#include "RigidBody3D.h"

void RigidBody3D::Draw()
{
	Sphere::color = RigidBody3D::currentcolor;
	SphereCollider::SphereColliderColor = Colors3f::Magenta;
	Sphere::radius = 1; // When SphereCollider is enabled it also Reflects the radius of Collider as well as Sphere
	Sphere::Draw();
}

void RigidBody3D::Update(float deltaTime)
{
	Sphere::UserInput = true;
	Sphere::Update(deltaTime);
}

RigidBody3D::RigidBody3D()
{}

RigidBody3D::RigidBody3D(float mas, vector3 pos, vector3 col) : GameObject(mas, pos, col), Sphere()
{
	currentcolor = col; // Initialize Color Manually to Avoid Ambigious error !!
}

RigidBody3D::~RigidBody3D()
{}