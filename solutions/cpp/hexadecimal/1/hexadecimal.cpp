#include "hexadecimal.h"

namespace hexadecimal {

    int convert(const std::string& hex)
    {
        int num = 0;
        int base = 1;
        for(int i = (int)hex.size() - 1; i >= 0; --i, base *= 16)
        {
            auto c = hex[i];
            if('a' <= c && c <= 'f')
            {
                num += base * (c - 'a' + 10);
            }
            else if('0' <= c && c <= '9')
            {
                num += base * (c - '0');
            }
            else
            {
                return 0;
            }
        }
        return num;
    }

}  // namespace hexadecimal
