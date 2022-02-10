#pragma once // allow C preprocessor to include a header file when it is needed and to ignore an #include directive otherwise
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <glm/glm.hpp>

class Cube
{
public:
	Cube(); // Default constructor
	Cube(glm::vec3 pos, glm::vec3 col); // Specified Constructor Initialz of the cube.

	~Cube();
	void Draw();

private:
	glm::vec3 position;
	glm::vec3 color; /* Color codes https://pemavirtualhub.wordpress.com/2016/06/20/opengl-color-codes/ */
};