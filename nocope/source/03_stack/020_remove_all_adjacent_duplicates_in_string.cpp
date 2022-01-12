// [leetcode 1047] Remove All Adjacent Duplicates In String
#include <string>

std::string removeDuplicates(std::string& s)
{
    std::string res;

    for (char c : s)
    {
        if (res.empty() || res.back() != c)
        {
            res.push_back(c);
        }
        else
        {
            res.pop_back();
        }
    }

    return res;
}
