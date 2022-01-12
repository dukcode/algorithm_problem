// [leetcode 91] Decode Ways
#include <string>
#include <vector>

// 뒤에서 부터 땡기는 이유?
int numDecodings(std::string s)
{
    const int n = s.size();
    std::vector<int> cache(n + 1, 0);

    cache[n] = 1;
    cache[n - 1] = s[n - 1] == '0' ? 0 : 1;

    for (int i = n - 2; i >= 0; --i)
    {
        int singleNum = s[i] - '0';
        if (singleNum > 0)
        {
            cache[i] += cache[i + 1];
        }

        int doubleNum = singleNum * 10 + (s[i + 1] - '0');
        if (10 <= doubleNum && doubleNum <= 26)
        {
            cache[i] += cache[i + 2];
        }
    }

    return cache[0];
}
