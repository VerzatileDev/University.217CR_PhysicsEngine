#include "GameEngine.h"

/* OBJECT DETAILS :
MASS      default =  1.0f
POSITION  default = vector3(0, 0, 0)
COLOR     default = vector3(1.0f, 2.0f, 1.0f) -> " White " / see Color_Utils for more
*/
GameObject* quad = new Quad2D(1.0f, vector3(0, 0, 0), Colors3f::Dark_Blue);
GameObject* cube = new Cube(1.0f, vector3(0, 0, 0), Colors3f::Red);
GameObject* sphere = new Sphere(1.0f, vector3(0, -2, 0), Colors3f::Green);
GameObject* cone = new Cone(1.0f, vector3(1, -1, 0), Colors3f::Green);
GameObject* particle = new Particle(1.0f, vector3(0, 0, 0), Colors3f::Green);
GameObject* rigidbody2d = new RigidBody2D(1.0f, vector3(0, 0, 0), Colors3f::Orange);


GameEngine Engine;

/* GLUT runs a Console Application Beginning from Main()*/
int main(int argc, char** argv)
{
	Engine.InitEngine(argc, argv, "9032499 Pool Game", 500, 500);

	// Push Back Objects (Initialize)
	Engine.AddGameObject(particle);
	Engine.AddGameObject(rigidbody2d);

	Engine.StartEngine();

	return 0;
}