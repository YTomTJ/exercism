#include "raindrops.h"

namespace raindrops
{
    std::string convert(int number)
    {
        bool m3 = (number % 3) == 0;
        bool m5 = (number % 5) == 0;
        bool m7 = (number % 7) == 0;
        if (m3 && m5 && m7)
            return "PlingPlangPlong";
        if (m3 && m5)
            return "PlingPlang";
        if (m3 && m7)
            return "PlingPlong";
        if (m5 && m7)
            return "PlangPlong";
        if (m3)
            return "Pling";
        if (m5)
            return "Plang";
        if (m7)
            return "Plong";
        return std::to_string(number);
    }

} // namespace raindrops
