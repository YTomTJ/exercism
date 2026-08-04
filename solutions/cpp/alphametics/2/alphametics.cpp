#include <algorithm>
#include <cctype>
#include <numeric>
#include <set>
#include <vector>
#include <stdexcept>

#include "alphametics.h"

using word_t = std::vector<size_t>;

namespace alphametics
{
    void preprocess(
        const std::string &problem,
        std::vector<char> &letters,
        std::vector<int> &coeff,
        std::set<int> &headers)
    {
        // find each word and all letters
        std::set<char> set;
        std::vector<std::vector<char>> left;
        std::vector<char> right;
        for (size_t i = 0; i < problem.size() + 1; ++i)
        {
            if (std::isalpha(problem[i]))
            {
                right.emplace_back(problem[i]);
                set.emplace(problem[i]);
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

        // convert to index
        letters.reserve(set.size());
        for (auto c : set)
        {
            letters.emplace_back(c);
        }
        std::map<char, size_t> index;
        for (size_t i = 0; i < letters.size(); ++i)
        {
            index[letters[i]] = i;
        }

        // count all letters by coefficients
        coeff.resize(letters.size());
        for (const auto &item : left)
        {
            int base = 1;
            for (auto ite = item.rbegin(); ite != item.rend(); ++ite, base *= 10)
            {
                coeff[index[*ite]] += base;
            }
        }
        {
            int base = 1;
            for (auto ite = right.rbegin(); ite != right.rend(); ++ite, base *= 10)
            {
                coeff[index[*ite]] -= base;
            }
        }

        // sort by count
        std::vector<int> sorted(letters.size());
        for (size_t i = 0; i < sorted.size(); ++i)
        {
            sorted[i] = i;
        }
        std::sort(sorted.begin(), sorted.end(), [&coeff](auto a, auto b)
                  { return std::abs(coeff[a]) > std::abs(coeff[b]); });

        std::vector<char> sorted_letters(sorted.size());
        std::vector<int> sorted_counts(sorted.size());
        for (size_t i = 0; i < sorted.size(); ++i)
        {
            sorted_letters[i] = letters[sorted[i]];
            sorted_counts[i] = coeff[sorted[i]];
            index[sorted_letters[i]] = i;
        }
        sorted_letters.swap(letters);
        sorted_counts.swap(coeff);

        // mark headers (cannot be 0)
        for (const auto &item : left)
        {
            headers.emplace(index[item[0]]);
        }
        headers.emplace(index[right[0]]);
    }

    bool dfs(
        std::vector<int> &test, std::vector<int> &marks,
        const size_t n, const std::vector<int> &coeff, const std::set<int> &headers,
        int total = 0)
    {
        if (test.size() == n)
        {
            return total == 0;
        }

        size_t k = test.size();
        for (size_t i = 0; i < marks.size(); ++i)
        {
            if (i == 0 && headers.find(k) != headers.end())
            {
                continue;
            }
            if (marks[i] > 0)
            {
                continue;
            }
            marks[i] = 1;
            test.push_back(i);
            if (dfs(test, marks, n, coeff, headers, total + coeff[test.size() - 1] * i))
            {
                return true;
            }
            test.pop_back();
            marks[i] = 0;
        }
        return false;
    }

    std::optional<std::map<char, int>> solve(const std::string &problem)
    {
        std::vector<char> letters;
        std::vector<int> coeff;
        std::set<int> headers;

        preprocess(problem, letters, coeff, headers);

        // search by dfs
        std::vector<int> marks(10);
        for (size_t i = 0; i < marks.size(); ++i)
        {
            marks[i] = 0;
        }

        std::vector<int> test;
        test.reserve(letters.size());
        if (dfs(test, marks, letters.size(), coeff, headers))
        {
            std::map<char, int> map;
            for (size_t i = 0; i < test.size(); ++i)
            {
                map.emplace(letters[i], test[i]);
            }
            return map;
        }
        return std::nullopt;
    }

} // namespace alphametics
