#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>

#pragma comment(lib, "glew32.lib") 

void displayScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity(); // Replaces Current matrix with Identity matrix < https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/glLoadIdentity.xml >

	// Position the objects for viewing.
	gluLookAt(0.0, 0.0, -10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	/* Color codes https://pemavirtualhub.wordpress.com/2016/06/20/opengl-color-codes/ */
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

	// black solid Cone
	glPushMatrix(); // Defines that new element is being used
	glColor3f(0.0, 0.0, 0.0); // black
	glTranslatef(-1, 0, 0); // Coordinate in world space
	glRotatef(-65, 1, 0, 0); // Angle,  (Specified Coordinates to start rotation around ) -> " x, y, z "
	glutSolidCone(0.5, 0.75, 30, 30); // Cone size
	glPopMatrix(); // Sets the Element 

	// Blue solid cone
	glPushMatrix();
	glColor3f(-2, 0, 2);
	glTranslatef(1, 0, 0);
	glRotatef(-65, 1, 0, 0);
	glutSolidCone(0.5, 0.75, 30, 30);
	glPopMatrix();

	// Cube
	glPushMatrix();
	glTranslatef(-3, 0, 0);
	glColor3f(1, 1, 1);
	glutSolidCube(0.8);
	glPopMatrix();

	glutSwapBuffers();
}

// Initialization routine.
void setup(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
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

// Get Input from ACII Keys 
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
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
	Bit mask to select a double buffered window. This overrides GLUT_SINGLE if it is also specified.
	Bit mask to select a window with a depth buffer.*/

	glutInitWindowSize(500, 500); // Set The Windows Initial Width and Height
	glutInitWindowPosition(500, 200); // Position Window Starting Top - Left Corner
	glutCreateWindow("9032499 Pool Game"); // Establish a Window with A given Title.
	glutDisplayFunc(displayScene); // Register Display CallBack Handler for Window Contents.
	glutReshapeFunc(resize); // Called WhenEver The Window Is Reshaped (< https://www.opengl.org/resources/libraries/glut/spec3/node48.html >)
	glutKeyboardFunc(keyInput); // Recive Key Input from The User for ACII keys - Maps.
	glutIdleFunc(idle); // Performs Background Processing Taks or Animation, when Window is not Reciving any Events. ( Set Automatically, when Events are not Recived ) (< https://www.opengl.org/resources/libraries/glut/spec3/node63.html >)

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop(); // Recalls everything inside to Main to be Reloaded (Until a Stop in the program is called " Either Crash, Manual Exit With ACII key ESC (27)
}