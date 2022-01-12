// 1992.cpp -- 쿼드트리 (시간 제한 : 2초)
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

char img[64][64];

string solve(int y, int x, int size);

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    // freopen("1992_input.txt", "r", stdin);

    // 1 <= N <= 64(2^8)
    int N; cin >> N;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            cin >> img[y][x];
        }
    }

    cout << solve(0, 0, N) << '\n';

    return 0;
}

string solve(int y, int x, int size)
{
    // base case
    if (size == 1)
    {
        return string(1, img[y][x]);
    }

    char head = img[y][x];
    bool flag = true;

    for (int i = y; i < y + size; i++)
    {
        for (int j = x; j < x + size; j++)
        {
            if (head != img[i][j])
            {
                flag = false;
                break;
            }
        }
        if (flag == false)
        {
            break;
        }
    }


    if (flag == true)
    {
        return string(1, head);
    }
    else
    {
        int half = size / 2;

        string upperLeft = solve(y, x, half);
        string upperRight = solve(y, x + half, half);
        string lowerLeft = solve(y + half, x, half);
        string lowerRight = solve(y + half, x + half, half);

        return string("(") + upperLeft + upperRight + lowerLeft + lowerRight + string(")");
    }

}
