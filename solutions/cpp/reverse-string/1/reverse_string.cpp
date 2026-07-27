#include <algorithm>
#include "reverse_string.h"

namespace reverse_string {

    std::string reverse_string(const std::string &line)
    {
        std::string x = line;
        std::reverse(x.begin(), x.end());
        return x;
    }

}  // namespace reverse_string
