#include "trinary.h"

namespace trinary {

    int to_decimal(const std::string& trinary)
    {
        int base = 1;
        int num  = 0;
        for(auto ite = trinary.rbegin(); ite != trinary.rend(); ++ite, base *= 3)
        {
            if(!('0' <= *ite && *ite <= '9'))
            {
                return 0;
            }
            int c = *ite - '0';
            num += base * c;
        }
        return num;
    }

}  // namespace trinary
