// [stack] 026_valid_parentheses.cpp
#include <iostream>
#include <string>
#include <stack>

bool isValid(const std::string& s)
{
        std::stack<char> stk;

        for (int idx = 0; idx < s.size(); ++idx)
        {
            char c = s[idx];
            if (c == '(' || c == '{' || c == '[')
            {
                stk.emplace(c);
            }
            else
            {
                if (stk.empty())
                {
                    return false;
                }

                if (c == ')' && stk.top() == '(')
                {
                    stk.pop();
                }
                else if (c == '}' && stk.top() == '{')
                {
                    stk.pop();
                }
                else if (c == ']' && stk.top() == '[')
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        if (stk.empty())
        {
            return true;
        }

        return false;
}

int main(void)
{
    std::string s{"(){}[]"};



    return 0;
}
