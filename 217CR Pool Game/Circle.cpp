#include "Circle.h"

void Circle::Draw()
{
	glPushMatrix();
	glTranslatef(position.x, position.y, position.z); // Position / Location
	int i, x, y;
	double radius = 1.30; // Size
	glColor3f(color.x, color.y, color.z);  // Color
	double twicePi = 2.0 * 3.142; // Calculate Pi""2
	x = 0, y = 0;
	glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
	glVertex2f(x, y); // center of circle
	for (i = 0; i <= 20; i++) {
		glVertex2f(
			(x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20)))
		);
	}
	glEnd(); //END
	glPopMatrix();
	// Reference https://stackoverflow.com/questions/22444450/drawing-circle-with-opengl

	/* In Case it is Nessecary to Use Lined Circle " Not Filled one "  Positions are " x + 0 "  change 0 depending where we required the location .. */
	//glPushMatrix();
	//glBegin(GL_LINE_LOOP);
	//for (int ii = 0; ii < 30; ii++) {
	//	float theta = 2.0f * 3.1415926f * float(ii) / float(30);//get the current angle 
	//	float x = 2 * cosf(theta);//calculate the x component 
	//	float y = 2 * sinf(theta);//calculate the y component 
	//	glVertex2f(x + 0, y + 0);//output vertex 
	//}
	//glEnd();
	//glPopMatrix();
}

Circle::Circle()
{}

Circle::Circle(float mas, vector3 pos, vector3 col) : GameObject(mas, pos, col)
{}

Circle::~Circle()
{}