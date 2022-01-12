#include <stack>

class MinStack
{
public:
    std::stack<int> container;
    std::stack<int> minContainer;

    MinStack()
        : container{stack<int>()}, minContainer{stack<int>()}
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
        if (!container.empty())
        {
            int val = container.top();
            container.pop();
            if (val == minContainer.top())
            {
                minContainer.pop();
            }
        }
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

int main(void)
{

    return 0;
}
