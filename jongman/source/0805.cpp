// 0804.cpp -- 외발 뛰기 문제를 해결하는 동적 계획법 알고리즘
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int board[100][100];
int cache[100][100];

bool isPossible(int n, int y, int x);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("0805_input.txt", "r", stdin);

    int testCase; cin >> testCase;
    while (testCase--)
    {
        memset(board, 0, sizeof(board));
        memset(cache, -1, sizeof(cache));

        int n; cin >> n;
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
            {
                cin >> board[y][x];
            }
        }

        if (isPossible(n, 0, 0))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}

bool isPossible(int n, int y, int x)
{
    // base case 1 : 도착점에 도달
    if (y == n - 1 && x == n - 1)
    {
        return true;
    }

    // base case 2 : 밖을 벗어남
    if (y < 0 || y >= n || x < 0 || x >= n)
    {
        return false;
    }
    
    int& ret = cache[y][x];
    if (ret != -1)
    {
        return ret;
    }

    int jumpSize = board[y][x];

    return ret = isPossible(n, y + jumpSize, x) || isPossible(n, y, x + jumpSize);
}
