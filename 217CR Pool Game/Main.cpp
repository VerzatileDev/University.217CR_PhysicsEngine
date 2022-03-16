#pragma comment(lib, "glew32.lib") 

//System Libraries
#include <vector> //For game Object list

// Resource Files
#include "Color_Utils.h" // Defines Usable color3f / color4f

//Class Defined lib
#include "Cube.h"
#include "Sphere.h"
#include "Cone.h"
#include "Particle.h"
#include "Quad2D.h"
#include "RigidBody2D.h"

/* Game Clock ( DeltaTime ) */
int oldTimeSinceStart;
int newTimeSinceStart;

/* Game Objects */
std::vector<GameObject*> objects;

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


void displayScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity(); // Replaces Current matrix with Identity matrix < https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/glLoadIdentity.xml >
	gluLookAt(0.0, 0.0, -10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // Position objects for viewing.


	// DRAW GAMEOBJECTS After Push Back
	for (int i = 0; i < objects.size(); ++i)
	{
		objects[i]->Draw();
	}
	
	
	glutSwapBuffers();
}

void setup(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	/* ( Initialize OBJECTS ) */
	objects.push_back(quad);
	//objects.push_back(cube);
	//objects.push_back(cube1);
	//objects.push_back(sphere);
	//objects.push_back(cone);
	objects.push_back(particle);
	//objects.push_back(rigidbody2d);
}

// Set Layout of the Window Displayed.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (float)w / (float)h, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

// Get Input ACII Keys 
void keyInput(unsigned char key, int x, int y)
{
	GameObject::ACII_keyMap[key] = true;
	std::cout << "Key pressed: " << key << " : " << GameObject::ACII_keyMap[key] << std::endl; // Debug
	switch (key)
	{
	case 27:
		exit(0);
		break;
	case 'w':
		std::cout << "Using key: " << key << std::endl;
		break;
	case 's':
		std::cout << "Using key: " << key << std::endl;
		break;
	case 'a':
		std::cout << "Using key: " << key << std::endl;
		break;
	case 'd':
		std::cout << "Using key: " << key << std::endl;
		break;
	default:
		break;
	}
}
void keyInputRelease(unsigned char key, int x, int y)
{
	GameObject::ACII_keyMap[key] = false;
	std::cout << "Key pressed: " << key << " : " << GameObject::ACII_keyMap[key] << std::endl; // Debug
}

// Input Non- ACII keys
void keySpecialInput(int key, int x, int y)
{
	GameObject::NonACII_keyMap[key] = true;
	std::cout << "Key pressed: " << key << " : " << GameObject::NonACII_keyMap[key] << std::endl; // Debug
	switch (key)
	{
	case GLUT_KEY_UP:
		std::cout << "Using key: " << key << std::endl;
		break;
	case GLUT_KEY_DOWN:
		std::cout << "Using key: " << key << std::endl;
		break;
	case GLUT_KEY_LEFT:
		std::cout << "Using key: " << key << std::endl;
		break;
	case GLUT_KEY_RIGHT:
		std::cout << "Using key: " << key << std::endl;
		break;
	default:
		break;
	}
}
void keySpecialInputRelease(int key, int x, int y)
{
	GameObject::NonACII_keyMap[key] = false;
	std::cout << "Key pressed: " << key << " : " << GameObject::NonACII_keyMap[key] << std::endl;
}


void idle()
{
	oldTimeSinceStart = newTimeSinceStart;
	newTimeSinceStart = glutGet(GLUT_ELAPSED_TIME);

	//std::cout << " --------------------------- " << std::endl;
	//std::cout << "OldTimeSinceStart: " << oldTimeSinceStart << std::endl;
	//std::cout << "NewTimeSinceStart: " << newTimeSinceStart << std::endl;

	float deltaTime = (newTimeSinceStart - oldTimeSinceStart);
	//std::cout << "Delta Time (ms): " << deltaTime << std::endl;
	deltaTime /= 1000.f;
	//std::cout << "Delta Time (seconds): " << deltaTime << std::endl;
	//std::cout << " --------------------------- " << std::endl;

	// Updates objects position and details when defined within the class or enabled with initilization.
	for (int i = 0; i < objects.size(); ++i)
	{
		objects[i]->Update(deltaTime);
	}
	
	
	glutPostRedisplay(); // Marks Window to be ReDisplayed <information at<https://www.opengl.org/resources/libraries/glut/spec3/node20.html>>
}

void onExitProgram()
{
	// Cleans Up programs  Memory Loaded Objects when (Esc) key is called or Programs exits.
	std::cout << "Reclaiming Memory.. " << std::endl;
	for (int i = 0; i < objects.size(); ++i)
	{
		delete objects[i];
		std::cout << " Released Memory of object num: " <<  i + 1<< std::endl;
	}
}


/* GLUT runs a Console Application Beginning from Main()*/
int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitContextVersion(2, 0); //Selects OpenGl Version Requested when the Context of the Program is Created (Aimed to find compatible/ supported extensions for this version)
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE); // Makes Sure to Include Outdated profile functions and methods, other version to use is glut_core_profile.
	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); 
	/* <https://www.opengl.org/resources/libraries/glut/spec3/node12.html>
	   BitWise Xor " Sets the bit if it is set in one operand but not both "
	   Bit mask to select a double buffered window. This overrides GLUT_SINGLE if it is also specified.
	   Bit mask to select a window with a depth buffer.
	*/

	glutInitWindowSize(500, 500);              // Set The Windows Initial Width and Height
	glutInitWindowPosition(500, 200);          // Position Window Starting Top - Left Corner
	glutCreateWindow("9032499 Pool Game");     // Establish a Window with A given Title.
	glutDisplayFunc(displayScene);             // Register Display CallBack Handler for Window Contents.
	glutReshapeFunc(resize);                   // Called WhenEver The Window Is Reshaped (< https://www.opengl.org/resources/libraries/glut/spec3/node48.html >)
	glutKeyboardFunc(keyInput);                // Get ACII keys
	glutKeyboardUpFunc(keyInputRelease);       // Reset ACII keys pushed
	glutSpecialFunc(keySpecialInput);          // Get Non-ACII keys.
	glutSpecialUpFunc(keySpecialInputRelease); // Reset Non-ACII keys pushed
	glutIdleFunc(idle);                        // Performs Background Processing Taks or Animation, when Window is not Reciving any Events. 
											   //( Set Automatically, when Events are not Recived ) (< https://www.opengl.org/resources/libraries/glut/spec3/node63.html >)
	glewExperimental = GL_TRUE;
	glewInit();
	setup();                                   // Set Objects to the stack " Push - Back "

	atexit(onExitProgram);                     // Clean Memory On Exit of Program
	glutMainLoop();                            // Recalls everything inside to Main to be Reloaded 
	                                           //(Until a Stop in the program is called " Either Crash, Manual Exit With ACII key ESC (27)
}