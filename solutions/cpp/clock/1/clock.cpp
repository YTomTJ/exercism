#include <sstream>
#include <iomanip>
#include "clock.h"

namespace date_independent
{
    clock::clock(int hour, int minute)
    {
        auto mm = hour * 60 + minute;
        while (mm < 0)
        {
            mm += 24 * 60;
        }
        m_minute = mm % 60;
        m_hour = ((mm / 60)) % 24;
    }

    clock clock::at(int hour, int minute)
    {
        return clock(hour, minute);
    }

    clock clock::plus(int minutes)
    {
        return clock(m_hour, m_minute + minutes);
    }

    clock::operator std::string() const
    {
        std::ostringstream oss;
        oss << std::setfill('0')
            << std::setw(2) << m_hour << ":"
            << std::setw(2) << m_minute;
        return oss.str();
    }

    bool clock::operator==(const clock &other) const
    {
        return m_hour == other.m_hour && m_minute == other.m_minute;
    }

    bool clock::operator!=(const clock &other) const
    {
        return !this->operator==(other);
    }

} // namespace date_independent
