#include "Collider.h"

bool Collider::IsColliding(const Collider& c1, const Collider& c2)
{
    return (c1.mXMin <= c2.mXMax &&
            c1.mXMax >= c2.mXMin &&
            c1.mYMin <= c2.mYMax &&
            c1.mYMax >= c2.mYMin);
}
