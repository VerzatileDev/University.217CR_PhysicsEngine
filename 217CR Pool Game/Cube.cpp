#include "Cube.h"

void Cube::CheckInput(float deltaTime)
{
	if (GameObject::NonACII_keyMap[GLUT_KEY_UP] == true) {
		position.y += 1.f * deltaTime;
	}
	if (GameObject::NonACII_keyMap[GLUT_KEY_DOWN] == true) {
		position.y -= 1.f * deltaTime;
	}
	if (GameObject::NonACII_keyMap[GLUT_KEY_LEFT] == true) {
		position.x += 1.f * deltaTime;
	}
	if (GameObject::NonACII_keyMap[GLUT_KEY_RIGHT] == true) {
		position.x -= 1.f * deltaTime;
	}
}

Cube::Cube()
{}

Cube::Cube(float mas, vector3 pos, vector3 col, bool KeyboardUse) : GameObject(mas, pos, col)
{
	UserInput = KeyboardUse;
}

Cube::~Cube()
{}

void Cube::Draw()
{
	glPushMatrix();                                   // Defines that new element is being used
	glTranslatef(position.x, position.y, position.z);
	glColor3f(color.x, color.y, color.z);             // In RGB (Red, Blue, Green)
	glutSolidCube(1.0f);                              // Size
	glPopMatrix();                                    // Pops current matrix stack, replacing the current matrix with one below it on the stack..

	/* Text Displayed On Screen from the Object */
	GameObject::renderBitmapString(position.x, position.y, position.z, "    Position.y " + std::to_string(position.y));
}

void Cube::Update(float deltaTime)
{
	if (UserInput) CheckInput(deltaTime);
}
