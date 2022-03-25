#include "Cone.h"

void Cone::CheckInput(float deltaTime)
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

Cone::Cone()
{}

Cone::Cone(float mas, vector3 pos, vector3 col, bool KeyboardUse, int UsingRigidBody3D, bool ShowingDetailsOnObject) : GameObject(mas, pos, col)
{
	UserInput = KeyboardUse;
	ShowDetails = ShowingDetailsOnObject; // True false "Show dot on Object, see rotation direction / Details of Object : Position, Velocity etc.
	RigidBodyUsed = UsingRigidBody3D;
}

Cone::~Cone()
{}

void Cone::Draw()
{
	glPushMatrix();                                  // Defines that new element is being used
	glColor3f(color.x, color.y, color.z);            // Color Defined In Main Initilization by GameObject
	glTranslatef(position.x, position.y, position.z);// Coordinate in world space
	glRotatef(orientation, 1, 0, 0);                 // Angle,  (Specified Coordinates to start rotation around ) -> " x, y, z "
	glutSolidCone(0.25, 0.75, 30, 30);               // Base, height, slices (Sides of the cone "The More the more rounded" min 3 to 32"), stacks(Bottom to Top horizontal lines across)
	
	if (ShowDetails) {
		Point::size = 5.0f;
		Point::pointColor = Colors3f::Cyan;
		Point::pointLocation = vector3(1, 0, 0);
		Point::Draw();
	}
	
	
	glPopMatrix();                                   // Pops the current matrix stack, replacing the current matrix with one below it on the stack..

	if (ShowDetails) {
		GameObject::renderBitmapString(GameObject::position.x - 1, GameObject::position.y, GameObject::position.z, "  Position.x " + std::to_string(GameObject::position.x));
		GameObject::renderBitmapString(GameObject::position.x - 1, GameObject::position.y - 0.3, GameObject::position.z, "  Position.y " + std::to_string(GameObject::position.y));
		GameObject::renderBitmapString(GameObject::position.x - 1, GameObject::position.y - 0.6, GameObject::position.z, "  Position.z " + std::to_string(GameObject::position.z));
		//GameObject::renderBitmapString(GameObject::position.x - 1, GameObject::position.y - 0.9, GameObject::position.z, "  AngularVelocity.x " + std::to_string(RigidBody3D::ShowAngularVelocity.x));
		//GameObject::renderBitmapString(GameObject::position.x - 1, GameObject::position.y - 1.2, GameObject::position.z, "  LinearVelocity.x " + std::to_string(RigidBody3D::ShowLinearVelocity.x));
		//GameObject::renderBitmapString(GameObject::position.x - 1, GameObject::position.y - 1.5, GameObject::position.z, "  orientation " + std::to_string(RigidBody3D::orientation));
	}

}

void Cone::Update(float deltaTime)
{
	if (UserInput) CheckInput(deltaTime);
}