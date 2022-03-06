#include "Cube.h"

Cube::Cube()
{}

Cube::Cube(float mas, vector3 pos, vector3 col) : GameObject(mas, pos, col)
{}

Cube::~Cube() // Destructor Called If out of scope. (Out of the Playable Space)
{}

void Cube::Draw()
{
	glPushMatrix(); // Defines that new element is being used
	glTranslatef(position.x, position.y, position.z);
	glColor3f(color.x, color.y, color.z); // In RGB (Red, Blue, Green)
	glutSolidCube(1.0f); // Size
	glPopMatrix(); // Pops current matrix stack, replacing the current matrix with one below it on the stack..
}

void Cube::Update(float deltaTime)
{
	//if (GameObject::NonACII_keyMap[GLUT_KEY_UP] == true)
	//	position.y -= 5.f * deltaTime;
	//if (GameObject::NonACII_keyMap[GLUT_KEY_DOWN] == true)
	//	position.y += 5.f * deltaTime;
}
