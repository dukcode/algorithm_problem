#include <cstdio>
#include <iostream>
#include <string>
#include <array>
#include <algorithm>

int lengthOfLongestSubString(std::string s);

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string s;
    cin >> s;

    cout << lengthOfLongestSubString(s) << '\n';

    return 0;
}

int lengthOfLongestSubString(std::string s)
{
    const int n = s.size();
    static std::array<int, 256> cache;
    cache.fill(-1);

    int maxLength = 0;
    int start = 0;
    int end = 0;

    while (end < n)
    {
        if (cache[s[end]] >= start)
        {
            start = cache[s[end]] + 1;
        }
        cache[s[end]] = end;

        maxLength = max(maxLength, end - start + 1);
        end++;
    }

    return maxLength;
}
