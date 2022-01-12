// 0804.cpp -- 외발 뛰기 문제를 해결하는 재귀 호출 알고리즘
#include <cstdio>
#include <iostream>
#include <cstring>

int board[100][100];

using namespace std;

bool isPossible(int n, int y, int x);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("0804_input.txt", "r", stdin);

    int testCase; cin >> testCase;
    while (testCase--)
    {
        memset(board, 0, sizeof(board));
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

    int jumpSize = board[y][x];

    return isPossible(n, y + jumpSize, x) || isPossible(n, y, x + jumpSize);
}
