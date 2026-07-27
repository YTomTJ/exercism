#include <bitset>
#include <string>
#include "eliuds_eggs.h"

namespace chicken_coop {

    int positions_to_quantity(int number)
    {
        std::bitset<32> bits(number);
        std::string digits = bits.to_string();
        int n = 0;
        for(size_t i = 0; i < digits.size(); ++i)
        {
            if(digits[i] == '1') {
                n++;
            }
        }
        return n;
    }

}  // namespace chicken_coop
