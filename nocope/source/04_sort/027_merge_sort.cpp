#include <iostream>
#include <random>
#include <algorithm>
#include <vector>

void sort(std::vector<int>& nums, int left, int right)
{
    if (left == right)
    {
        return;
    }

    int mid = (left + right) / 2;
    sort(nums, left, mid);
    sort(nums, mid + 1, right);

    int i = left;
    int j = mid + 1;

    std::vector<int> tmp;
    while (i <= mid && j <= right)
    {
        if (nums[i] <= nums[j])
        {
            tmp.emplace_back(nums[i]);
            i++;
        }
        else
        {
            tmp.emplace_back(nums[j]);
            j++;
        }
    }

    if (i == mid + 1)
    {
        while (j <= right)
        {
            tmp.emplace_back(nums[j]);
            j++;
        }
    }
    else
    {
        while (i <= mid)
        {
            tmp.emplace_back(nums[i]);
            i++;
        }
    }

    for (int i = 0; i < tmp.size(); ++i)
    {
        nums[left + i] = tmp[i];
    }

}

void mergeSort(std::vector<int>& nums)
{
    const int n = nums.size();
    sort(nums, 0, n - 1);
}

int main(void)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 99);

    std::vector<int> nums;
    for (int i = 0; i < 20; ++i)
    {
        nums.emplace_back(dist(mt));
    }

    for (int e : nums)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    mergeSort(nums);

    for (int e : nums)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    return 0;
}
