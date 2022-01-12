// 9095.cpp -- 1, 2, 3 더하기
#include <iostream>
#include <cstdio>

using namespace std;

int cache[11];

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int testCase; cin >> testCase;
    while (testCase--)
    {
        int n; cin >> n;

        cache[1] = 1;
        cache[2] = 2;
        cache[3] = 4;
        
        for (int i = 4; i < 11; i++)
        {
            cache[i] = cache[i - 1] + cache[i - 2] + cache[i - 3];
        }

        cout << cache[n] << '\n';
    }
    return 0;
}
