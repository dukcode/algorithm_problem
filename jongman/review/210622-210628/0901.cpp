// 0901.cpp -- LIS 출력하기
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int A[101];

int cache[101];
int choice[101];

int lis(int start);
void reconstruct(int start, vector<int>& seq);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    // freopen("0901_input.txt", "r", stdin);
    
    memset(cache, -1, sizeof(cache));
    memset(choice, -1, sizeof(choice));

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }

    cout << lis(-1) - 1 << '\n';

    vector<int> seq;
    reconstruct(-1, seq);
    for (int i = 0; i < seq.size(); ++i)
    {
        cout << seq[i] << ' ';
    }
    cout << '\n';

    return 0;
}

int lis(int start)
{
    int& ret = cache[start + 1];
    if (ret != -1)
    {
        return ret;
    }

    // base case
    ret = 1;

    int bestNext = -1;
    for (int next = start + 1; next < n; ++next)
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
