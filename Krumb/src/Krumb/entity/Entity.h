#pragma once

namespace Krumb
{
    struct PlayerPos
    {
        float x;
        float y;
        float z;

        PlayerPos() : x(0), y(0), z(0) {}
        PlayerPos(float xyz) : x(xyz), y(xyz), z(xyz) {}
        PlayerPos(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
        PlayerPos(PlayerPos& other) : x(other.x), y(other.y), z(other.z) {}
        PlayerPos(const PlayerPos& other) : x(other.x), y(other.y), z(other.z) {}

        bool equals(PlayerPos& other)
        {
            return x == other.x && y == other.y && z == other.z;
        }
        bool equals(const PlayerPos& other)
        {
            return x == other.x && y == other.y && z == other.z;
        }

        bool operator==(PlayerPos& other) { return equals(other); }
        bool operator==(const PlayerPos& other) { return equals(other); }

        PlayerPos operator+(const PlayerPos& other)
        {
            PlayerPos retVal;
            retVal.x = x + other.x;
            retVal.y = y + other.y;
            retVal.z = z + other.z;
            return retVal;
        }

        PlayerPos operator-(const PlayerPos& other)
        {
            PlayerPos retVal;
            retVal.x = x - other.x;
            retVal.y = y - other.y;
            retVal.z = z - other.z;
            return retVal;
        }

        void operator+=(const PlayerPos& other)
        {
            x += other.x;
            y += other.y;
            z += other.z;
        }

        void operator-=(const PlayerPos& other)
        {
            x -= other.x;
            y -= other.y;
            z -= other.z;
        }

    };
}
