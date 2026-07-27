#include "rotational_cipher.h"

namespace rotational_cipher
{
    std::string rotate(const std::string &text, int rot)
    {
        std::string code = text;
        for (auto &c : code)
        {
            if ('a' <= c && c <= 'z')
            {
                c = (((c - 'a') + rot) % 26) + 'a';
            }
            else if ('A' <= c && c <= 'Z')
            {
                c = (((c - 'A') + rot) % 26) + 'A';
            }
        }
        return code;
    }

} // namespace rotational_cipher
