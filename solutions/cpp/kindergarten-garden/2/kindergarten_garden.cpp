#include "kindergarten_garden.h"

namespace kindergarten_garden
{
    std::array<kindergarten_garden::Plants, 4> plants(const std::string &cups, const std::string &child)
    {
        const int n = child[0] - 'A';

        int split = 0;
        for (size_t i = 0; i < cups.size(); ++i)
        {
            if (cups[i] == '\n')
            {
                split = i;
                break;
            }
        }

        std::string line1 = cups.substr(0, split);
        std::string line2 = cups.substr(split + 1);
        return {
            (Plants)(line1[n * 2]),
            (Plants)(line1[n * 2 + 1]),
            (Plants)(line2[n * 2]),
            (Plants)(line2[n * 2 + 1]),
        };
    }

} // namespace kindergarten_garden
