#pragma once // allow C preprocessor to include a header file when it is needed and to ignore an #include directive otherwise
#include "GameObject.h"

class Cube : public GameObject
{
public:
	Cube();                                   // Default Constructor without GameObject
	Cube(float mas, vector3 pos, vector3 col);// Constructor with GameObject
	~Cube();                                  // Destructor
	void Draw();							  // Object Drawn Details
	void Update(float);                       // Object Updates Taking in deltaTime
};