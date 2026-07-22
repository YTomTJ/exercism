#include <sstream>
#include <string>

namespace log_line {
    std::string message(std::string line) {
        auto i = line.find(": ");
        if(i == std::string::npos) {
            return "";
        }
        return line.substr(i + 2);
    }

    std::string log_level(std::string line) {
        auto a = line.find("[");
        if(a == std::string::npos) {
            return "";
        }
        a += 1;
        auto b = line.find("]");
        if(b == std::string::npos) {
            return "";
        }
        return line.substr(a, b - a);
    }

    std::string reformat(std::string line) {
        auto msg = message(line);
        auto lvl = log_level(line);

        std::stringstream ss;
        ss << msg << " (" << lvl << ")";
        return ss.str();
    }
}  // namespace log_line
