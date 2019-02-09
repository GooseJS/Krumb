#pragma once

#include "Krumb/entity/Entity.h"
#include "Krumb/render/Camera.h"

namespace Krumb
{
    struct PlayerMovement
    {
        bool moveForwardPressed;
        bool moveBackPressed;
        bool moveLeftPressed;
        bool moveRightPressed;
        bool moveUpPressed;
        bool moveDownPressed;
    };

    class Player
    {
        private:
           PlayerPos _pos;

           float _moveSpeed;

           Camera _playerCamera;

        public:
           Player();

           void handleMovementInput(const PlayerMovement& movement);
           void handleRotationInput(const float& rotX, const float& rotY);

           inline float getX() { return _pos.x; }
           inline float getY() { return _pos.y; }
           inline float getZ() { return _pos.z; }
           inline Camera& getPlayerCamera() { return _playerCamera; }
    };
}
