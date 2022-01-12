#include <iostream>
#include <random>

const int N = 10;

void print(int* data, int n);
int findPivotIndex(int* data, int n);

int main(void)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 10);

    int arr[N];
    for (int i = 0; i < N; ++i)
    {
        arr[i] = dist(mt);
    }
    print(arr, N);

    int pivot = findPivotIndex(arr, N);
    std::cout << "pivot : " << pivot << std::endl;
    
    return 0;
}

void print(int* data, int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;
}

// int findPivotIndex(int* data, int n)
// {
//     int sum = 0;
//     for (int idx = 0; idx < n; idx++)
//     {
//         sum += data[idx];
//     }
//
//     int leftSum = 0;
//     int rightSum = sum;
//
//     int previousPivot = 0;
//     for (int idx = 0; idx < n; idx++)
//     {
//         int pivot = data[idx];
//         leftSum += previousPivot;
//         rightSum -= pivot;
//
//         if (leftSum == rightSum)
//         {
//             return idx;
//         }
//
//         previousPivot = pivot;
//     }
// }

int findPivotIndex(int* data, int n)
{
    int leftSum = 0;
    int rightSum = 0;
    for (int idx = 1; idx < n; idx++)
    {
        rightSum += data[idx];
    }

    for (int pivot = 1; pivot < N; ++pivot)
    {
        leftSum += data[pivot - 1];
        rightSum -= data[pivot];

        if (leftSum == rightSum)
        {
            return pivot;
        }
    }

    return -1;
}
