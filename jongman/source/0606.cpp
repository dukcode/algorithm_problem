// 0606.cpp -- 게임판 덮기 문제를 해결하는 재귀 호출 알고리즘
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int coverType[4][3][2] = {{{0, 0}, {0, 1}, {1, 1}},
                           {{0, 0}, {1, -1}, {1, 0}},
                           {{0, 0}, {1, 0}, {1, 1}},
                           {{0, 0}, {0, 1}, {1, 0}}};

int cover(vector<vector<int>>& board);

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("0606_input.txt", "r", stdin);
    
    int testCase; cin >> testCase;
    while (testCase--)
    {
        int H; cin >> H;
        int W; cin >> W;

        // initialize board
        vector<vector<int>> board(H, vector<int>(W, false));
        for (int y = 0; y < H; y++)
        {
            for (int x = 0; x < W; x++)
            {
                char input; cin >> input;
                if (input == '#')
                {
                    board[y][x] = 1;
                }
                else
                {
                    board[y][x] = 0;
                }
            }
        }

        cout << cover(board) << endl;
    }

    return 0;
}

bool inRange(vector<vector<int>>& board, int y, int x)
{
    if (y < 0 || y >= board.size() || x < 0 || x >= board[0].size())
    {
        return false;
    }
    
    return true;
}

bool draw(vector<vector<int>>& board, int y, int x, int type, int draw)
{
    // type과 draw에 따라 값 더해줌과 동시에 기존 장소 1이거나 board벗어나면 false return

    bool flag = true;
    for (int i = 0; i < 3; i++)
    {
        int nextY = y + coverType[type][i][0];
        int nextX = x + coverType[type][i][1];

        if (inRange(board, nextY, nextX))
        {
            if (board[nextY][nextX] == 1)
            {
                flag = false;
            }
            board[nextY][nextX] += draw;
        }
        else
        {
            flag = false;
        }
    }

    return flag;
}

int cover(vector<vector<int>>& board)
{
    // base case : 왼쪽 위 부터 빈칸을 찾고 빈칸이 없으면 1을 return한다.
    int y = 0; int x = 0; int countEmpty = 0;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == 0)
            {
                if (countEmpty == 0)
                {
                    y = i;
                    x = j;
                }
                countEmpty++;
            }
        }
    }
    // cout << "x = " << x << ", y = " << y << '\n';
    // cout << "empty = " << countEmpty << '\n';
    
    // 남은 빈 칸의 수가 3의 배수이면 return 0
    if ((countEmpty % 3) != 0)
    {
        return 0;
    }
    // 남은 빈 칸이 존재하지 않으면 return 1
    if (countEmpty == 0)
    {
        return 1;
    }

    int ret = 0;

    for (int type = 0; type < 4; type++)
    {
        if (draw(board, y, x, type, 1))
        {
            ret += cover(board);
        }
        draw(board, y, x, type, -1);
    }

    return ret;
}

