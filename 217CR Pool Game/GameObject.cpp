#include "GameObject.h"

/* Key Value maps for ACII / NOn ACII*/
std::map<char, bool> GameObject::ACII_keyMap;
std::map<int, bool> GameObject::NonACII_keyMap;

GameObject::GameObject()
{}

GameObject::GameObject(float mas, glm::vec3 pos, glm::vec3 col)
{
	position = pos;
	color = col;
	mass = mas;
}

GameObject::~GameObject()
{}

void GameObject::Draw()
{}

void GameObject::Update(float deltaTime)
{}