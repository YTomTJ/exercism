#include <array>
#include <string>
#include <vector>

#include <algorithm>
#include <numeric>
#include <sstream>
#include <iostream>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores)
{
    std::vector<int> output(student_scores.size());
    std::transform(student_scores.begin(), student_scores.end(), output.begin(), [](auto x)
                   { return (int)x; });
    return output;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores)
{
    return std::accumulate(student_scores.begin(), student_scores.end(), 0, [](auto count, auto x)
                           { if(x <= 40) count += 1;
                           return count; });
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score)
{
    int step = (highest_score - 40) / 4;
    return {41, 41 + step, 41 + 2 * step, 41 + 3 * step};
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names)
{
    std::vector<std::string> ranking(student_scores.size());
    for (int i = 0; i < student_scores.size(); ++i)
    {
        std::stringstream ss;
        ss << i + 1 << ". " << student_names[i] << ": " << student_scores[i];
        ranking[i] = ss.str();
    }
    return ranking;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names)
{
    auto it = std::find(student_scores.begin(), student_scores.end(), 100);
    if (it != student_scores.end())
    {
        int index = std::distance(student_scores.begin(), it);
        return student_names[index];
    }
    return "";
}
