#pragma once

namespace UserInput
{
	bool isTrue = true;
	bool isFalse = false;
}

namespace UsingRigidBody2D
{
	int non = 0; // Means that No RigidBody Inertia Is applied and No acting RigidBody will be applied.
	int circle = 1;
	int rectangle = 2;
}

namespace UsingRigidBody3D
{
	int non = 3; // Means that No RigidBody Inertia Is applied and No acting RigidBody will be applied.
	int HallowSphere = 4;
	int SolidSphere = 5;
	int Cube = 6;
}

namespace ShowDetails // Shows us Object information on which they are enabled.
{
	bool isTrue = true;
	bool isFalse = false;
}