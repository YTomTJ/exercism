#include "atbash_cipher.h"
#include <sstream>

namespace atbash_cipher
{
    std::string _atbash_(const std::string &text, bool encode)
    {
        int k = 0;
        std::stringstream ss;
        for (size_t i = 0; i < text.size(); ++i)
        {
            auto c = text[i];
            if ('a' <= c && c <= 'z')
            {
                ss << (char)(25 - (c - 'a') + 'a');
                k++;
            }
            else if ('A' <= c && c <= 'Z')
            {
                ss << (char)(25 - (c - 'A') + 'a');
                k++;
            }
            else if ('0' <= c && c <= '9')
            {
                ss << c;
                k++;
            }
            else
            {
                continue;
            }
            if (encode)
            {
                if (k % 5 == 0)
                {
                    ss << ' ';
                }
            }
        }
        auto s = ss.str();
        int last = (int)s.size() - 1;
        for (; last >= 0; --last)
        {
            if (s[last] != ' ')
            {
                break;
            }
        }
        return s.substr(0, last + 1);
    }

    std::string encode(const std::string &text)
    {
        return _atbash_(text, true);
    }

    std::string decode(const std::string &text)
    {
        return _atbash_(text, false);
    }

} // namespace atbash_cipher
