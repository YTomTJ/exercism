#include "darts.h"

namespace darts
{
    int score(float x, float y)
    {
        auto d2 = x * x + y * y;
        if (d2 <= 1)
            return 10;
        if (d2 <= 25)
            return 5;
        if (d2 <= 100)
            return 1;
        return 0;
    }

} // namespace darts
