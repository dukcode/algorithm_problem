// [leetcode 560] Subarray Sum Equals K
#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

int subarraySum(std::vector<int>& nums, int k)
{
    const int n = nums.size();

    // map<sum, 갯수>로 최적화
    std::unordered_map<int, int> m;
    m.emplace(0, 1);
    
    int count = 0;
    int cumulativeSum = 0;
    for (int i = 0; i < n; ++i)
    {
        cumulativeSum += nums[i];

        if (m.find(cumulativeSum - k) != m.end())
        {
            count += m[cumulativeSum - k];
        }

        ++m[cumulativeSum];
    }

    return count;

////////////////////////////////////////////////////////////////////////

    // const int n = nums.size();
    //
    // std::unordered_map<int, std::vector<int>> m;
    // m.emplace(0, std::vector<int>(1, -1));
    //
    // int count = 0;
    // int cumulativeSum = 0;
    // for (int i = 0; i < n; ++i)
    // {
    //     cumulativeSum += nums[i];
    //
    //     // m[cumulativeSum].emplace_back(i); 아래에 if문 안하는 이유 cumulativeSum - k = cumulativeSum일 때 (k == 0) nums[idx] 만 포함된 잘못된 결과 포함됨
    //     if (m.find(cumulativeSum - k) != m.end())
    //     {
    //         count += m[cumulativeSum - k].size();
    //     }
    //
    //     m[cumulativeSum].emplace_back(i);
    // }
    //
    // return count;

////////////////////////////////////////////////////////////////////

    // 이딴 식으로 하면 ㅂㅅ! 머리 굴려
    // for문 하나에 다 우겨 넣으면 순서에 따르기 때문에 자기 자신보다 뒤에 있는 idx 거를 수 있다!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    // for (const std::pair<int, std::vector<int>>& e : m)
    // {
    //     if (m.find(k + e.first) != m.end())
    //     {
    //         for (int i = 0; i < e.second.size(); ++i)
    //         {
    //             for (int j = 0; j < m[k + e.first].size(); ++j)
    //             {
    //                 if (e.second[i] < m[k + e.first][j])
    //                 {
    //                     res += 1;
    //                 }
    //             }
    //         }
    //     }
    // }
    //
    // return res;
}

int main(void)
{
    std::vector<int> v{1, 1, -1, 1, -1};

    int ans = subarraySum(v, 1);

    std::cout << '\n' << ans << '\n';

    return 0;
}
