// 1520.cpp -- 내리막 길
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int h;
int w;

int map[500][500];

int cache[500][500];

int numOfRoutes(int y, int x);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("1520_input.txt", "r", stdin);

    memset(cache, -1, sizeof(cache));

    cin >> h >> w;
    for (int y = 0; y < h; ++y)
    {
        for (int x = 0; x < w; ++x)
        {
            cin >> map[y][x];
        }
    }

    cout << numOfRoutes(0, 0) << '\n';

    return 0;
}

int numOfRoutes(int y, int x)
{
    if (y < 0 || y >= h || x < 0 || x >= w)
    {
        return 0;
    }
    
    int& ret = cache[y][x];
    if (ret != -1)
    {
        return ret;
    }

    if (y == h - 1 && x == w - 1)
    {
        return ret = 1;
    }

    ret = 0;
    if (x != w - 1 && map[y][x] > map[y][x + 1]) // right
    {
        ret += numOfRoutes(y, x + 1);
    }

    if (y != h - 1 && map[y][x] > map[y + 1][x]) // down
    {
        ret += numOfRoutes(y + 1, x);
    }

    if (x != 0 && map[y][x] > map[y][x - 1]) // left
    {
        ret += numOfRoutes(y, x - 1);
    }

    if (y != 0 && map[y][x] > map[y - 1][x]) // up
    {
        ret += numOfRoutes(y - 1, x);
    }

    return ret;
}


