#include "binary.h"

namespace binary
{
    int convert(const std::string &binary)
    {
        int k = 1;
        int num = 0;
        for (int i = binary.size() - 1; i >= 0; --i, k *= 2)
        {
            if (binary[i] != '1' && binary[i] != '0')
            {
                return 0;
            }
            num += (binary[i] - '0') * k;
        }
        return num;
    }

} // namespace binary
