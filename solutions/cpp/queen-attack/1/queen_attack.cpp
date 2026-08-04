#include <cmath>
#include <stdexcept>
#include "queen_attack.h"

namespace queen_attack
{
    chess_board::chess_board(step_t white, step_t black)
        : m_white(white), m_black(black)
    {
        if (white.first < 0 || white.first >= 8 || white.second < 0 || white.second >= 8)
        {
            throw std::domain_error("white out of board");
        }
        if (black.first < 0 || black.first >= 8 || black.second < 0 || black.second >= 8)
        {
            throw std::domain_error("black out of board");
        }
        if (white == black)
        {
            throw std::domain_error("distinct");
        }
    }

    step_t chess_board::white() const
    {
        return m_white;
    }

    step_t chess_board::black() const
    {
        return m_black;
    }

    bool chess_board::can_attack() const
    {
        auto dx = std::abs(m_white.first - m_black.first);
        auto dy = std::abs(m_white.second - m_black.second);
        return dx == 0 || dy == 0 || dx == dy;
    }

} // namespace queen_attack
