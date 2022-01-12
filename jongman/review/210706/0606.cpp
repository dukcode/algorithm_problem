// 0606.cpp -- 게임판 덮기 문제를 해결하는 재귀 호출 알고리즘
#include <vector>

int w;
int h;

int coverType[4][3][2];

bool inRange(int y, int x)
{
    if (y < 0 || y >= h || x < 0 || x >= w)
    {
        return false;
    }

    return true;
}

bool draw(vector< vector<int> >& board, int y, int x, int type, int delta)
{
    bool ok = true;
    for (int i = 0; i < 3; ++i)
    {
        int ny = y + coverType[type][i][0];
        int nx = x + coverType[type][i][1];

        if (!inRange(ny, nx))
        {
            ok = false;
            continue;
        }

        if ((board[ny][nx] += delta) != 1)
        {
            ok = false;
        }
    }

    return ok;
}

int count(vector< vector<int> >& board)
{
    // base case 0 - 빈칸이 없으면 count
    // 위쪽 부터 왼쪽에서 빈칸을 찾는다
    int y = -1; int x = -1;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (board[i][j] == 0)
            {
                y = i; x = j;
                break;
            }

            if (y != -1)
            {
                break;
            }
        }
    }

    if (y == -1)
    {
        return 1;
    }

    int ret = 0;
    for (int type = 0; type < 4; ++type)
    {
        if (draw(y, x, type, 1))
        {
            ret += count(board);
        }
        draw(y, x, type, -1);
    }

    return ret;
}
