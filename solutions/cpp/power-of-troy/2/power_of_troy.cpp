#include "power_of_troy.h"

namespace troy
{
    human::human()
        : possession(nullptr),
          own_power(nullptr),
          influenced_by(nullptr),
          power_intensity(0)
    {
    }

    human::~human()
    {
        if (influenced_by != nullptr && influenced_by->owner != nullptr)
        {
            influenced_by->owner->power_intensity -= 1;
        }
    }

    void give_new_artifact(human &man, std::string name)
    {
        man.possession = std::make_shared<artifact>(name);
    }

    void exchange_artifacts(std::shared_ptr<artifact> &a1, std::shared_ptr<artifact> &a2)
    {
        a1.swap(a2);
    }

    void manifest_power(human &man, std::string name)
    {
        auto p = std::make_shared<power>(name);
        p->owner = &man;
        man.own_power.swap(p);
        man.power_intensity += 1;
    }

    void use_power(human &h1, human &h2)
    {
        h2.influenced_by = h1.own_power;
        h1.power_intensity += 1;
    }

    int power_intensity(human &man)
    {
        return man.power_intensity;
    }

} // namespace troy
