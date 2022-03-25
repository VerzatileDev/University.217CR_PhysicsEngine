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

Cube::Cube(float mas, vector3 pos, vector3 col, bool KeyboardUse, int UsingRigidBody3D, bool ShowingDetailsOnObject) : GameObject(mas, pos, col)
{
	UserInput = KeyboardUse;
	ShowDetails = ShowingDetailsOnObject; // True false "Show dot on Object, see rotation direction / Details of Object : Position, Velocity etc.
	RigidBodyUsed = UsingRigidBody3D;
}

Cube::~Cube()
{}

void Cube::Draw()
{
	glPushMatrix();                                   // Defines that new element is being used
	glTranslatef(position.x, position.y, position.z);
	glRotatef(orientation, 1, 0, 0);                  // Angle,  (Specified Coordinates to start rotation around ) -> " x, y, z "
	glColor3f(color.x, color.y, color.z);             // In RGB (Red, Blue, Green)
	glutSolidCube(1.0f);                              // Size


	if (ShowDetails) {
		Point::size = 3.0f;
		Point::pointColor = Colors3f::Cyan;
		Point::pointLocation = vector3(0.5, 0.5, -0.5);
		Point::Draw();
	}

	glPopMatrix();                                    // Pops current matrix stack, replacing the current matrix with one below it on the stack..

	if (ShowDetails) {
		GameObject::renderBitmapString(GameObject::position.x - 1, GameObject::position.y, GameObject::position.z, "  Position.x " + std::to_string(GameObject::position.x));
		GameObject::renderBitmapString(GameObject::position.x - 1, GameObject::position.y - 0.3, GameObject::position.z, "  Position.y " + std::to_string(GameObject::position.y));
		GameObject::renderBitmapString(GameObject::position.x - 1, GameObject::position.y - 0.6, GameObject::position.z, "  Position.z " + std::to_string(GameObject::position.z));
		//GameObject::renderBitmapString(GameObject::position.x - 1, GameObject::position.y - 0.9, GameObject::position.z, "  AngularVelocity.x " + std::to_string(RigidBody3D::ShowAngularVelocity.x));
		//GameObject::renderBitmapString(GameObject::position.x - 1, GameObject::position.y - 1.2, GameObject::position.z, "  LinearVelocity.x " + std::to_string(RigidBody3D::ShowLinearVelocity.x));
		//GameObject::renderBitmapString(GameObject::position.x - 1, GameObject::position.y - 1.5, GameObject::position.z, "  orientation " + std::to_string(RigidBody3D::orientation));
	}
}

void Cube::Update(float deltaTime)
{
	if (UserInput) CheckInput(deltaTime);
}
