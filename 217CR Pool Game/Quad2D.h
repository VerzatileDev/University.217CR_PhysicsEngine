#pragma once // allow C preprocessor to include a header file when it is needed and to ignore an #include directive otherwise
#include "GameObject.h"

class Quad2D : public GameObject
{
private:
	void CheckInput(float deltaTime);
protected:
	bool UserInput;
public:
	Quad2D();                                        // Default constructor without the use of GameObject
	Quad2D(float mas, glm::vec3 pos, glm::vec3 col, bool KeyboardUse); // Constructor using GameObject Details
	~Quad2D();                                       // Destructor
	void Draw();                                     // Object Initilization and set of details
	void Update(float);                              // Object Updates Taking in deltaTime
};