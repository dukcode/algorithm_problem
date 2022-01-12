#include <vector>
#include <iostream>
#include <random>

void insertionSort(std::vector<int>& nums)
{
    const int n = nums.size();
    for (int i = 1; i < n; ++i)
    {
        int num = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > num)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = num;
    }
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

    insertionSort(nums);

    for (int e : nums)
    {
        std::cout << e << ' ';
    }
    std::cout << '\n';

    return 0;
}
