// 0409.cpp -- 최대 연복 부분 구간 합 문제를 푸는 무식한 알고리즘
#include <iostream>
#include <vector>

const int MIN = numeric_limits<int>::min();

int getInefficientMaxSum(const vector<int>& A)
{
    int ret = MIN;
    int N = A.size();

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += A[k];
            }
            ret = max(ret, sum);
        }
    }

    return ret;
}

int getBetterMaxSum(const vector<int>& A)
{
    int ret = MIN;
    int N = A.size();

    for (int i = 0; i < N - 1; i++)
    {
        int sum = 0;
        for (int j = i; j < N; j++)
        {
            sum += A[j];
            ret = max(ret, sum);
        }
    }
    return ret;
}
