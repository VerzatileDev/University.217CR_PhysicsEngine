#include <GL/glew.h>
#include <GL/freeglut.h> // Used for CallBacks - A Function that is executed after another function has finished executing.
#include <glm/glm.hpp>

#pragma comment(lib, "glew32.lib") 

#include "Cube.h"
#include "Sphere.h"
#include "Cone.h"
#include <vector> // FOr game Object list
#include <iostream>

/* Game Objects */
std::vector<GameObject*> objects; // List of Objects
GameObject* cube = new Cube(glm::vec3(0, 0, 0), glm::vec3(1.0, 0.0, 0.0));
GameObject* cube1 = new Cube(glm::vec3(0, 1, 0), glm::vec3(2.0, 1.0, 0.0));
GameObject* sphere = new Sphere(glm::vec3(0, -2, 0), glm::vec3(0.0, 1.0, 0.0));
GameObject* cone = new Cone(glm::vec3(1, -1, 0), glm::vec3(0.0, 1.0, 0.0));

void displayScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity(); // Replaces Current matrix with Identity matrix < https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/glLoadIdentity.xml >
	// Position the objects for viewing.
	gluLookAt(0.0, 0.0, -10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);


	// Quad Plane, 4 Points 
	glPushMatrix(); // <https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/glPushMatrix.xml> Push / Pop current matric stack
	glColor3f(1.0f, 0.0f, 1.0f); // Yellow
	glBegin(GL_QUADS); // Draw a plane element from the represented 4 point.
	glVertex3f(5, 5, 0);// top right
	glVertex3f(-5, 5, 0);// top left
	glVertex3f(-5, -2, -0);// bottom right
	glVertex3f(5, -2, -0);// bottom left
	glEnd();
	glPopMatrix(); // Pops the current matrix stack, replacing the current matrix with one below it on the stack..


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

	/* PUSH Back Objects */

	objects.push_back(cube);
	objects.push_back(cube1);
	objects.push_back(sphere);
	objects.push_back(cone);
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


// Input Non- ACII keys
void keySpecialInput(int key, int x, int y)
{
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


void idle()
{
	glutPostRedisplay(); // Marks Window to be ReDisplayed <information at<https://www.opengl.org/resources/libraries/glut/spec3/node20.html>>
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
	glutSpecialFunc(keySpecialInput); // Non- ACII keys.
	glutIdleFunc(idle); // Performs Background Processing Taks or Animation, when Window is not Reciving any Events. ( Set Automatically, when Events are not Recived ) (< https://www.opengl.org/resources/libraries/glut/spec3/node63.html >)

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop(); // Recalls everything inside to Main to be Reloaded (Until a Stop in the program is called " Either Crash, Manual Exit With ACII key ESC (27)
}