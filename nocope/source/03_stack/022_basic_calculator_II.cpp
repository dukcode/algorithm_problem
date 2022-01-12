// [leetcode 227] Basic Calculator II
#include <string>
#include <cctype>

// 구현 할 때 놓칠 수 있는 부분이 많음
int calculate(std::string& s)
{
    s += '+';   // 중요!
    std::stack<int> numStk;

    char prevOperator = '+';
    int num = 0;

    for (char c : s)
    {
        if (std::isdigit(c))
        {
            num = num * 10 + (c - '0');
        }
        else if (c == ' ')
        {
            continue;
        }
        else
        {
            if (prevOperator == '+')
            {
                numStk.emplace(num);
            }
            else if (prevOperator == '-')
            {
                numStk.emplace(-num);
            }
            else if (prevOperator == '*')
            {
                numStk.top() *= num;
            }
            else if (prevOperator == '/')
            {
                numStk.top() /= num;
            }

            num = 0;
            prevOperator = c;
        }
    }

    int res = 0;
    while (!numStk.empty())
    {
        res += numStk.top();
        numStk.pop();
    }

    return res;
}
