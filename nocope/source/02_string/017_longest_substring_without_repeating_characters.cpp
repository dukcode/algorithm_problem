// [leetcode 3] Longest Substring Without Reapeating Characters
#include <string>
#include <array>

std::array<int, 256> cache;

int lengthIfLongestSubstring(std::string& s)
{
    const std::size_t n = s.size();
    cache.fill(-1);

    int res = 0;

    int start = -1;
    for (int end = 0; end < n; ++end)
    {
        int& location = cache[s[end]];

        if (start < location)
        {
            start = location;
        }
        
        location = end;

        res = std::max(res, end - start);
    }

    return res;
}
