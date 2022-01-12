#include <iostream>
#include <stack>
#include <cctype>

int calculate(std::string s)
{
    const int n = s.size();
    std::stack<int> numStk;
    
    int idx = 0;
    while (idx < n)
    {
        if (s[idx] == ' ')
        {
            idx++;
            continue;
        }

        if (s[idx] == '+')
        {
            numStk.emplace(0);
            idx++;

            while (s[idx] == ' ')
            {
                idx++;
            }

            while (std::isdigit(s[idx]))
            {
                numStk.top() = numStk.top() * 10 + (s[idx] - '0');
                idx++;
            }
        }
        if else (s[idx] == '-')
        {
            numStk.emplace(0);
            idx++;

            while (s[idx] == ' ')
            {
                idx++;
            }

            while (std::isdigit(s[idx]))
            {
                numStk.top() = numStk.top() * 10 - (s[idx] - '0');
                idx++;
            }
        }

        if else (s[idx] == '*')
        {
            idx++;

        }
    }

}

int main(void)
{
    std::cout << calculate("10 / 2 + 10 * 2 + 2 * 2 * 2+500") << std::endl;

    return 0;
}
