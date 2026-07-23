#include <map>
#include "allergies.h"

std::map<std::string, int> allergen_types = {
    {"eggs", 1},
    {"peanuts", 2},
    {"shellfish", 4},
    {"strawberries", 8},
    {"tomatoes", 16},
    {"chocolate", 32},
    {"pollen", 64},
    {"cats", 128},
};

allergies::allergy_info::allergy_info(int allergens)
{
    for (const auto &item : allergen_types)
    {
        if ((allergens & item.second) == item.second)
        {
            m_allergens.emplace(item.first);
        }
    }
}

bool allergies::allergy_info::is_allergic_to(const std::string &allergen)
{
    return std::find(m_allergens.begin(), m_allergens.end(), allergen) != m_allergens.end();
}

const std::unordered_set<std::string> &allergies::allergy_info::get_allergies() const
{
    return m_allergens;
}

allergies::allergy_info allergies::allergy_test(int allergens)
{
    return allergy_info(allergens);
}
