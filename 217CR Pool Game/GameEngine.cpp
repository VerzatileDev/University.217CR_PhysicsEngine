#include "GameEngine.h"
std::vector<GameObject*> GameEngine::objects;
static int oldTimeSinceStart;
static int newTimeSinceStart;

void GameEngine::StartEngine(void)
{
	// Recalls everything inside to Main to be Reloaded (Until a Stop in the program is called " Either Crash, Manual Exit With ACII key ESC (27)
	std::cout << " Press `ESC` To Exit (Close) the Game" << std::endl;
	glutMainLoop();
}

void GameEngine::InitEngine(int argc, char** argv, const char* windowTitle, int width, int height)
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

	glutInitWindowSize(1280, 720);		       // Width Height " Size Of the Window Displayed "
	glutInitWindowPosition(200, 100);          // Location of the Window Being Displayed Starting From Top left Corner "
	glutCreateWindow(windowTitle);			   // Establish a Window with A given Title.
	glewExperimental = GL_TRUE;
	glewInit();
	glutDisplayFunc(DisplayScene);             // Register Display CallBack Handler for Window Contents.
	
	// Called WhenEver The Window Is Reshaped (< https://www.opengl.org/resources/libraries/glut/spec3/node48.html >)
	glutReshapeFunc([](int w, int h)
		{
			glViewport(0, 0, w, h);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(60.0, (float)w / (float)h, 1.0, 500.0);
			glMatrixMode(GL_MODELVIEW);
		}
	);
	
	// Performs Background Processing Taks or Animation, when Window is not Reciving any Events.
	//( Set Automatically, when Events are not Recived ) (< https://www.opengl.org/resources/libraries/glut/spec3/node63.html >)
	glutIdleFunc(UpdateGame);

	// Get ACII keys
	glutKeyboardFunc([](unsigned char key, int x, int y)
	{
		GameObject::ACII_keyMap[key] = true;
		//std::cout << "Key pressed: " << key << " : " << GameObject::ACII_keyMap[key] << std::endl; // Debug
		switch (key)
		{
		case 27:
			exit(0);
			break;
		case 'w':
			//std::cout << "Using key: " << key << std::endl;
			break;
		case 's':
			//std::cout << "Using key: " << key << std::endl;
			break;
		case 'a':
			//std::cout << "Using key: " << key << std::endl;
			break;
		case 'd':
			//std::cout << "Using key: " << key << std::endl;
			break;
		default:
			break;
		}
	});

	// Reset ACII keys pushed
	glutKeyboardUpFunc([](unsigned char key, int x, int y)
	{
		GameObject::ACII_keyMap[key] = false;
		//std::cout << "Key pressed: " << key << " : " << GameObject::ACII_keyMap[key] << std::endl; // Debug
	});

	// Get Non-ACII keys.
	glutSpecialFunc([](int key, int x, int y)
	{
		GameObject::NonACII_keyMap[key] = true;
		//std::cout << "Key pressed: " << key << " : " << GameObject::NonACII_keyMap[key] << std::endl; // Debug
		switch (key)
		{
		case GLUT_KEY_UP:
			//std::cout << "Using key: " << key << std::endl;
			break;
		case GLUT_KEY_DOWN:
			//std::cout << "Using key: " << key << std::endl;
			break;
		case GLUT_KEY_LEFT:
			//std::cout << "Using key: " << key << std::endl;
			break;
		case GLUT_KEY_RIGHT:
			//std::cout << "Using key: " << key << std::endl;
			break;
		default:
			break;
		}
	});

	// Reset Non-ACII keys pushed
	glutSpecialUpFunc([](int key, int x, int y)
	{
		GameObject::NonACII_keyMap[key] = false;
		//std::cout << "Key pressed: " << key << " : " << GameObject::NonACII_keyMap[key] << std::endl;
	});
	
	// Clean Memory On Exit of Program
	atexit([]
	{
		// Cleans Up programs  Memory Loaded Objects when (Esc) key is called or Programs exits.
		std::cout << "Reclaiming Memory.. " << std::endl;
		for (int i = 0; i < objects.size(); ++i)
		{
			delete objects[i];
			std::cout << "Released Memory of object num: " << i + 1 << std::endl;
		}
		std::cout << "\n! Reclaiming Memory Complete ! " << std::endl;
	});
}

void GameEngine::DisplayScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0, 0.0, 1.0, 0.0); // Set Background Color Dark Blue
	glLoadIdentity(); // Replaces Current matrix with Identity matrix < https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/glLoadIdentity.xml >
	gluLookAt(0.0, 0.0, -10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);// Position the objects for viewing.

	// DRAW GAMEOBJECTS After Push Back
	for (int i = 0; i < objects.size(); ++i)
	{
		objects[i]->Draw();
	}

	glutSwapBuffers();
}

void GameEngine::UpdateGame(void)
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




	// -----------Collision Check here -----------
	
	// Get Object[i] and object[2]
	// Send them to SphereCollider::CollisionCheck


	

	for (int i = 1; i < objects.size(); ++i) // Change this to Collision Objects Instead..
	{
		/* Objects can Only access shared data from between object and gameobject class */
		/* SPHERE ON SPHERE COLLISION CHECK  " CURRENTLY INCLUDES ALL OTHER OBJECT THAT HAVE NO COLLISION !*/
		glm::vec3 tempposition1 = objects[0]->position; // PLAYER object This Means The Check Only happens Between first Object and the Rest
		glm::vec3 tempposition2 = objects[i]->position;

		float tempRadius1 = objects[0]->radius;
		float tempRadius2 = objects[i]->radius;

		

		std::cout << "Radius of object "<< i << " Its Radius is : " << objects[i]->radius << std::endl; // Debug

		bool value = SphereCollider::CollisionCheck(tempposition1, tempposition2, tempRadius1, tempRadius2);
		if (value == true)
		{
			std::cout << "Collision with" << " object Number " << i << std::endl; // Debug
			
			objects[i]->color = Colors3f::Magenta; // Collision Detected
		}
		else objects[i]->color = Colors3f::Green; // No collision detected


	}





	// Updates objects position and details when defined within the class or enabled with initilization.
	for (int i = 0; i < objects.size(); ++i)
	{
		objects[i]->Update(deltaTime);
		
	}

	//---------- If there was Collision DoCollision here..----


	// Marks Window to be ReDisplayed <information at<https://www.opengl.org/resources/libraries/glut/spec3/node20.html>>
	glutPostRedisplay();
}

void GameEngine::AddGameObject(GameObject* object)
{
	objects.push_back(object);
}