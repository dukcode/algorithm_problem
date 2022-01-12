// [leetcode 1209] Remove All Adjacent Duplicates In String II
#include <string>

std::string removeDuplicates(std::string s, int k)
{
    std::string res;
    std::stack<int> cache;

    for (char c : s)
    {
        if (res.empty() || res.back() != c)
        {
            cache.emplace(1);
            res.push_back(c);
        }
        else
        {
            cache.top()++;
            if (cache.top() == k)
            {
                res.erase(res.end() - (k - 1), res.end());
                duplicate.pop();
            }
            else
            {
                res.push_back(c);
            }
        }
    }

    return res;
}
