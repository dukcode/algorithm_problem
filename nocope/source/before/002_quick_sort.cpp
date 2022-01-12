// baekjoon - 2750
#include <iostream>

void swap(int& lhs, int& rhs)
{
    int temp = lhs;
    lhs = rhs;
    rhs = temp;
}

void quick_sort(int* data, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int pivot = (end + start) / 2;
    int first = start;
    int second = end - 1;

    swap(data[pivot], data[end]);

    while (first <= second)
    {
        while (data[first] < data[end] && first < end)
        {
            first++;
        }

        while (data[second] > data[end] && second >= start)
        {
            second--;
        }

        if (first < second)
        {
            swap(data[first], data[second]);
        }
    }

    swap(data[first], data[end]);

    quick_sort(data, start, first - 1);
    quick_sort(data, first + 1, end);
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    // freopen("002_input.txt", "r", stdin);

    const int num = 1000;
    int arr[num];

    int n; std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << '\n';
    }

    return 0;
}
