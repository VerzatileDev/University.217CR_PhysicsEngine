#include "Point.h"

void Point::Draw()
{
	// Displays A Point on the Object making it easier to see rotation.
	glPointSize(size);
	glColor3f(pointColor.x, pointColor.y, pointColor.z);
	glBegin(GL_POINTS);
	glVertex3f(pointLocation.x, pointLocation.y, pointLocation.z); // Location of the Point From the Centre Updated With Object Rotation etc.
	glEnd();
	// glPopMatrix(); // <--- Enable When Nessecary Though on default referenced to calling it into other objects Try using Pop there instead.
}

void Point::Update(float deltaTime)
{}

Point::Point()
{}

Point::~Point()
{}