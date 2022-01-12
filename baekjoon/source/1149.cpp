// 1149.cpp -- RGB거리
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_PRICE = 1000 * 1000 + 100;

int n;
int price[1000][3];

int cache[1000][3];

int getMinPrice(int count, int selected);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("1149_input.txt", "r", stdin);

    memset(cache, -1, sizeof(cache));
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; i < 3; ++j)
        {
            cin >> price[i][j];
        }
    }

    int answer = MAX_PRICE;
    for (int i = 0; i < 3; i++)
    {
        answer = min(answer, getMinPrice(0, i));
    }
    
    cout << answer << '\n';

    return 0;
}

int getMinPrice(int count, int selected)
{
    // base case
    if (n - 1 == count)
    {
        return price[count][selected];
    }

    int& ret = cache[count][selected];
    if (ret != -1)
    {
        return ret;
    }

    return ret = min(getMinPrice(count + 1, (selected + 1) % 3), getMinPrice(count + 1, (selected + 2) % 3)) + price[count][selected];
}
