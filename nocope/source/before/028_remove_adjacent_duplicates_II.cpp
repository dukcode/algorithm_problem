#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

std::string removeDuplicates(std::string s, int k)
{
    const int n = s.size();
    std::string res;
    std::stack<int> duplicate;
    for (int idx = 0; idx < n; ++idx)
    {
        if (res.empty() || res.back() != s[idx])
        {
            res.push_back(s[idx]);
            duplicate.emplace(1);
        }
        else if (res.back() == s[idx])
        {
            duplicate.top()++;
            if (duplicate.top() == k)
            {
                res.erase(res.end() - (k - 1), res.end());
                duplicate.pop();
            }
            else
            {
                res.push_back(s[idx]);
            }
        }
    }

    return res;
}

int main(void)
{
    std::cout << removeDuplicates("pbbcggttciiippooaais", 2) << std::endl;

    return 0;
}
