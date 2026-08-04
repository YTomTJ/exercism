#pragma once
#include <string>

namespace date_independent
{
    class clock
    {
    public:
        static clock at(int hour, int minute);

        clock plus(int minutes);
        explicit operator std::string() const;
        bool operator==(const clock &other) const;
        bool operator!=(const clock &other) const;

    private:
        clock(int hour, int minute);

        int m_hour;
        int m_minute;
    };

} // namespace date_independent
