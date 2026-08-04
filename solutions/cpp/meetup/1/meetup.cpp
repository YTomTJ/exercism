#include "meetup.h"

using namespace boost::gregorian;

namespace meetup
{
    scheduler::scheduler(months_of_year m, int year)
        : m_base(year, m, 1)
    {
    }

    date_t scheduler::find(weekdays wd, int index) const
    {
        auto base = m_base;
        if (index > 0)
        {
            while (true)
            {
                base = boost::gregorian::next_weekday(base, greg_weekday(wd));
                index--;
                if (index <= 0)
                {
                    return base;
                }
                base = base + days(1);
            }
        }
        else if (index < 0)
        {
            auto _base = base;
            while (true)
            {
                if (_base.month() != m_base.month() || _base.year() != m_base.year())
                {
                    return base;
                }
                base = _base;
                _base = boost::gregorian::next_weekday(base + days(1), greg_weekday(wd));
            }
        }
        else if (index == 0)
        {
            while (true)
            {
                base = boost::gregorian::next_weekday(base, greg_weekday(wd));
                if (13 <= base.day() && base.day() <= 19)
                {
                    return base;
                }
                base = base + days(1);
            }
        }
        return base;
    }

    date_t scheduler::first_monday() const
    {
        return find(weekdays::Monday, 1);
    }
    date_t scheduler::second_monday() const
    {
        return find(weekdays::Monday, 2);
    }
    date_t scheduler::third_monday() const
    {
        return find(weekdays::Monday, 3);
    }
    date_t scheduler::fourth_monday() const
    {
        return find(weekdays::Monday, 4);
    }
    date_t scheduler::last_monday() const
    {
        return find(weekdays::Monday, -1);
    }
    date_t scheduler::monteenth() const
    {
        return find(weekdays::Monday, 0);
    }

    date_t scheduler::first_tuesday() const
    {
        return find(weekdays::Tuesday, 1);
    }
    date_t scheduler::second_tuesday() const
    {
        return find(weekdays::Tuesday, 2);
    }
    date_t scheduler::third_tuesday() const
    {
        return find(weekdays::Tuesday, 3);
    }
    date_t scheduler::fourth_tuesday() const
    {
        return find(weekdays::Tuesday, 4);
    }
    date_t scheduler::last_tuesday() const
    {
        return find(weekdays::Tuesday, -1);
    }
    date_t scheduler::tuesteenth() const
    {
        return find(weekdays::Tuesday, 0);
    }

    date_t scheduler::first_wednesday() const
    {
        return find(weekdays::Wednesday, 1);
    }
    date_t scheduler::second_wednesday() const
    {
        return find(weekdays::Wednesday, 2);
    }
    date_t scheduler::third_wednesday() const
    {
        return find(weekdays::Wednesday, 3);
    }
    date_t scheduler::fourth_wednesday() const
    {
        return find(weekdays::Wednesday, 4);
    }
    date_t scheduler::last_wednesday() const
    {
        return find(weekdays::Wednesday, -1);
    }
    date_t scheduler::wednesteenth() const
    {
        return find(weekdays::Wednesday, 0);
    }

    date_t scheduler::first_thursday() const
    {
        return find(weekdays::Thursday, 1);
    }
    date_t scheduler::second_thursday() const
    {
        return find(weekdays::Thursday, 2);
    }
    date_t scheduler::third_thursday() const
    {
        return find(weekdays::Thursday, 3);
    }
    date_t scheduler::fourth_thursday() const
    {
        return find(weekdays::Thursday, 4);
    }
    date_t scheduler::last_thursday() const
    {
        return find(weekdays::Thursday, -1);
    }
    date_t scheduler::thursteenth() const
    {
        return find(weekdays::Thursday, 0);
    }

    date_t scheduler::first_friday() const
    {
        return find(weekdays::Friday, 1);
    }
    date_t scheduler::second_friday() const
    {
        return find(weekdays::Friday, 2);
    }
    date_t scheduler::third_friday() const
    {
        return find(weekdays::Friday, 3);
    }
    date_t scheduler::fourth_friday() const
    {
        return find(weekdays::Friday, 4);
    }
    date_t scheduler::last_friday() const
    {
        return find(weekdays::Friday, -1);
    }
    date_t scheduler::friteenth() const
    {
        return find(weekdays::Friday, 0);
    }

    date_t scheduler::first_saturday() const
    {
        return find(weekdays::Saturday, 1);
    }
    date_t scheduler::second_saturday() const
    {
        return find(weekdays::Saturday, 2);
    }
    date_t scheduler::third_saturday() const
    {
        return find(weekdays::Saturday, 3);
    }
    date_t scheduler::fourth_saturday() const
    {
        return find(weekdays::Saturday, 4);
    }
    date_t scheduler::last_saturday() const
    {
        return find(weekdays::Saturday, -1);
    }
    date_t scheduler::saturteenth() const
    {
        return find(weekdays::Saturday, 0);
    }

    date_t scheduler::first_sunday() const
    {
        return find(weekdays::Sunday, 1);
    }
    date_t scheduler::second_sunday() const
    {
        return find(weekdays::Sunday, 2);
    }
    date_t scheduler::third_sunday() const
    {
        return find(weekdays::Sunday, 3);
    }
    date_t scheduler::fourth_sunday() const
    {
        return find(weekdays::Sunday, 4);
    }
    date_t scheduler::last_sunday() const
    {
        return find(weekdays::Sunday, -1);
    }
    date_t scheduler::sunteenth() const
    {
        return find(weekdays::Sunday, 0);
    }

} // namespace meetup
