#pragma once // allow C preprocessor to include a header file when it is needed and to ignore an #include directive otherwise
#include "GameObject.h"

class Cube : public GameObject
{
private:
	void CheckInput(float deltaTime);
protected:
	bool UserInput;
	bool ShowDetails = false;
	int RigidBodyUsed = 0;																						   // 0 = non.
	float orientation = 0.0;																					   // Default Value of orientation / Angle
public:
	Cube();																										   // Default Constructor without GameObject
	Cube(float mas, vector3 pos, vector3 col, bool KeyboardUse, int UsingRigidBody3D, bool ShowingDetailsOnObject);// Constructor with GameObject
	~Cube();																									   // Destructor
	void Draw();																								   // Object Drawn Details
	void Update(float);																						       // Object Updates Taking in deltaTime
};