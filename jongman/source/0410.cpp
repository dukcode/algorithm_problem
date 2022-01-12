#include <iostream>
#include <vector>

using namespace std;

const int MIN = numeric_limits<int>::min();

int getFastSum(const vector<int>& A, int lo, int hi)
{
    // base case
    if (lo == hi)
    {
        return A[lo];
    }

    int mid = (lo + hi) / 2;

    int left = MIN; int right = MIN;

    int sum = 0;
    for (int i = mid; i >= lo; i--)
    {
        sum += A[i];
        left = max(sum, left);
    }

    int sum = 0;
    for (int i = mid + 1; i <= hi; i++)
    {
        sum += A[i];
        right = max(sum, right);
    }

    int single = max(getFastSum(A, lo, mid), getFastSum(A, mid + 1, hi));

    return max(single, left + right);
}
