#pragma once
#include "GameObject.h"
// IN GAMEOBJECT glm::vec3 is defined as vector3 !

class RigidBody2D
{
private:
	float mass;
	vector3 linearAcceleration;
	vector3 linearVelocity;
	vector3 rigidbody2dPosition;
	vector3 linearForces;

	// Rotational Motion.
	float rotationalInertia; // -- In case 3D inertia must be a matrix.
	

};