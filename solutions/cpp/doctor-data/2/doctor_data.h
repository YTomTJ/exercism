#include <string>

namespace star_map
{
    enum System
    {
        BetaHydri,
        Sol,
        EpsilonEridani,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani,
    };
}

namespace heaven
{
    class Vessel
    {
    public:
        std::string my_name;
        int generation;
        int current_system;
        int busters;

    public:
        Vessel(std::string, int);

        Vessel(std::string, int, star_map::System system);

        Vessel replicate(std::string name);

        void make_buster();

        bool shoot_buster();
    };

    std::string get_older_bob(const Vessel &v1, const Vessel &v2);

    bool in_the_same_system(const Vessel &v1, const Vessel &v2);
}