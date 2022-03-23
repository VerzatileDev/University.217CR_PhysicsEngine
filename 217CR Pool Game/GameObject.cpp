#include "GameObject.h"

/* Key Value maps for ACII / NOn ACII*/
std::map<char, bool> GameObject::ACII_keyMap;
std::map<int, bool> GameObject::NonACII_keyMap;

GameObject::GameObject()
{}

GameObject::GameObject(float mas, vector3 pos, vector3 col) : Point()
{
	position = pos;
	color = col;
	mass = mas;
}

GameObject::~GameObject()
{}

void GameObject::Draw()
{}

void GameObject::Update(float deltaTime)
{}

void GameObject::renderBitmapString(float x, float y,float z, std::string str)
{
	glColor4f(1.0f, 0.0f, 0.0f, 0.0); // Color of the text displayed
	glRasterPos3f(x, y, z); // Provide position of the Text
	for (std::string::iterator c = (&str)->begin(); c != (&str)->end(); ++c)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *c); // Font and char displayed..
	}
	// Referencing to look up to these informations about the functioning of this
	// https://stackoverflow.com/questions/4917403/displaying-variables-in-glut Stackoverflow mentioning the Rendering of the text and use of fonts.
	// https://stackoverflow.com/questions/4826481/c-char-vs-string the difference between char* to string*
	// https://www.opengl.org/resources/libraries/glut/spec3/node76.html  glutBitmapCharacter
	// https://www.opengl.org/resources/libraries/glut/spec3/node76.html fonts 
	// https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/glRasterPos.xml RasterPos
	// -- Issue of Resize text when going far from frame -- https://stackoverflow.com/questions/12229329/drawing-bigger-text-using-glutbitmapcharacters
}
