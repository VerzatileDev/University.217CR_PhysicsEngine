#include "Circle.h"

void Circle::CheckInput(float deltaTime)
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

void Circle::Draw()
{
	glPushMatrix();
	glTranslatef(GameObject::position.x, GameObject::position.y, GameObject::position.z); // Position / Location
	glRotatef(angle, 0, 0, 1);															// Rotation of the Circle "Orientation"
	int i, x, y;
																						// Size
	glColor3f(GameObject::color.x, GameObject::color.y, GameObject::color.z);			// Color
	double twicePi = 2.0 * 3.142;														// Calculate Pi""2
	x = 0, y = 0;
	glBegin(GL_TRIANGLE_FAN);															// BEGIN CIRCLE Initialization
	glVertex2f(x, y);																	// center location of circle
	for (i = 0; i <= 20; i++) {															// i<= number  <-- Means the amount of triangles around the circle.
		glVertex2f(
			(x + (GameObject::radius * cos(i * twicePi / 20))), (y + (GameObject::radius * sin(i * twicePi / 20)))
		);
	}
	glEnd();																			// END Initializing Circle forming.
	

	if (ShowDetails) {
		Point::size = 5.0f;
		Point::pointColor = Colors3f::Cyan;
		Point::pointLocation = vector3(GameObject::radius, 0, 0);
		Point::Draw();
	}

	// Reference https://stackoverflow.com/questions/22444450/drawing-circle-with-opengl
	/* In Case it is Nessecary to Use Lined Circle " Not Filled one "  Positions are " x + 0 "  change 0 depending where we required the location .. */
	//glPushMatrix();
	//glBegin(GL_LINE_LOOP);
	//for (int ii = 0; ii < 30; ii++) {
	//	float theta = 2.0f * 3.1415926f * float(ii) / float(30);//get the current angle 
	//	float x = 2 * cosf(theta);//calculate the x component 
	//	float y = 2 * sinf(theta);//calculate the y component 
	//	glVertex2f(x + 0, y + 0);//output vertex 
	//}
	//glEnd();
	//glPopMatrix();

	glPopMatrix();

	if (ShowDetails) {
		GameObject::renderBitmapString(GameObject::position.x - GameObject::radius, GameObject::position.y, GameObject::position.z, "  Position.x " + std::to_string(GameObject::position.x));
		GameObject::renderBitmapString(GameObject::position.x - GameObject::radius, GameObject::position.y - 0.3, GameObject::position.z, "  Position.y " + std::to_string(GameObject::position.y));
		GameObject::renderBitmapString(GameObject::position.x - GameObject::radius, GameObject::position.y - 0.6, GameObject::position.z, "  Position.z " + std::to_string(GameObject::position.z));
		GameObject::renderBitmapString(GameObject::position.x - GameObject::radius, GameObject::position.y - 0.9, GameObject::position.z, "  AngularVelocity.x " + std::to_string(RigidBody2D::ShowAngularVelocity.x));
		GameObject::renderBitmapString(GameObject::position.x - GameObject::radius, GameObject::position.y - 1.2, GameObject::position.z, "  LinearVelocity.x " + std::to_string(RigidBody2D::ShowLinearVelocity.x));
		GameObject::renderBitmapString(GameObject::position.x - GameObject::radius, GameObject::position.y - 1.5, GameObject::position.z, "  orientation " + std::to_string(RigidBody2D::orientation));
	}

}

Circle::Circle()
{}

Circle::Circle(float mas, vector3 pos, vector3 col, bool KeyboardUse, float rad ,int UsingRigidBody2D, bool ShowingDetailsOnObject) : GameObject(mas, pos, col, rad), RigidBody2D(mas, pos, col, UsingRigidBody2D)
{

	UserInput = KeyboardUse;
	RigidBodyUsed = UsingRigidBody2D;     // 0 non, 1 circle, 2 rectangle.
	ShowDetails = ShowingDetailsOnObject; // True false "Show dot on Object, see rotation direction / Details of Object : Position, Velocity etc.

}

Circle::~Circle()
{}

void Circle::Update(float deltaTime)
{
	if (UserInput) CheckInput(deltaTime);

	if (RigidBodyUsed == 2 or RigidBodyUsed == 1)
	{
		RigidBody2D::Update(deltaTime);
		GameObject::position = RigidBody2D::position;
		angle = RigidBody2D::orientation;
	}
}