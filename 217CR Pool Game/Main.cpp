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



// 3D Objects That can use RigidBody3D Calculations
//GameObject* cube = new Cube(1.0f, vector3(0, 0, 0), Colors3f::Red, UserInput::isFalse, UsingRigidBody3D::Cube, ShowDetails::isTrue);
//GameObject* cone = new Cone(1.0f, vector3(1, -1, 0), Colors3f::Green, UserInput::isFalse, UsingRigidBody3D::non, ShowDetails::isFalse);

// Billiard Balls // 
GameObject* player = new Sphere(1.0f, vector3(5, 0, 0), Colors3f::White, 0.2f, UserInput::isTrue, UsingRigidBody3D::SolidSphere, ShowDetails::isTrue);

GameObject* sphere1 = new Sphere(1.0f, vector3(-5, 2, 0), Colors3f::Red, 0.2f, UserInput::isFalse, UsingRigidBody3D::SolidSphere, ShowDetails::isFalse);
GameObject* sphere2 = new Sphere(1.0f, vector3(-5, 1.5, 0), Colors3f::Blue, 0.2f, UserInput::isFalse, UsingRigidBody3D::SolidSphere, ShowDetails::isFalse);
GameObject* sphere3 = new Sphere(1.0f, vector3(-5, 1, 0), Colors3f::Orange, 0.2f, UserInput::isFalse, UsingRigidBody3D::SolidSphere, ShowDetails::isFalse);
GameObject* sphere4 = new Sphere(1.0f, vector3(-5, 0.5, 0), Colors3f::Green, 0.2f, UserInput::isFalse, UsingRigidBody3D::SolidSphere, ShowDetails::isFalse);
GameObject* sphere5 = new Sphere(1.0f, vector3(-5, 0.0 , 0), Colors3f::Brown, 0.2f, UserInput::isFalse, UsingRigidBody3D::SolidSphere, ShowDetails::isFalse);


GameObject* sphere6 = new Sphere(1.0f, vector3(-4.5, 1.7, 0), Colors3f::Bronze, 0.2f, UserInput::isFalse, UsingRigidBody3D::SolidSphere, ShowDetails::isFalse);
GameObject* sphere7 = new Sphere(1.0f, vector3(-4.5, 1.2, 0), Colors3f::Black, 0.2f, UserInput::isFalse, UsingRigidBody3D::SolidSphere, ShowDetails::isFalse);
GameObject* sphere8 = new Sphere(1.0f, vector3(-4.5, 0.7, 0), Colors3f::White, 0.2f, UserInput::isFalse, UsingRigidBody3D::SolidSphere, ShowDetails::isFalse);
GameObject* sphere9 = new Sphere(1.0f, vector3(-4.5, 0.2, 0), Colors3f::Baby_Blue, 0.2f, UserInput::isFalse, UsingRigidBody3D::SolidSphere, ShowDetails::isFalse);


GameObject* sphere10 = new Sphere(1.0f, vector3(-4, 1.5, 0), Colors3f::Dark_Purple, 0.2f, UserInput::isFalse, UsingRigidBody3D::SolidSphere, ShowDetails::isFalse);
GameObject* sphere11 = new Sphere(1.0f, vector3(-4, 0.9, 0), Colors3f::Orange, 0.2f, UserInput::isFalse, UsingRigidBody3D::SolidSphere, ShowDetails::isFalse);
GameObject* sphere12 = new Sphere(1.0f, vector3(-4, 0.4, 0), Colors3f::Dark_Gray, 0.2f, UserInput::isFalse, UsingRigidBody3D::SolidSphere, ShowDetails::isFalse);

GameObject* sphere13 = new Sphere(1.0f, vector3(-3.5, 1.2, 0), Colors3f::Dark_Blue , 0.2f, UserInput::isFalse, UsingRigidBody3D::SolidSphere, ShowDetails::isFalse);
GameObject* sphere14 = new Sphere(1.0f, vector3(-3.5, 0.6, 0), Colors3f::Red, 0.2f, UserInput::isFalse, UsingRigidBody3D::SolidSphere, ShowDetails::isFalse);

GameObject* sphere15 = new Sphere(1.0f, vector3(-3, 0.8, 0), Colors3f::Violet, 0.2f, UserInput::isFalse, UsingRigidBody3D::SolidSphere, ShowDetails::isFalse);



/* !!! If you want to See rigidBody in action Attach them to an Object Instead. !!!*/
GameObject* rigidbody2d = new RigidBody2D(1.0f, vector3(2, 0, 0), Colors3f::Orange, UsingRigidBody2D::rectangle); // Only Use this For Testing Purposes !!
GameObject* rigidbody3d = new RigidBody3D(1.0f, vector3(0, 0, 0), Colors3f::Orange, UsingRigidBody3D::SolidSphere); // Only Use this For Testing Purposes !!


GameObject* circle = new Circle(1.0f, vector3(0, 0, 0), Colors3f::Red, 0.5f, UserInput::isFalse, UsingRigidBody2D::circle, ShowDetails::isFalse);
GameObject* quad2d = new Quad2D(1.0f, vector3(-2, 0, 0), Colors3f::Black, UserInput::isFalse, UsingRigidBody2D::rectangle, ShowDetails::isTrue, vector3(0.6, 0.6, 0)/* Size*/);
GameObject* particle = new Particle(1.0f, vector3(0, 0, 0), Colors3f::White, 0.5f, UserInput::isFalse, ShowDetails::isFalse); // Default Linear Motion


GameEngine Engine;

/* GLUT runs a Console Application Beginning from Main()*/
int main(int argc, char** argv)
{
	Engine.InitEngine(argc, argv, "9032499 Pool Game", 500, 500);

	// Push Back Objects (Initialize)

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

	/* Collison Only works If only Spheres are in the Scene.  " MAKE A NEW VECTOR OBJECT for COLLISON OBJECT  SPHERE TO SPHERE COLLISION !!*/
	Engine.AddGameObject(player); // User BALL 
	
	// Row 1
	Engine.AddGameObject(sphere1);
	Engine.AddGameObject(sphere2);
	Engine.AddGameObject(sphere3);
	Engine.AddGameObject(sphere4);
	Engine.AddGameObject(sphere5);

	// Row 2
	Engine.AddGameObject(sphere6);
	Engine.AddGameObject(sphere7);
	Engine.AddGameObject(sphere8);
	Engine.AddGameObject(sphere9);

	// Row 3
	Engine.AddGameObject(sphere10);
	Engine.AddGameObject(sphere11);
	Engine.AddGameObject(sphere12);

	// Row 4 
	Engine.AddGameObject(sphere13);
	Engine.AddGameObject(sphere14);

	// Row 5
	Engine.AddGameObject(sphere15);

	// Objects ShowCase
	Engine.AddGameObject(quad2d);
	Engine.AddGameObject(circle);
	Engine.AddGameObject(particle);
	

	//Engine.AddGameObject(rigidbody3d);

	Engine.StartEngine();
	return 0;
}