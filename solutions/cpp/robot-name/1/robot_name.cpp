#include "robot_name.h"

namespace robot_name
{
    static size_t nn = 0;

    robot::robot()
    {
        reset();
    }

    std::string robot::name() const
    {
        return m_name;
    }

    void robot::reset()
    {
        m_name = "00000";
        m_name[0] = (nn / 26000) + 'A';
        m_name[1] = ((nn % 26000) / 1000) + 'A';
        m_name[2] = ((nn % 1000) / 100) + '0';
        m_name[3] = ((nn % 100) / 10) + '0';
        m_name[4] = (nn % 10) + '0';
        nn++;
    }

} // namespace robot_name
