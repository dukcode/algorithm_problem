// [baekjoon 12865] 평범한 배낭
// 다시
#include <iostream>
#include <cstdio>
#include <vector>
#include <limits>

int num;
int weightLimit;

std::vector<int> weights;
std::vector<int> costs;

int getMaxValue(std::vector<std::vector<int>>& values);

int main(void)
{
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    std::freopen("input.txt", "r", stdin);

    std::cin >> num >> weightLimit;

    int w;
    int v;
    for (int i = 0; i < num; ++i)
    {
        std::cin >> w >> v;
        weights.emplace_back(w);
        costs.emplace_back(v);
    }
    std::vector<std::vector<int>> values(num + 1, std::vector<int>(weightLimit + 1, 0));
    for (int i = 1; i < weightLimit + 1; ++i)
    {
        values[0][i] = std::numeric_limits<int>::min();
    }

    std::cout << getMaxValue(values) << '\n';

    return 0;
}

int getMaxValue(std::vector<std::vector<int>>& values)
{
    int res = std::numeric_limits<int>::min();

    for (int itemNum = 0; itemNum < num; ++itemNum)
    {
        for (int weight = 0; weight <= weightLimit; ++weight)
        {
            int notTakingWeight = weight - weights[itemNum];
            int notTakingValue;

            if (notTakingWeight < 0)
            {
                notTakingValue = 0;
            }
            else
            {
                notTakingValue = values[itemNum][notTakingWeight];
            }

            values[itemNum + 1][weight] = std::max(notTakingValue, values[itemNum][notTakingWeight] + costs[itemNum]);
            res = std::max(values[itemNum + 1][weight], res);
        }
    }


    return res == std::numeric_limits<int>::min() ? 0 : res;
}
