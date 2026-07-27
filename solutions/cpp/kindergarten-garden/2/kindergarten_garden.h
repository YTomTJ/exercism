#pragma once
#include <array>
#include <string>

namespace kindergarten_garden
{

    enum class Plants : char
    {
        clover = 'C',
        grass = 'G',
        violets = 'V',
        radishes = 'R',
    };

    std::array<kindergarten_garden::Plants, 4> plants(const std::string &, const std::string &);

} // namespace kindergarten_garden
