#pragma once

class Collider
{
    float mXMin, mYMin;
    float mXMax, mYMax;

public:

    static bool IsColliding(const Collider& c1, const Collider& c2);

    void Set(float xMin, float yMin, float xMax, float yMax);

    float GetXMin() const { return mXMin; }
    float GetYMin() const { return mYMin; }
    float GetXMax() const { return mXMax; }
    float GetYMax() const { return mYMax; }
};