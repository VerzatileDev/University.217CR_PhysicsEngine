#pragma once
// Include Library Files To be used within a gameobject
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>

class GameObject
{
public:
	GameObject();
	GameObject(glm::vec3 pos, glm::vec3 col);
	~GameObject();
	void Draw();

protected: // To be used within the class itself ( When The Class is Inherited on others)
	glm::vec3 position;
	glm::vec3 color;


};