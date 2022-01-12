// [leetcode 20] Valid Parentheses
#include <stack>
#include <string>

bool isValid(std::string& s)
{
    const std::size_t n = s.size();
    stack<char> stk;

    for (int i = 0; i < n; ++i)
    {
        char parenthesis = s[i];

        if (parenthesis == '(' || parenthesis == '[' || parenthesis == '{')
        {
            stk.emplace(parenthesis);
        }
        else
        {
            if (stk.empty())
            {
                return false;
            }
            else if (parenthesis == ')' && stk.top() == '(')
            {
                stk.pop();
            }
            else if (parenthesis == ']' && stk.top() == '[')
            {
                stk.pop();
            }
            else if (parenthesis == '}' && stk.top() == '{')
            {
                stk.pop();
            }
            else
            {
                return false;
            }
        }

    }

    return stk.empty() ? true : false;
}
