// 0606.cpp

int coverType[4][3][2] = {
                          {{0, 0},{0, 1},{1,  1}},  // ㄱ
                          {{0, 0},{1, 0},{1, -1}},  // _|
                          {{0, 0},{1, 0},{1,  1}},  // ㄴ
                          {{0, 0},{0, 1},{1,  0}}   // |^
                         };

int board[20][20];

int h;
int w;

int countCovering(void)
{
    // find firstFree
    int y = -1;
    int x = -1;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (board[i][j] == 0)
            {
                y = i; x = j;
                break;
            }
        }

        if (y != -1)
        {
            break;
        }
    }

    // there is no firstFree
    if (y == -1)
    {
        return 1;
    }

    int ret = 0;
    for (int type = 0; type < 4; ++type)
    {
        if (set(y, x, type, 1))
        {
            ret += countCovering();
        }
        set(y, x, type, -1);
    }

    return ret;
}

bool set(int y, int x, int type, int draw)
{
    bool ok = true;

    for (int i = 0; i < 3; i++)
    {
        int ny = y + coverType[type][i][0];
        int nx = x + coverType[type][i][1];

        if (ny < 0 || ny >= h || nx < 0 || nx >= w)
        {
            ok = false;
        }
        else if ((board[ny][nx] += draw) > 1)
        {
            ok = false;
        }
    }

    return ok;
}
