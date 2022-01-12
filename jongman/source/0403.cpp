// 0403.cpp -- 이동 평균 구하기
#include <iostream>
#include <vector>

vector<double> GetMovingAverage(const vector<double>& A, int M)
{
    vector<double> movingAverage;
    double partialSum;
    int size = A.size();

    for (int i = M - 1; i < size; i++)
    {
        partialSum = 0;

        for (int j = 0; j < M; j++)
        {
            partialSum -= A[i - j];
        }

        movingAverage.push_back(partialSum / M);
    }

    return movingAverage;
}
