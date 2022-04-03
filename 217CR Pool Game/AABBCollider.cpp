#include "AABBCollider.h"

bool AABBCollider::CollisionCheck(glm::vec3 position1, glm::vec3 position2, float object1Width, float object2Width, float object1Height, float object2Height)
{
    bool collision = false;

    // No Rotation Formula
    if (position1.x < position2.x + object2Width && position1.x + object1Width > position2.x && position1.y < position2.y + object2Height && object1Height + position1.y > position2.y)
    {
        collision = true; // If there is collision change color in GameEngine.cpp Update
    }
    else collision = false; // If there is collision keep or change color in GameEngine.cpp Update either back to original or new.

    // Reference  1 https://developer.mozilla.org/en-US/docs/Games/Techniques/3D_collision_detection
    // Reference  2  http://www.r-5.org/files/books/computers/algo-list/realtime-3d/Christer_Ericson-Real-Time_Collision_Detection-EN.pdf
    return collision;
}

AABBCollider::AABBCollider(vector3 AABBColliderPos, vector3 AABBColliderCol, float width, float height)
{
}

AABBCollider::AABBCollider()
{
}

AABBCollider::~AABBCollider()
{
}

void AABBCollider::Draw()
{

}