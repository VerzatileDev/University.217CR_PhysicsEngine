#pragma comment(lib, "glew32.lib") 

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>
#include <GL/glut.h> //print text to openglwindow

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
#include "RigidBody3D.h"


class GameEngine
{
private:
	static std::vector<GameObject*> objects; // Store Objects to a vector list to be called and used.
	
	static void UpdateGame(void); //Each thing needs to be static
	static void DisplayScene(void); //Draw Game

public:
	static void InitEngine(int argc, char** argv, const char* windowTitle, int width, int height);
	static void AddGameObject(GameObject* object);// Push back Object to Scene
	static void StartEngine(void); // Start game
};