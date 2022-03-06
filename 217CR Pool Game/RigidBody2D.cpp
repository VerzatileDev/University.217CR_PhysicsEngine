#include "RigidBody2D.h"


void RigidBody2D::Draw()
{
	glPushMatrix(); //dont affect other objects, only this one so take a copy of the matrix and put it on the stack
	glTranslatef(position.x, position.y, position.z); //then this happens
	glRotatef(orientation, 0, 0, 1); //this really happens first
	glColor3f(1.f, 1.f, 1.f);

	glBegin(GL_QUADS);
	glVertex3f(-length, width, 0); //top left
	glVertex3f(length, width, 0); //top right
	glVertex3f(length, -width, 0); //bottom right
	glVertex3f(-length, -width, 0); //bottom left
	glEnd();

	glPointSize(5.0f); // so we can see the point better

	glColor3f(0.f, 0.f, 0.f);
	glBegin(GL_POINTS);
	//at the middle of object
	glVertex3f(0, 0, 0);
	glEnd();
	glPopMatrix(); //forget about what we've done to this object so push off the stack - we are back to before the glPushMatrix() happened
}

void RigidBody2D::Update(float deltaTime)
{

}

RigidBody2D::RigidBody2D(float mas, vector3 pos, vector3 col) : GameObject(mas, pos, col)
{
	// Anything nessecary to be defined only for this class Add here
}

RigidBody2D::~RigidBody2D()
{}

// Rest Of the Methods / Functions.