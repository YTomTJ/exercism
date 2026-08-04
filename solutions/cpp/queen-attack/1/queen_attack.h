#pragma once
#include <utility>

using step_t = std::pair<int, int>;

namespace queen_attack
{
    class chess_board
    {
    public:
        chess_board(step_t white, step_t black);
        step_t white() const;
        step_t black() const;
        bool can_attack() const;

    private:
        const step_t m_white;
        const step_t m_black;
    };

} // namespace queen_attack
