// 11053.cpp -- 가장 긴 증가하는 부분 수열
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cache[1001];

int n;
int A[1000];

int lis(int start);

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("11053_input.txt", "r", stdin);

    memset(cache, -1, sizeof(cache));

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cout << lis(-1) - 1 << '\n';

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

    for (int next = start + 1; next < n; next++)
    {
        if (start == -1 || A[start] < A[next])
        {
            ret = max(ret, lis(next) + 1);
        }
    }

    return ret;
}
// 11053.cpp -- 가장 긴 증가하는 부분 수열
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cache[1001];

int n;
int A[1000];

int lis(int start);

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("11053_input.txt", "r", stdin);

    memset(cache, -1, sizeof(cache));

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cout << lis(-1) - 1 << '\n';

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

    for (int next = start + 1; next < n; next++)
    {
        if (start == -1 || A[start] < A[next])
        {
            ret = max(ret, lis(next) + 1);
        }
    }

    return ret;
}
// 11053.cpp -- 가장 긴 증가하는 부분 수열
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cache[1001];

int n;
int A[1000];

int lis(int start);

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("11053_input.txt", "r", stdin);

    memset(cache, -1, sizeof(cache));

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cout << lis(-1) - 1 << '\n';

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

    for (int next = start + 1; next < n; next++)
    {
        if (start == -1 || A[start] < A[next])
        {
            ret = max(ret, lis(next) + 1);
        }
    }

    return ret;
}
