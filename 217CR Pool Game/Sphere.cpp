#include "Sphere.h"

void Sphere::CheckInput(float deltaTime)
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

Sphere::Sphere()
{}

Sphere::Sphere(float mas, vector3 pos, vector3 col, float rad, bool KeyboardUse, int UsingRigidBody3D, bool ShowingDetailsOnObject) : GameObject(mas, pos, col, rad), SphereCollider()
{
	UserInput = KeyboardUse;
	ShowDetails = ShowingDetailsOnObject; // True false "Show dot on Object, see rotation direction / Details of Object : Position, Velocity etc.
	RigidBodyUsed = UsingRigidBody3D;
}

Sphere::~Sphere()
{}

void Sphere::Draw()
{
	glPushMatrix();																		  // Defines that new element is being used
	glTranslatef(GameObject::position.x, GameObject::position.y, GameObject::position.z); // Location
	glColor3f(GameObject::color.x, GameObject::color.y, GameObject::color.z);             // RGB ( Red,BLue, Green)
	glutSolidSphere(GameObject::radius, 30, 30);													  // Radius /slices /stacks

	if (ShowDetails) {
		Point::size = 5.0f;
		Point::pointColor = Colors3f::Red;
		Point::pointLocation = vector3(GameObject::radius, 0, 0);
		Point::Draw();
	}

	glPopMatrix();																		  // Pops the current matrix stack, replacing the current matrix with one below it on the stack..
	

	/* ! Note that Constructor Method will not work ! Update them Manually*/
	// Update Positions Of the Collider / radius
	SphereColliderPosition = GameObject::position;
	SphereCollider::SphereColliderColor = glm::vec3(1.f, 0.f, 1.0f); // Magenta
	SphereCollider::radius = GameObject::radius;
	SphereCollider::Draw();



	if (ShowDetails) {
		GameObject::renderBitmapString(GameObject::position.x - GameObject::radius, GameObject::position.y, GameObject::position.z, "  Position.x " + std::to_string(GameObject::position.x));
		GameObject::renderBitmapString(GameObject::position.x - GameObject::radius, GameObject::position.y - 0.3, GameObject::position.z, "  Position.y " + std::to_string(GameObject::position.y));
		GameObject::renderBitmapString(GameObject::position.x - GameObject::radius, GameObject::position.y - 0.6, GameObject::position.z, "  Position.z " + std::to_string(GameObject::position.z));
		//GameObject::renderBitmapString(GameObject::position.x - radius, GameObject::position.y - 0.9, GameObject::position.z, "  AngularVelocity.x " + std::to_string(RigidBody3D::ShowAngularVelocity.x));
		//GameObject::renderBitmapString(GameObject::position.x - radius, GameObject::position.y - 1.2, GameObject::position.z, "  LinearVelocity.x " + std::to_string(RigidBody3D::ShowLinearVelocity.x));
		//GameObject::renderBitmapString(GameObject::position.x - radius, GameObject::position.y - 1.5, GameObject::position.z, "  orientation " + std::to_string(RigidBody3D::orientation));
	}

}

void Sphere::Update(float deltaTime)
{
	if(UserInput) CheckInput(deltaTime);
}