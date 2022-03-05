#pragma once
// Include Library Files To be used within a gameobject
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <map>
#include <iostream> // Deubg And console writeouts

class GameObject
{
public:
	GameObject();
	GameObject(float mas, glm::vec3 pos, glm::vec3 col);
	~GameObject();
	virtual void Draw() = 0; // Must Return Void As function is inside other class objects.
	virtual void Update(float); // Derived Classes that have no existing Update function, will use One defined here.

	//Keys and Special Keys
	static std::map<char, bool> ACII_keyMap;
	static std::map<int, bool> NonACII_keyMap;

protected: // To be used within the class itself ( When The Class is Inherited on others)
	glm::vec3 position;
	glm::vec3 color;
	float mass;
};