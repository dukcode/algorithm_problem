// 11726.cpp -- 2xn 타일링
#include <iostream>

using namespace std;

long long cache[1001];


int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cache[1] = 1; cache[2] = 2;
    for (int i = 3; i < 1001; i++)
    {
        cache[i] = cache[i - 1] + cache[i - 2];
    }

    int n; cin >> n;
    cout << cache[n] % 10007 << '\n';

    return 0;
}

