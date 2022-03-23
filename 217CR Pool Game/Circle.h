#pragma once
#include "GameObject.h"
#include "RigidBody2D.h"

class Circle : public GameObject, public RigidBody2D
{
private:
	void CheckInput(float deltaTime);			// Get UserInput from the Keyboard if enabled by UserInput..
	bool ShowDetails = false;					// Display information on Screen of the Object
protected:
	float angle = 0.0f;							// Default Value of orientation / Angle of the circle
	bool UserInput = false;						// <-- By Default False
	int RigidBodyUsed = 0;						// <-- By Default False " 0 " Can be 0(non), 1(Circle) or 2(rectangle)
public:
	void Draw();								// Object Details and its initialization to display on Screen
	Circle();									// Default Constructor Without GameObject Details
	Circle(float mas, vector3 pos, vector3 col, bool KeyboardUse, int UsingRigidBody2D, bool ShowingDetailsOnObject);// Contructuor using GameObject details / Else
	~Circle();									// Destructor
	void Update(float);							// Object Updates Taking in deltaTime
};