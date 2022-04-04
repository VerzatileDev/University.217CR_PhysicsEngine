#include "GameEngine.h"

// Resource Files
#include "Color_Utils.h"
#include "Default_Utils.h"

/* OBJECT DETAILS :
MASS      default =  1.0f
POSITION  default = vector3(0, 0, 0)
COLOR     default = vector3(1.0f, 2.0f, 1.0f) -> " White " / see Color_Utils for more
Radius    If Defined Uses Float = 1.0f; On Default by GameObject
True/False UserInput    " Enables The Use of a Keyboard For the User Object "// See more on Default_Utils
True/False RigidBody2D  " Adds Forces And calcualtions for Positions as well as Angular Motion // More At Default_Utils
True/False ShowDetails  " Lets us See information such as position of the object etc "  // More At Default_Utils
*/

/* SETUP OF POOL TABLE */
// 2D Objects That can use RigidBody2D Calculations
GameObject* table = new Quad2D(1.0f, vector3(0, 0, 5), Colors3f::Forest_Green, UserInput::isFalse, UsingRigidBody2D::non, ShowDetails::isFalse, vector3(12, 8, 0)/* Size Lenght height width */);
GameObject* hole1 = new Quad2D(1.0f, vector3(11, 7, 5), Colors3f::Black, UserInput::isFalse, UsingRigidBody2D::non, ShowDetails::isFalse, vector3(0.6, 0.6, 0)/* Size*/);
GameObject* hole2 = new Quad2D(1.0f, vector3(11, -7, 5), Colors3f::Black, UserInput::isFalse, UsingRigidBody2D::non, ShowDetails::isFalse, vector3(0.6, 0.6, 0)/* Size*/);
GameObject* hole3 = new Quad2D(1.0f, vector3(0, 7, 5), Colors3f::Black, UserInput::isFalse, UsingRigidBody2D::non, ShowDetails::isFalse, vector3(0.6, 0.6, 0)/* Size*/);
GameObject* hole4 = new Quad2D(1.0f, vector3(0, -7, 5), Colors3f::Black, UserInput::isFalse, UsingRigidBody2D::non, ShowDetails::isFalse, vector3(0.6, 0.6, 0)/* Size*/);
GameObject* hole5 = new Quad2D(1.0f, vector3(-11, 7, 5), Colors3f::Black, UserInput::isFalse, UsingRigidBody2D::non, ShowDetails::isFalse, vector3(0.6, 0.6, 0)/* Size*/);
GameObject* hole6 = new Quad2D(1.0f, vector3(-11, -7, 5), Colors3f::Black, UserInput::isFalse, UsingRigidBody2D::non, ShowDetails::isFalse, vector3(0.6, 0.6, 0)/* Size*/);
GameObject* tableEdgeTop = new Quad2D(1.0f, vector3(0, 8, 5), Colors3f::Brown, UserInput::isFalse, UsingRigidBody2D::non, ShowDetails::isFalse, vector3(12, 0.3, 0)/* Size Lenght height width */);
GameObject* tableEdgeBottom = new Quad2D(1.0f, vector3(0, -8, 5), Colors3f::Brown, UserInput::isFalse, UsingRigidBody2D::non, ShowDetails::isFalse, vector3(12, 0.3, 0)/* Size Lenght height width */);
GameObject* tableEdgeLeft = new Quad2D(1.0f, vector3(12, 0, 5), Colors3f::Brown, UserInput::isFalse, UsingRigidBody2D::non, ShowDetails::isFalse, vector3(0.3, 8, 0)/* Size Lenght height width */);
GameObject* tableEdgeRight = new Quad2D(1.0f, vector3(-12, 0, 5), Colors3f::Brown, UserInput::isFalse, UsingRigidBody2D::non, ShowDetails::isFalse, vector3(0.3, 8, 0)/* Size Lenght height width */);




//GameObject* cue = new Quad2D(1.0f, vector3(0, 0, 5), Colors3f::White, UserInput::isFalse, UsingRigidBody2D::rectangle, ShowDetails::isFalse, vector3(8, 0.2, 0)/* Size*/);

GameObject* circle = new Circle(1.0f, vector3(0, 0, 0), Colors3f::Red, 0.5f ,UserInput::isFalse,UsingRigidBody2D::circle, ShowDetails::isFalse);


// 3D Objects That can use RigidBody3D Calculations
GameObject* cube = new Cube(1.0f, vector3(0, 0, 0), Colors3f::Red, UserInput::isFalse, UsingRigidBody3D::Cube, ShowDetails::isTrue);
GameObject* cone = new Cone(1.0f, vector3(1, -1, 0), Colors3f::Green, UserInput::isFalse, UsingRigidBody3D::non, ShowDetails::isFalse);


GameObject* quad2d = new Quad2D(1.0f, vector3(-2, 0, 0), Colors3f::Black, UserInput::isFalse, UsingRigidBody2D::non, ShowDetails::isTrue, vector3(0.6, 0.6, 0)/* Size*/);





GameObject* sphere = new Sphere(1.0f, vector3(0, -1, 0), Colors3f::Green, 0.5f, UserInput::isTrue, UsingRigidBody3D::SolidSphere, ShowDetails::isFalse);
GameObject* sphere1 = new Sphere(1.0f, vector3(0, 2, 0), Colors3f::Green, 0.5f, UserInput::isFalse, UsingRigidBody3D::non, ShowDetails::isFalse);

GameObject* sphere3 = new Sphere(1.0f, vector3(0, 5, 0), Colors3f::Green, 0.5f, UserInput::isFalse, UsingRigidBody3D::SolidSphere, ShowDetails::isFalse);
GameObject* sphere4 = new Sphere(1.0f, vector3(2, 0, 0), Colors3f::Green, 0.5f, UserInput::isFalse, UsingRigidBody3D::non, ShowDetails::isFalse);



/* !!! If you want to See rigidBody in action Attach them to an Object Instead. !!!*/
GameObject* rigidbody2d = new RigidBody2D(1.0f, vector3(2, 0, 0), Colors3f::Orange, UsingRigidBody2D::rectangle); // Only Use this For Testing Purposes !!
GameObject* rigidbody3d = new RigidBody3D(1.0f, vector3(0, 0, 0), Colors3f::Orange, UsingRigidBody3D::SolidSphere); // Only Use this For Testing Purposes !!


GameObject* particle = new Particle(1.0f, vector3(0, 0, 0), Colors3f::Black, 0.5f, UserInput::isFalse, ShowDetails::isFalse); // Default Linear Motion



GameEngine Engine;

/* GLUT runs a Console Application Beginning from Main()*/
int main(int argc, char** argv)
{
	Engine.InitEngine(argc, argv, "9032499 Pool Game", 500, 500);

	// Push Back Objects (Initialize)
	//Engine.AddGameObject(particle);

	/* Pool Table Initialization */
	Engine.AddPoolTableObject(table);
	Engine.AddPoolTableObject(hole1);
	Engine.AddPoolTableObject(hole2);
	Engine.AddPoolTableObject(hole3);
	Engine.AddPoolTableObject(hole4);
	Engine.AddPoolTableObject(hole5);
	Engine.AddPoolTableObject(hole6);
	Engine.AddPoolTableObject(tableEdgeTop);
	Engine.AddPoolTableObject(tableEdgeBottom);
	Engine.AddPoolTableObject(tableEdgeLeft);
	Engine.AddPoolTableObject(tableEdgeRight);

	/* Rest of objects */
	//Engine.AddGameObject(cube);
	//Engine.AddGameObject(rigidbody2d);

	/* Collison Only works If only Spheres are in the Scene.  " MAKE A NEW VECTOR OBJECT for COLLISON OBJECT  SPHERE TO SPHERE COLLISION !!*/
	Engine.AddGameObject(sphere);
	Engine.AddGameObject(sphere1);
	Engine.AddGameObject(sphere3);
	Engine.AddGameObject(sphere4);

	Engine.AddGameObject(quad2d);
	Engine.AddGameObject(circle);

	//Engine.AddGameObject(rigidbody3d);

	Engine.StartEngine();
	return 0;
}