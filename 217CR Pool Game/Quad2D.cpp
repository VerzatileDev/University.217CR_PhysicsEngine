#include "Quad2D.h"

Quad2D::Quad2D()
{}

Quad2D::Quad2D(float mas, vector3 pos, vector3 col) : GameObject(mas, pos, col)
{}


Quad2D::~Quad2D()
{}

void Quad2D::Draw()
{
	// Quad Plane, 4 Points 
	glPushMatrix(); // <https://www.khronos.org/registry/OpenGL-Refpages/gl2.1/xhtml/glPushMatrix.xml> Push / Pop current matric stack
	glColor3f(color.x, color.y, color.z);
	glBegin(GL_QUADS); // Draw a plane element from the represented 4 point.
	glVertex3f(5, 5, 0); // top right
	glVertex3f(-5, 5, 0); // top left
	glVertex3f(-5, -5, -0); // bottom right
	glVertex3f(5, -5, -0); // bottom left
	glEnd();
	glPopMatrix(); // Pops the current matrix stack, replacing the current matrix with one below it on the stack..
}

void Quad2D::Update(float deltaTime)
{}