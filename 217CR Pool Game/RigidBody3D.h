#pragma once
#include "GameObject.h"
#include "Color_Utils.h"


class RigidBody3D : public GameObject
{
private:
	/* Linear Motion*/
	// Mass & Position from GameObject 
	vector3 LinearAcceleration = vector3(0, 0, 0);
	vector3 LinearVelocity = vector3(0, 0, 0);
	vector3 FuturePosition = vector3(0, 0, 0);
	vector3 LinearTotalForce = vector3(0, 0, 0);


	/* Rotational Motion.*/
	//glm::mat3 AngularInertia;
	float  AngularInertia;                            // <-- this should be a Matrix  3 by 3    Vec3 column1, vec3 column2, vec3 column3	
													 // mat3 n = mat3(column1, column2, column3);
													 // https://en.wikibooks.org/wiki/GLSL_Programming/Vector_and_Matrix_Operations
	vector3 AngularAcceleration = vector3(0, 0, 0);
	vector3 AngularVelocity = vector3(0, 0, 0);
	vector3 AngularTorque = vector3(0, 0, 0);

	/* FORCES AFFECTING OBJECT AND THEIR POSITION OF AFFECTION*/

	// FORCE 1
	vector3 gravity = vector3(0, -0.5f, 0);
	vector3 GravityPosition = vector3(0, 0, 0);

	// FORCE 2
	vector3 AngularForceAffectingObject = vector3(2, 0, 0);
	vector3 AngularForceAffectingObjectPosition = vector3(1, 1, 0);

	
	float SqrNumber(float Number);

	void CalculateForces(); // Find Forces Applied to Object
	void CalculateVelocity(float deltaTime);
	void SetDisplacements(float deltaTime);

protected:
	float radius = 1.0f;
	float orientation = 0.0;
	int UsingRigidBody3DType = 3; // 3 Means No RigidBody Type is used !!

	vector3 KeyboardForce = vector3(0, 0, 0); // Defined in Other Objects.
	vector3 KeyboardForcePosition = vector3(1, 0, 0);

	// Box Information (HardCode)
	float Width = 1;
	float Length = 1;
	float Height = 1;
public:
	void Draw();															// Object Initilization and set of details
	void Update(float);														// Object Updates Taking in deltaTime
	RigidBody3D();															// Default Constructor Use when Nessecary to add to Other Objects..
	RigidBody3D(float mas, vector3 pos, vector3 col, int UsingRigidBody3D);	// Constructor With GameObject
	~RigidBody3D();															// Destructor



	float GetInertia(float Length, float Height, float width);
	// Return Values functions
};