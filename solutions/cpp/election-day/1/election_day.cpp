#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

namespace election
{
    struct ElectionResult
    {
        // Name of the candidate
        std::string name{};
        // Number of votes the candidate has
        int votes{};
    };

    int &vote_count(ElectionResult &es)
    {
        return es.votes;
    }

    void increment_vote_count(ElectionResult &es, int votes)
    {
        es.votes += votes;
    }

    ElectionResult &determine_result(std::vector<ElectionResult>& votes)
    {
        auto ite = std::max_element(votes.begin(), votes.end(), [](const auto &x, const auto &y)
                                    { return x.votes < y.votes; });
        ite->name = "President " + ite->name;
        return *ite;
    }

} // namespace election
