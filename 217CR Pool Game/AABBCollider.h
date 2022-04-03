#pragma once
#include "GameObject.h"

class AABBCollider
{
protected:
	// Position of Object 1 and 2
	//vector3 objectPosition1 = { 0,0,0 };
	//vector3 objectPosition2 = { 0,0,0 };

	// Dimensions of Quad2D
	//float objectWidth1;
	//float objectWidth2;
	//float objectHeight1;
	//float objectHeight2;
public:
	static bool CollisionCheck(glm::vec3 position1, glm::vec3 position2, float object1Width, float object2Width, float object1Height, float object2Height); //Collision Check returns boolean depending if the Collision happened or not.
	AABBCollider(vector3 AABBColliderPos, vector3 AABBColliderCol, float width, float height); // Constructor
	AABBCollider(); // deafault Constructor
	~AABBCollider(); // Destructor
	void Draw();

};