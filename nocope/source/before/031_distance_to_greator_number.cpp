// 739. Daily Temperatures
#include <vector>
#include <stack>
#include <utility>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures)
{
    const int n = temperatures.size();
    stack<pair<int, int>> stk;

    for (int i = n - 1; i >= 0; --i)
    {

        while (!stk.empty() && stk.top().first <= temperatures[i])
        {
            stk.pop();
        }

        int distance = stk.empty() ? 0 : stk.top().second - i;
        stk.emplace(make_pair(temperatures[i], i));
        temperatures[i] = distance;
    }

    return temperatures;
}


