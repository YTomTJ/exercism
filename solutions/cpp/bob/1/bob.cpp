#include <cctype>
#include "bob.h"

namespace bob
{
    std::string hey(const std::string &line)
    {
        bool has_letter = false;
        bool ALL_CAPITAL = true;
        bool all_space = true;
        char last_letter = '\0';

        for (int i = 0; i < line.size(); ++i)
        {
            if (!std::isspace(line[i]))
            {
                all_space = false;
                last_letter = line[i];
                if (std::isalpha(line[i]))
                {
                    has_letter = true;
                }
                if ('a' <= line[i] && line[i] <= 'z')
                {
                    ALL_CAPITAL = false;
                }
            }
        }

        bool end_quest = last_letter == '?';

        if (all_space)
        {
            return "Fine. Be that way!";
        }
        if (has_letter)
        {
            if (ALL_CAPITAL && end_quest)
            {
                return "Calm down, I know what I'm doing!";
            }
            if (ALL_CAPITAL)
            {
                return "Whoa, chill out!";
            }
        }
        if (end_quest)
        {
            return "Sure.";
        }
        return "Whatever.";
    }

} // namespace bob
