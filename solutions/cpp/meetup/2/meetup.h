#pragma once
#include <boost/date_time/gregorian/gregorian.hpp>

using date_t = boost::gregorian::date;
using namespace boost::date_time;

namespace meetup
{
    class scheduler
    {
    public:
        scheduler(months_of_year m, int year);

        date_t first_monday() const;
        date_t second_monday() const;
        date_t third_monday() const;
        date_t fourth_monday() const;
        date_t last_monday() const;
        date_t monteenth() const;

        date_t first_tuesday() const;
        date_t second_tuesday() const;
        date_t third_tuesday() const;
        date_t fourth_tuesday() const;
        date_t last_tuesday() const;
        date_t tuesteenth() const;

        date_t first_wednesday() const;
        date_t second_wednesday() const;
        date_t third_wednesday() const;
        date_t fourth_wednesday() const;
        date_t last_wednesday() const;
        date_t wednesteenth() const;

        date_t first_thursday() const;
        date_t second_thursday() const;
        date_t third_thursday() const;
        date_t fourth_thursday() const;
        date_t last_thursday() const;
        date_t thursteenth() const;

        date_t first_friday() const;
        date_t second_friday() const;
        date_t third_friday() const;
        date_t fourth_friday() const;
        date_t last_friday() const;
        date_t friteenth() const;

        date_t first_saturday() const;
        date_t second_saturday() const;
        date_t third_saturday() const;
        date_t fourth_saturday() const;
        date_t last_saturday() const;
        date_t saturteenth() const;

        date_t first_sunday() const;
        date_t second_sunday() const;
        date_t third_sunday() const;
        date_t fourth_sunday() const;
        date_t last_sunday() const;
        date_t sunteenth() const;

    private:
        date_t find(weekdays wd, int index) const;

        const date_t m_base;
    };

} // namespace meetup
