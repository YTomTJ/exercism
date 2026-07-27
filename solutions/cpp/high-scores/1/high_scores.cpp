#include <algorithm>
#include "high_scores.h"

namespace arcade
{

    std::vector<int> HighScores::list_scores()
    {
        return scores;
    }

    int HighScores::latest_score()
    {
        if (scores.size() > 0)
        {
            return scores[scores.size() - 1];
        }
        return 0;
    }

    int HighScores::personal_best()
    {
        return *std::max_element(scores.begin(), scores.end());
    }

    std::vector<int> HighScores::top_three()
    {
        auto _scores = scores;
        std::sort(_scores.begin(), _scores.end(), [](int a, int b)
                  { return a > b; });

        std::vector<int> top;
        for (int i = 0; i < std::min(3, (int)_scores.size()); ++i)
        {
            top.push_back(_scores[i]);
        }
        return top;
    }

} // namespace arcade
