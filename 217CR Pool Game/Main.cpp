#include "GameEngine.h"

// Resource Files
#include "Color_Utils.h" // Defines Usable color3f / color4f
#include "Default_Utils.h" // For Odd Reasons, this Header File Cannot be Included anywhere else and Gives Errors, that everything inside is already defiend. 

/* OBJECT DETAILS :
MASS      default =  1.0f
POSITION  default = vector3(0, 0, 0)
COLOR     default = vector3(1.0f, 2.0f, 1.0f) -> " White " / see Color_Utils for more
True/False UserInput    " Enables The Use of a Keyboard For the User Object "// See more on Default_Utils
True/False RigidBody2D  " Adds Forces And calcualtions for Positions as well as Angular Motion // More At Default_Utils
True/False ShowDetails  " Lets us See information such as position of the object etc "  // More At Default_Utils
*/

// 2D Objects That can use RigidBody2D Calculations
GameObject* quad = new Quad2D(1.0f, vector3(0, 0, 0), Colors3f::Dark_Blue, UserInput::isFalse, UsingRigidBody2D::rectangle, ShowDetails::isFalse);
GameObject* quad1 = new Quad2D(1.0f, vector3(-2, 0, 0), Colors3f::Green, UserInput::isFalse, UsingRigidBody2D::non, ShowDetails::isFalse);
GameObject* circle = new Circle(1.0f, vector3(0, 0, 0), Colors3f::Green, UserInput::isFalse, UsingRigidBody2D::circle, ShowDetails::isFalse);


GameObject* particle = new Particle(1.0f, vector3(0, 0, 0), Colors3f::Green, UserInput::isFalse); // Default Linear Motion
GameObject* cube = new Cube(1.0f, vector3(0, 0, 0), Colors3f::Red, UserInput::isFalse);
GameObject* sphere = new Sphere(1.0f, vector3(0, -1, 0), Colors3f::Green, UserInput::isFalse);
GameObject* sphere1 = new Sphere(1.0f, vector3(0, 2, 0), Colors3f::Green, UserInput::isFalse);
GameObject* cone = new Cone(1.0f, vector3(1, -1, 0), Colors3f::Green, UserInput::isFalse);

/* !!! If you want to See rigidBody in action Attach them to an Object Instead. !!!*/
GameObject* rigidbody2d = new RigidBody2D(1.0f, vector3(2, 0, 0), Colors3f::Orange, UsingRigidBody2D::rectangle); // Only Use this For Testing Purposes !!
GameObject* rigidbody3d = new RigidBody3D(1.0f, vector3(0, 0, 0), Colors3f::Orange); // Only Use this For Testing Purposes !!



GameEngine Engine;

/* GLUT runs a Console Application Beginning from Main()*/
int main(int argc, char** argv)
{
	Engine.InitEngine(argc, argv, "9032499 Pool Game", 500, 500);

	// Push Back Objects (Initialize)
	//Engine.AddGameObject(particle);
	//Engine.AddGameObject(quad);
	//Engine.AddGameObject(rigidbody2d);
	//Engine.AddGameObject(quad1);
	//Engine.AddGameObject(cube);
	Engine.AddGameObject(circle);
	//Engine.AddGameObject(sphere);
	//Engine.AddGameObject(sphere1);

	//Engine.AddGameObject(rigidbody3d);

	Engine.StartEngine();
	return 0;
}