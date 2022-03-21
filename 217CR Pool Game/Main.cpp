#include "GameEngine.h"

// Resource Files
#include "Color_Utils.h" // Defines Usable color3f / color4f
#include "Default_Utils.h" // For Odd Reasons, this Header File Cannot be Included anywhere else and Gives Errors, that everything inside is already defiend. 

/* OBJECT DETAILS :
MASS      default =  1.0f
POSITION  default = vector3(0, 0, 0)
COLOR     default = vector3(1.0f, 2.0f, 1.0f) -> " White " / see Color_Utils for more
*/
GameObject* quad = new Quad2D(1.0f, vector3(0, 0, 0), Colors3f::Dark_Blue, UserInput::isFalse);
GameObject* cube = new Cube(1.0f, vector3(0, 0, 0), Colors3f::Red, UserInput::isFalse);

GameObject* sphere = new Sphere(1.0f, vector3(0, -1, 0), Colors3f::Green, UserInput::isTrue);
GameObject* sphere1 = new Sphere(1.0f, vector3(0, 2, 0), Colors3f::Green, UserInput::isFalse);
GameObject* sphere2 = new Sphere(1.0f, vector3(2, 0, 0), Colors3f::Green, UserInput::isFalse);

GameObject* cone = new Cone(1.0f, vector3(1, -1, 0), Colors3f::Green, UserInput::isFalse);
GameObject* particle = new Particle(1.0f, vector3(0, 0, 0), Colors3f::Green, UserInput::isFalse);
GameObject* rigidbody2d = new RigidBody2D(1.0f, vector3(0, 0, 0), Colors3f::Orange);

GameEngine Engine;

/* GLUT runs a Console Application Beginning from Main()*/
int main(int argc, char** argv)
{
	Engine.InitEngine(argc, argv, "9032499 Pool Game", 500, 500);

	// Push Back Objects (Initialize)
	Engine.AddGameObject(particle);
	//Engine.AddGameObject(rigidbody2d);
	//Engine.AddGameObject(cube);
	Engine.AddGameObject(sphere);
	Engine.AddGameObject(sphere1);
	Engine.AddGameObject(sphere2);

	Engine.StartEngine();

	return 0;
}