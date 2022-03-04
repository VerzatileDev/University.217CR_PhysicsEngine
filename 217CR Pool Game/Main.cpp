#pragma comment(lib, "glew32.lib") 

#include <vector> //for game Object list
#include <iostream>

#include "Cube.h"
#include "Sphere.h"
#include "Cone.h"
#include "Particle.h"
#include "Quad2D.h"


/* Game Clock ( DeltaTime ) */
int oldTimeSinceStart;
int newTimeSinceStart;

/* Game Objects */
std::vector<GameObject*> objects; // List of Objects

GameObject* quad = new Quad2D(glm::vec3(0, 0, 0), glm::vec3(1.0f, 2.0f, 1.0f)); // white
GameObject* cube = new Cube(glm::vec3(0, 0, 0), glm::vec3(1.0, 0.0, 0.0));
GameObject* cube1 = new Cube(glm::vec3(0, 1, 0), glm::vec3(2.0, 1.0, 0.0));
GameObject* sphere = new Sphere(glm::vec3(0, -2, 0), glm::vec3(0.0, 1.0, 0.0));
GameObject* cone = new Cone(glm::vec3(1, -1, 0), glm::vec3(0.0, 1.0, 0.0)); // position, color
GameObject* particle = new Particle(1.0f, glm::vec3(0, 0, 0), glm::vec3(0.0, 1.0, 0.0)); // Mass, position, color

void displayScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity(); // Replaces Current matrix with Identity matrix < https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/glLoadIdentity.xml >
	// Position the objects for viewing.
	gluLookAt(0.0, 0.0, -10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	// DRAW GAMEOBJECTS from list After Push Back
	for (int i = 0; i < objects.size(); ++i)
	{
		objects[i]->Draw();
	}

	glutSwapBuffers();
}

void setup(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);

	/* PUSH Back Objects  ( Initialize )*/

	objects.push_back(quad);
	//objects.push_back(cube);
	//objects.push_back(cube1);
	//objects.push_back(sphere);
	//objects.push_back(cone);
	objects.push_back(particle);
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
	GameObject::NonACII_keyMap[key] = true; //Map Key use
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


	for (int i = 0; i < objects.size(); ++i)
	{
		objects[i]->Update(deltaTime); // Hard code deltaTime
	}
	glutPostRedisplay(); // Marks Window to be ReDisplayed <information at<https://www.opengl.org/resources/libraries/glut/spec3/node20.html>>
}

void onExitProgram()
{
	// CleanUp Code at the End of the Program when Exit is called.. 
	std::cout << "Reclaiming Memory.. " << std::endl;
	for (int i = 0; i < objects.size(); ++i)
	{
		delete objects[i];
	}
}

/* GLUT runs a Console Application Beginning from Main()*/
int main(int argc, char** argv)
{
	glutInit(&argc, argv);  //Initialize GLUT

	glutInitContextVersion(2, 0); // Function Selects, Which OpenGl Version Is Requested when the Context of the Program is Created (Aims to find compatible/ supported extensions for this version)
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE); // Makes Sure to Include Outdated profile functions and methods, other version to use is glut_core_profile.
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); // BitWise Xor  " Sets the bit if it is set in one operand but not both "
	/* <https://www.opengl.org/resources/libraries/glut/spec3/node12.html>
	Bit mask to select a double buffered window. This overrides GLUT_SINGLE if it is also specified.
	Bit mask to select a window with a depth buffer.*/

	glutInitWindowSize(500, 500); // Set The Windows Initial Width and Height
	glutInitWindowPosition(500, 200); // Position Window Starting Top - Left Corner
	glutCreateWindow("9032499 Pool Game"); // Establish a Window with A given Title.
	glutDisplayFunc(displayScene); // Register Display CallBack Handler for Window Contents.
	glutReshapeFunc(resize); // Called WhenEver The Window Is Reshaped (< https://www.opengl.org/resources/libraries/glut/spec3/node48.html >)
	glutKeyboardFunc(keyInput); // Recive Key Input from The User for ACII keys - Maps.
	glutKeyboardUpFunc(keyInputRelease);
	glutSpecialFunc(keySpecialInput); // Non- ACII keys.
	glutSpecialUpFunc(keySpecialInputRelease);
	glutIdleFunc(idle); // Performs Background Processing Taks or Animation, when Window is not Reciving any Events. ( Set Automatically, when Events are not Recived ) (< https://www.opengl.org/resources/libraries/glut/spec3/node63.html >)

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	atexit(onExitProgram); // Called on Exit ( Initialized to before exit is called / made ready to be called "")
	glutMainLoop(); // Recalls everything inside to Main to be Reloaded (Until a Stop in the program is called " Either Crash, Manual Exit With ACII key ESC (27)
	
}