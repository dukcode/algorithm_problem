// [leetcode 347] Top K Frequent Elements
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>

// class 안에 선언되려면 static으로 선언되어야 함
bool compare(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs)
{
    return lhs.second > rhs.second;
}

std::vector<int> topKFrequent(std::vector<int>& nums, int k)
{
    const int n = nums.size();

    std::unordered_map<int, int> m;
    for (int i = 0; i < n; ++i)
    {
        m[nums[i]]++;
    }

    // 옮기는 과정 중요 : heap container로도 구현할 수 있다고 하는데 (O(nlgk)) 배우고 해보기
    std::vector<std::pair<int, int>> ans(m.begin(), m.end());
    std::sort(ans.begin(), ans.end(), compare);
    ans.erase(ans.begin() + k, ans.end());

    vector<int> res;
    for (const auto& e : ans)
    {
        res.emplace_back(e.first);
    }
    return res;
}
