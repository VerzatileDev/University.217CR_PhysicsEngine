#pragma once
// Include Library Files To be used within a gameobject
#include <GL/glew.h>	 // Not Nessecary can be removed
#include <GL/freeglut.h> // Not Nessecary can be removed
#include <GL/glut.h>     //print text to openglwindow
#include <glm/glm.hpp>

// Game Object Specific Includes
#include <map>
#include <iostream> // Deubg And console writeouts
#include <string> // use specifically for display  RenderBitmap..

#define vector3 glm::vec3 // Simplfy & make code easily readable

class GameObject
{
public:
	GameObject();
	GameObject(float mas, vector3 pos, vector3 col);
	~GameObject();
	virtual void Draw() = 0; // Must Return Void As function is inside other class objects.
	virtual void Update(float); // Derived Classes that have no existing Update function, will use One defined here.

	//Keys and Special Keys
	static std::map<char, bool> ACII_keyMap;
	static std::map<int, bool> NonACII_keyMap;

	void renderBitmapString(float x, float y,float z, std::string str); // Display String Text Given to display with Position x / y  " displayed value "

protected: // To be used within the class itself ( When The Class is Inherited on others)
	vector3 position;
	vector3 color;
	float mass = 1; // Set the Lowest Default Mass to be initialized with 1 if not Defined otherwise.
};