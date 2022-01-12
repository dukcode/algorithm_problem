// [leetcode 394] Decode String
#include <string>
#include <stack>

// stack 사용 시 구현 유의점 : empty인지 아닌지 ex) 2[aa]ef
std::string decodeString(std::string& s)
{
    const std::size_t n = s.size();
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
                countingStk.top() = countingStk.top() * 10 + (s[idx] - '0');
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
        else // s[idx] == ']'
        {
            int k = countingStk.top();
            std::string toAppend(res.top());

            res.pop();
            countingStk.pop();

            for (int i = 0; i < k; ++i)
            {
                res.top() += toAppend;
            }
            idx++;
        }
    }

    return res.top();
}
