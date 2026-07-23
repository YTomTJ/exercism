#include "doctor_data.h"

heaven::Vessel::Vessel(std::string name, int gen)
    : Vessel(name, gen, star_map::System::Sol)
{
}

heaven::Vessel::Vessel(std::string name, int gen, star_map::System system)
    : my_name(name), generation(gen),
      current_system(system)
{
}

heaven::Vessel heaven::Vessel::replicate(std::string name)
{
    return heaven::Vessel(name, generation + 1);
}

void heaven::Vessel::make_buster()
{
    busters += 1;
}

bool heaven::Vessel::shoot_buster()
{
    if (busters > 0)
    {
        busters -= 1;
        return true;
    }
    return false;
}

std::string heaven::get_older_bob(const heaven::Vessel &v1, const heaven::Vessel &v2)
{
    return v1.generation <= v2.generation ? v1.my_name : v2.my_name;
}

bool heaven::in_the_same_system(const heaven::Vessel &v1, const heaven::Vessel &v2)
{
    return v1.current_system == v2.current_system;
}