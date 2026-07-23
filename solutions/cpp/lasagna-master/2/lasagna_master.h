#pragma once

#include <vector>
#include <string>

namespace lasagna_master
{

    struct amount
    {
        int noodles;
        double sauce;
    };

    int preparationTime(std::vector<std::string> layers, int time = 2);

    amount quantities(std::vector<std::string> layers);

    void addSecretIngredient(std::vector<std::string> &list1, const std::vector<std::string> &list2);

    void addSecretIngredient(std::vector<std::string> &list1, const std::string &item);

    std::vector<double> scaleRecipe(std::vector<double> quantities, int portions);

} // namespace lasagna_master
