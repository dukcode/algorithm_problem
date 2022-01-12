// [leetcode 155] Min Stack
#include <stack>

class MinStack
{
public:
    std::stack<int> container;
    std::stack<int> minContainer;

    MinStack()
    {}

    void push(int val)
    {
        container.push(val);
        if (minContainer.empty() || minContainer.top() >= val)
        {
            minContainer.push(val);
        }
    }

    void pop()
    {
        if (container.top() == minContainer.top())
        {
            minContainer.pop();
        }
        container.pop();
    }

    int top()
    {
        return container.top();
    }

    int getMin()
    {
        return minContainer.top();
    }
};

