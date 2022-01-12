// 0810.cpp -- 최대 부분 수열 문제를 해결하는 완전 탐색 알고리즘
#include <vector>

using namespace std;

vector<int> lis(const vector<int>& A);

int main(void)
{

    return 0;
}

int lis(const vector<int>& A)
{
    // base case
    if (A.empty())
    {
        return 0;
    }

    int ret = 0;

    for (int i = 0; i < A.size(); i++)
    {
        vector<int> B;
        for (int j = i + 1; j < A.size(); j++)
        {
            if (A[i] < A[j])
            {
                B.push_back(A[j]);
            }
        }

        ret = max(ret, 1 + lis(B);
    }

    return ret;
}
