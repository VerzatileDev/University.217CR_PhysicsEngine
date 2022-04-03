#pragma once // allow C preprocessor to include a header file when it is needed and to ignore an #include directive otherwise
#include "GameObject.h"
#include "RigidBody2D.h"

class Quad2D : public GameObject, public RigidBody2D
{
private:
	void CheckInput(float deltaTime);		// Get UserInput from the Keyboard if enabled by UserInput..
	
protected:
	bool UserInput = false;					// <-- By Default False
	int RigidBodyUsed = 0;					// <-- By Default False " 0 " Can be 0(non), 1(Circle) or 2(rectangle)
	bool ShowDetails = false;
	float angle = 0.0;						// Default Value of orientation / Angle of the rectangle
	/* Rectangle Information 2D*/
	vector3 ObjectDimensions = vector3(1,1,0); // Default Dimensions
public:
	Quad2D();								// Default Constructor Use when Nessecary to add to Other Objects..
	Quad2D(float mas, glm::vec3 pos, glm::vec3 col, bool KeyboardUse, int UsingRigidBody2D, bool ShowingDetailsOnObject, glm::vec3 LengthHeightWidth); // Constructor using GameObject Details
	~Quad2D();								// Destructor
	void Draw();							// Object Initilization and set of details
	void Update(float);						// Object Updates Taking in deltaTime
};