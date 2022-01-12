// [leetcode 739] Daily Temperature
#include <vector>
#include <stack>
#include <utilty>

std::vector<int> dailyTemperatures(std::vector<int>& temperatures)
{
    const int n = temperatures.size();
    std::stack<std::pair<int, int>> stk;

    for (int i = n - 1; i >= 0; --i)
    {
        while (!stk.empty() && temperatures[i] >= stk.top().first)
        {
            stk.pop();
        }

        int distance = stk.empty() ? 0 : stk.top().second - i;
        stk.emplace(std::pair<int, int>(temperatures[i], i));
        temperatures[i] = distance;
    }

    return temperatures;
}
