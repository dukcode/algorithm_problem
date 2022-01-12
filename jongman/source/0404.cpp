// 0404.cpp -- 선형 시간에 이동 평균 구하기

#include <iostream>
#include <vector>

vector<double> GetMovingAverage(const vector<double>& A, int M)
{
    vector<double> movingAverage;

    int size = A.size();
    double partialSum;

    for (int i = 0; i < M - 1; i++)
    {
        partialSum += A[i];
    }

    for (int i = M - 1; i < size; i++)
    {
        partialSum += A[i];
        movingAverage.push_back(partialSum / M);
        partialSum -= A[i - M + 1];
    }

    return movingAverage;
}
