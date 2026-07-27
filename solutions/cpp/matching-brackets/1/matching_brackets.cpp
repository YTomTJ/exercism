#include <vector>
#include "matching_brackets.h"

namespace matching_brackets
{
    bool check(const std::string &text)
    {
        std::vector<char> brackets;
        for (auto c : text)
        {
            if (c == '[' || c == '{' || c == '(')
            {
                brackets.push_back(c);
                continue;
            }
            if (c == ']')
            {
                if (brackets.size() <= 0 || brackets[brackets.size() - 1] != '[')
                    return false;
            }
            else if (c == '}')
            {
                if (brackets.size() <= 0 || brackets[brackets.size() - 1] != '{')
                    return false;
            }
            else if (c == ')')
            {
                if (brackets.size() <= 0 || brackets[brackets.size() - 1] != '(')
                    return false;
            }
            else
            {
                continue;
            }
            brackets.pop_back();
        }
        return brackets.size() == 0;
    }

} // namespace matching_brackets
