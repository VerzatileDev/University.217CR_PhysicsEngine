#pragma once // allow C preprocessor to include a header file when it is needed and to ignore an #include directive otherwise
#include "GameObject.h"

class Cube : public GameObject // Libraries From GameObject
{
public:
	Cube(); // Default constructor
	Cube(float mas, vector3 pos, vector3 col); // Specified Constructor Initialz of the cube.
	~Cube();
	void Draw();
	void Update(float);

};