#include "Quad2D.h"

void Quad2D::CheckInput(float deltaTime)
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

Quad2D::Quad2D()
{}

Quad2D::Quad2D(float mas, glm::vec3 pos, glm::vec3 col, bool KeyboardUse) : GameObject(mas, pos, col)
{
	UserInput = KeyboardUse;
}

Quad2D::~Quad2D()
{}

void Quad2D::Draw()
{
	glPushMatrix();                       // <https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/glPushMatrix.xml> Push / Pop current matric stack
	glColor3f(color.x, color.y, color.z); // Color Defined In Main Initilization by GameObject
	glBegin(GL_QUADS);                    // Draw a plane element from the represented 4 point.
	glVertex3f(5, 5, 0);                  // top right
	glVertex3f(-5, 5, 0);                 // top left
	glVertex3f(-5, -5, -0);               // bottom right
	glVertex3f(5, -5, -0);                // bottom left
	glEnd();
	glPopMatrix();                        // Pops the current matrix stack, replacing the current matrix with one below it on the stack..
}

void Quad2D::Update(float deltaTime)
{
	if (UserInput) CheckInput(deltaTime);
}