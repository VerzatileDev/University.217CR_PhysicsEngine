#pragma once
#include "GameObject.h"
#include "Point.h"

class Particle : public GameObject, public Point
{
protected:
	bool UserInput;
	float radius = 0.9f;                          // Radius of the Particle " Hard Code "
private:
	/* Position & Mass From GameObject */
	vector3 LinearAcceleration = vector3(0, 0, 0);// Throttle on the object (The amount an object accelerates in its worldspace)
	vector3 LinearVelocity = vector3(0, 0, 0);    // Change of an Objects direction in regards to Time.
	vector3 LinearTotalForce = vector3(0, 0, 0);  // All the forces effecting the object.
	vector3 gravity = vector3(0, -1, 0);          // Earth's Gravity (-9.807) downwards Pull.
	vector3 FuturePosition = vector3(0, 0, 0);    // Future position of the object in the world map.
	vector3 wind = vector3(-0.2, 0, 0);           // Additional Force
	vector3 keyboardForce = vector3(0, 0, 0);     // Force Recived from Keyboard movement of the User
	
	// Calculation
	void CheckForKeyboard(float deltaTime);
	void CalculateForces();
	void CalculateVelocity(float deltaTime);
	void SetDisplacements(float deltaTime);

public:
	void Draw();
	void Update(float);
	Particle();
	Particle(float m, vector3 pos, vector3 col, bool KeyboardUse);
	~Particle();
};