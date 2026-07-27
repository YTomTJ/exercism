#include <cctype>
#include <vector>
#include "alphametics.h"

#include <iostream>

namespace alphametics
{
    std::optional<std::map<char, int>> solve(const std::string &problem)
    {
        std::map<char, int> map;

        std::vector<std::vector<char>> left;
        std::vector<char> right;
        for (int i = 0; i < problem.size(); ++i)
        {
            if (std::isalpha(problem[i]))
            {
                right.emplace_back(problem[i]);
                map[problem[i]] = 0;
            }
            else if (problem[i] == '+' || problem[i] == '=' || problem[i] == ' ')
            {
                if (right.size() > 0)
                {
                    left.push_back(right);
                    right.clear();
                }
            }
        }

        for (const auto &item : left)
        {
            std::string a(item.begin(), item.end());
            std::cout << a << std::endl;
        }

        return std::nullopt;
    }

} // namespace alphametics
