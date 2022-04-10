// 1463.cpp -- 1로 만들기
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int MAX = 1000001;
int cache[MAX];

void getMinCount();

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);


    getMinCount();

    int n; cin >> n;
    cout << cache[n] << '\n';

    return 0;
}

void getMinCount()
{
    cache[1] = 0;
    int n = 2;
    while (n < MAX)
    {
        cache[n] = cache[n - 1] + 1;

        if (n % 3 == 0)
        {
            cache[n] = min(cache[n], cache[n / 3] + 1);
        }

        if (n % 2 == 0)
        {
            cache[n] = min(cache[n], cache[n / 2] + 1);
        }

        n++;
    }
}
