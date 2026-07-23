#pragma once

#include <string>
#include <memory>

namespace troy
{
    class human;

    struct artifact
    {
        // constructors needed (until C++20)
        artifact(std::string name) : name(name) {}
        std::string name;
    };

    struct power
    {
        // constructors needed (until C++20)
        power(std::string effect) : effect(effect) {}
        std::string effect;

        human *owner = nullptr;
    };

    class human
    {
    public:
        std::shared_ptr<artifact> possession;
        std::shared_ptr<power> own_power;
        std::shared_ptr<power> influenced_by;
        int power_intensity;

    public:
        human();
        ~human();
    };

    void give_new_artifact(human &man, std::string name);
    void exchange_artifacts(std::shared_ptr<artifact> &a1, std::shared_ptr<artifact> &a2);
    void manifest_power(human &man, std::string name);
    void use_power(human &h1, human &h2);
    int power_intensity(human &man);

} // namespace troy
