// 0703.cpp
#include <vector>

void normalize(vector<int>& num)
{
    num.push_back(0);

    for (int i = 0; i + 1 < num; ++i)
    {
        if (num[i] < 0)
        {
            int borrow = (abs(num[i]) + 9) / 10;
            num[i + 1] -= borrow;
            num[i] += borrow * 10;
        }
        else
        {
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
    }

    while (num.back() == 0 && num.size() > 1)
    {
        num.pop_back();
    }
}

vector<int> multiply(const vector<int>& A, const vector<int>& B)
{
    vector<int> C(A.size() + B.size() + 1, 0);

    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            C[i + j] += A[i] * B[j];
        }
    }

    normalize(C);

    return C;
}
