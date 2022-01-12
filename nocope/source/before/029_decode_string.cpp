#include <iostream>
#include <string>
#include <stack>
#include <cctype>

std::string decodeString(std::string s)
{
    const int n = s.size();
    std::stack<std::string> res;
    std::stack<int> countingStk;

    res.emplace(std::string());
    int idx = 0;
    while (idx < n)
    {
        if ('0' <= s[idx] && s[idx] <= '9')
        {
            countingStk.emplace(s[idx] - '0');
            idx++;
            while ('0' <= s[idx] && s[idx] <= '9')
            {
                countingStk.top() = countingStk.top() * 10 + int(s[idx] - '0');
                idx++;
            }
        }
        else if ('a' <= s[idx] && s[idx] <= 'z')
        {
            res.top().push_back(s[idx]);
            idx++;
            while ('a' <= s[idx] && s[idx] <= 'z')
            {
                res.top().push_back(s[idx]);
                idx++;
            }
        }
        else if (s[idx] == '[')
        {
            res.emplace(std::string());
            idx++;
        }
        else if (s[idx] == ']')
        {
            int k = countingStk.top();
            std::string toAppend(res.top());

            res.pop();
            countingStk.pop();

            for (int i = 0; i < k; ++i)
            {
                res.top().append(toAppend);
            }

            idx++;
        }
    }

    return res.top();
}

int main(void)
{
    std::cout << decodeString("a20[b2[ak]3[zz]aba2[a]]") << '\n';
    
    return 0;
}
