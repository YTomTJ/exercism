#include <cmath>
#include <string>
#include "armstrong_numbers.h"

namespace armstrong_numbers {

    bool is_armstrong_number(int number)
    {
        auto digits = std::to_string(number);
        if (digits.size() <= 1)
            return true;

        int sum = 0;
        for (size_t i = 0; i < digits.size(); ++i)
        {
            sum += std::pow(digits[i] - '0', digits.size());
        }
        return sum == number;
    }

}  // namespace armstrong_numbers
