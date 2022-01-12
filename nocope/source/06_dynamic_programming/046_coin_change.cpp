// [leetcode 322] Coin Change
#include <vector>
#include <algorithm>
#include <limits>

const int INT_MAX = std::numeric_limits<long long>::max();

int coinChange(std::vector<int>& coins, int amount)
{
    const int n = coins.size();
    std::vector<int> cache(amount + 1, INT_MAX);

    // 아래서 부터 하기 중요
    cache[0] = 0;

    for (int money = 0; money < amount + 1; ++money)
    {
        if (cache[money] != INT_MAX)
        {
            for (const int coin : coins)
            {
                // coin <= amount - money <<= coin의 범위때문에 overflow 방지
                if (coin <= amount - money && money + coin <= amount)
                {
                    cache[money + coin] = min(cache[money + coin], cache[money] + 1);
                }
            }
        }
    }

    return cache[amount] == INT_MAX ? -1 : cache[amount];
}
