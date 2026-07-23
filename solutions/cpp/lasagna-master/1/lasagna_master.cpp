#include <algorithm>
#include "lasagna_master.h"

namespace lasagna_master
{
    int preparationTime(std::vector<std::string> layers, int time)
    {
        return layers.size() * time;
    }

    amount quantities(std::vector<std::string> layers)
    {
        amount a{0, 0};
        for (int i = 0; i < layers.size(); ++i)
        {
            if (layers[i] == "noodles")
            {
                a.noodles += 50;
            }
            else if (layers[i] == "sauce")
            {
                a.sauce += 0.2;
            }
        }
        return a;
    }

    void addSecretIngredient(std::vector<std::string> &list1, const std::vector<std::string>& list2)
    {
        addSecretIngredient(list1, list2.back());
    }

    void addSecretIngredient(std::vector<std::string> &list1, const std::string& item)
    {
        list1.back() = item;
    }

    std::vector<double> scaleRecipe(std::vector<double> quantities, int portions)
    {
        std::vector<double> a(quantities);
        std::transform(quantities.begin(), quantities.end(), a.begin(), [&](auto a) {
            return a * portions / 2;
        });
        return a;
    }

} // namespace lasagna_master
