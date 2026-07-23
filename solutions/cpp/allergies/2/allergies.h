#pragma once
#include <string>
#include <unordered_set>

namespace allergies
{
    class allergy_info
    {
    public:
        allergy_info(int allergens);

        bool is_allergic_to(const std::string &allergen);

        const std::unordered_set<std::string> &get_allergies() const;

    private:
        std::unordered_set<std::string> m_allergens;
    };

    allergy_info allergy_test(int allergens);

} // namespace allergies
