// 2580.cpp -- 스도쿠
#include <cstdio>
#include <iostream>

int board[9][9];

void printBoard(void);
bool solve(int y, int x);

using namespace std;

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("2580_input.txt", "r", stdin);

    for (int y = 0; y < 9; ++y)
    {
        for (int x = 0; x < 9; ++x)
        {
            cin >> board[y][x];
        }
    }

    solve(0, 0);
    printBoard();

    return 0;
}

void printBoard(void)
{
    for (int y = 0; y < 9; ++y)
    {
        for (int x = 0; x < 9; ++x)
        {
            cout << board[y][x] << ' ';
        }
        cout << '\n';
    }
}

bool solve(int y, int x)
{
    if (y == 8 && x == 8)
    {
        return true;
    }

    bool taken[11];
    memset(taken, false, sizeof(taken));

    if (board[y][x] == 0)
    {
        // 같은 줄에 있는 숫자 검사
        for (int i = 0; i < 9; ++i)
        {
            taken[board[y][i]] = taken[board[i][x]] = true;
        }

        // 같은 그룹에 있는 숫자 검사
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                taken[board[i + y / 3][j + x / 3]] = true;
            }
        }
    }

    for (int i = 1; i < 10; i++)
    {
        if (!taken[i])
        {
            board[y][x] = i;

            int ny = (x + 1) % 9;
            int nx = y + (x + 1) / 9;

            if (solve(ny, nx))
            {
                return true;
            }
        }
    }
    

    return false;
}
