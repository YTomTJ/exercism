#include "luhn.h"

namespace luhn {

    bool valid(const std::string& s)
    {
        if(s.size() <= 1) {
            return false;
        }
        int sum = 0;
        int k = 0;
        for(auto ite = s.rbegin(); ite != s.rend(); ++ite)
        {
            auto c = *ite;
            if('0' <= c && c <= '9')
            {
                k++;
                if(k % 2 == 0)
                {
                    auto x = (c - '0') * 2;
                    if(x > 9) x -= 9;
                    sum += x;
                } else
                {
                    sum += c - '0';
                }
            }
            else if(c == ' ')
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return k > 1 && (sum % 10 == 0);
    }

}  // namespace luhn
