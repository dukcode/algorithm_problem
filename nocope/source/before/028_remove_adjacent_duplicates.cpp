#include <iostream>
#include <string>
#include <algorithm>

std::string removeDuplicates(std::string s)
{
    const int n = s.size();
    std::string stk;
    for (int idx = 0; idx < n; ++idx)
    {
        if (stk.empty() || stk.back() != s[idx])
        {
            stk.push_back(s[idx]);
        }
        else
        {
            stk.pop_back();
        }
    }

    return stk;
}

int main(void)
{
    std::cout << removeDuplicates("azxxzy") << std::endl;

    return 0;
}
