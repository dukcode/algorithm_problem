// 0411.cpp -- 최대 연속 부분 구간 합 문제를 푸는 동적 계획법 알고리즘
#include <iostream>
#include <vector>

int getFastestMaxSum(const vector<int>& A)
{
    int N = A.size();
    ret = MIN;
    int psum = 0;

    for (int i = 0; i < N; i++)
    {
        psum = max(0, psum) + A[i];
        ret = max(ret, psum);
    }

    return ret;
}
