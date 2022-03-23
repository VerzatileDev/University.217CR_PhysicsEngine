#pragma once // allow C preprocessor to include a header file when it is needed and to ignore an #include directive otherwise
#include "GameObject.h"
#include "RigidBody2D.h"

class Quad2D : public GameObject, public RigidBody2D
{
private:
	void CheckInput(float deltaTime);
	
	bool ShowDetails = false;
protected:
	bool UserInput;
	int RigidBodyUsed = 0;
	float angle = 0.0;
	/* Rectangle Information 2D*/
	float width = 0; // on Z Axis
	float length = 1; // on x Axis
	float height = 1; // on y Axis
public:
	Quad2D();														   // Default Constructor Use when Nessecary to add to Other Objects..
	Quad2D(float mas, glm::vec3 pos, glm::vec3 col, bool KeyboardUse, int UsingRigidBody2D, bool ShowingDetailsOnObject); // Constructor using GameObject Details
	~Quad2D();														   // Destructor
	void Draw();													   // Object Initilization and set of details
	void Update(float);												   // Object Updates Taking in deltaTime
};