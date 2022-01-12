// 0812.cpp -- 최대 증가 부분 수열 문제를 해결하는 동적 계획법 알고리즘 (2)
#include <vector>
#include <algorithm>

vector<int> A;

int cache[101];

int main(void)
{

    cout << lis(-1) + 1 << '\n';

    return 0;
}

int lis(int start)
{
    int& ret = cache[start + 1];
    if (ret != -1)
    {
        return ret;
    }

    ret = 1;

    for (int i = 1; start + i < A.size(); i++)
    {
        if (srart == -1 || A[start] < A[start + i])
        {
            ret = max(ret, lis(start + i) + 1);
        }
    }

    return ret;
}
