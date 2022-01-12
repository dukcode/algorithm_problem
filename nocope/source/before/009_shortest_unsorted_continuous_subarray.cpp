#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

int findUnsortedSubarray(const std::vector<int>& arr)
{
    int n = arr.size();

    int start = -1;
    int end = -2;
    int maxValue = std::numeric_limits<int>::min();
    int minValue = std::numeric_limits<int>::max();
    for (int i = 0; i < n; ++i)
    {
        maxValue = std::max(maxValue, arr[i]);
        if (maxValue > arr[i])
        {
            end = i;
        }

        minValue = std::min(minValue, arr[n - 1 - i]);
        if (minValue < arr[n - 1 - i])
        {
            start = n - 1 - i;
        }
    }

    return end - start + 1;
}

int main(void)
{
    std::vector<int> arr{2, 5, 7, 6, 3, 9, 15};

    std::cout << findUnsortedSubarray(arr) << std::endl;

    return 0;
}
