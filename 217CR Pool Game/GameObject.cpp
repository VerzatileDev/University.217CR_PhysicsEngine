#include "GameObject.h"

GameObject::GameObject()
{}

GameObject::GameObject(glm::vec3 pos, glm::vec3 col)
{
	position = pos;
	color = col;
}

GameObject::~GameObject()
{}

void GameObject::Draw()
{}