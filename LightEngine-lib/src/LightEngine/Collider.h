#pragma once

class Collider
{
    float mXMin, mYMin;
    float mXMax, mYMax;

public:

    static bool IsColliding(const Collider& c1, const Collider& c2);
};