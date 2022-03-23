#include "Quad2D.h"

void Quad2D::CheckInput(float deltaTime)
{
	if (GameObject::NonACII_keyMap[GLUT_KEY_UP] == true) {
		GameObject::position.y += 1.f * deltaTime;
		//if (RigidBodyUsed == 2 || RigidBodyUsed == 1) RigidBody2D::KeyboardForce.y += 5.f * deltaTime; else RigidBody2D::KeyboardForce.y = 0;
	}
	if (GameObject::NonACII_keyMap[GLUT_KEY_DOWN] == true) {
		GameObject::position.y -= 1.f * deltaTime;
		//if (RigidBodyUsed == 2 || RigidBodyUsed == 1) RigidBody2D::KeyboardForce.y -= 5.f * deltaTime; else RigidBody2D::KeyboardForce.y = 0;
	}
	if (GameObject::NonACII_keyMap[GLUT_KEY_LEFT] == true) {
		GameObject::position.x += 1.f * deltaTime;
		if (RigidBodyUsed == 2 or RigidBodyUsed == 1) RigidBody2D::KeyboardForce.x += 3.f * deltaTime; else RigidBody2D::KeyboardForce.x = 0;
	}
	if (GameObject::NonACII_keyMap[GLUT_KEY_RIGHT] == true) {
		GameObject::position.x -= 1.f * deltaTime;
		if (RigidBodyUsed == 2 or RigidBodyUsed == 1) RigidBody2D::KeyboardForce.x -= 3.f * deltaTime; else RigidBody2D::KeyboardForce.x = 0;
	}
}

Quad2D::Quad2D()
{}

Quad2D::Quad2D(float mas, glm::vec3 pos, glm::vec3 col, bool KeyboardUse, int UsingRigidBody2D, bool ShowingDetailsOnObject) : GameObject(mas, pos, col), RigidBody2D(mas, pos, col, UsingRigidBody2D)
{
	UserInput = KeyboardUse;
	RigidBodyUsed = UsingRigidBody2D;     // 0 non, 1 circle, 2 rectangle.
	ShowDetails = ShowingDetailsOnObject; // True false "Show dot on Object, see rotation direction / Details of Object : Position, Velocity etc.
}

Quad2D::~Quad2D()
{}

void Quad2D::Draw()
{
	
	glPushMatrix();                       // <https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/glPushMatrix.xml> Push / Pop current matric stack

	glTranslatef(GameObject::position.x, GameObject::position.y, GameObject::position.z);
	glRotatef(angle, 0, 0, 1);			  //"angle,x,y,z (define as 0 or 1 ) 0 = means not affected on axis.
	glColor3f(GameObject::color.x, GameObject::color.y, GameObject::color.z); // Color Defined In Main Initilization by GameObject
	glBegin(GL_QUADS);                    // Draw a plane element from the represented 4 point.
	glVertex3f(-length, height, width);	  //top left
	glVertex3f(length, height, width);    //top right
	glVertex3f(length, -height, width);   //bottom right
	glVertex3f(-length, -height, width);  //bottom left
	glEnd();							  // End the Initilization of Quad " Plane " Points

	if (ShowDetails) {
		Point::size = 5.0f;
		Point::pointColor = Colors3f::Cyan;
		Point::pointLocation = vector3(length, 0, 0);
		Point::Draw();
	}

	glPopMatrix();                      // Pops the current matrix stack, replacing the current matrix with one below it on the stack..

	if (ShowDetails) {
		GameObject::renderBitmapString(GameObject::position.x - length, GameObject::position.y, GameObject::position.z, "  Position.x " + std::to_string(GameObject::position.x));
		GameObject::renderBitmapString(GameObject::position.x - length, GameObject::position.y - 0.3, GameObject::position.z, "  Position.y " + std::to_string(GameObject::position.y));
		GameObject::renderBitmapString(GameObject::position.x - length, GameObject::position.y - 0.6, GameObject::position.z, "  Position.z " + std::to_string(GameObject::position.z));
		GameObject::renderBitmapString(GameObject::position.x - length, GameObject::position.y - 0.9, GameObject::position.z, "  AngularVelocity.x " + std::to_string(RigidBody2D::ShowAngularVelocity.x));
		GameObject::renderBitmapString(GameObject::position.x - length, GameObject::position.y - 1.2, GameObject::position.z, "  LinearVelocity.x " + std::to_string(RigidBody2D::ShowLinearVelocity.x));
		GameObject::renderBitmapString(GameObject::position.x - length, GameObject::position.y - 1.5, GameObject::position.z, "  orientation " + std::to_string(RigidBody2D::orientation));
	}
	
}

void Quad2D::Update(float deltaTime)
{
	if (UserInput) CheckInput(deltaTime);

	if (RigidBodyUsed == 2 or RigidBodyUsed == 1)
	{
		RigidBody2D::Update(deltaTime);
		GameObject::position = RigidBody2D::position;
		angle = RigidBody2D::orientation;
	}
	else return;

}