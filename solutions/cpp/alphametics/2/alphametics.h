#if !defined(ALPHAMETICS_H)
#define ALPHAMETICS_H

#include <string>
#include <optional>
#include <map>

namespace alphametics
{

    std::optional<std::map<char, int>> solve(const std::string &problem);

} // namespace alphametics

#endif // ALPHAMETICS_H
