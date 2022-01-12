#include <iostream>
#include <cstdio>

using namespace std;

int cache[101];
int n;
int A[100];
int choice[101];

int lis(int start);

int main(void)
{

    return 0;
}

int lis(int start)
{
    if (start == n)
    {
        return 0;;
    }

    int ret = cache[start + 1];
    if (ret != -1)
    {
        return ret;
    }

    int ret = 1;
    int bestNext = -1;
    for (int next = start + 1; next < n; next++)
    {
        if (start == -1 || A[start] < A[next])
        {
            int cand = lis(next) + 1;
            if (cand > ret)
            {
                ret = cand;
                bestNext = next;
            }
        }
    }

    choice[start + 1] = bestNext;
    return ret;
}

void reconstruct(int start, vector<int>& seq)
{
    if (start != -1)
    {
        seq.push_back(A[start]);
    }

    int next = choice[start + 1];

    if (next != -1)
    {
        reconstruct(next, seq);
    }
}
