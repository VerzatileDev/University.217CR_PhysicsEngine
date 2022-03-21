#pragma once
#include "GameObject.h"

class Cone : public GameObject
{
private:
	void CheckInput(float deltaTime);
public:
	Cone();													    // Default Constructor without GameObject
	Cone(float mas, vector3 pos, vector3 col, bool KeyboardUse);// Constructor with GameObject
	~Cone();													// Destructor
	void Draw();												// Object Drawn Details
	void Update(float);										    // Object Updates Taking in deltaTime
protected:
	float orientation = 0;										// Angle of the object currently " see x,y,z to see on which angle object is orientated "
	bool UserInput;
};