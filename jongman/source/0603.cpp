// 0603.cpp -- 보글 게임판에서 단어를 찾는 재귀 호출 알고리즘
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int dy[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dx[8] = {1, 0, -1, 1, -1, 1, 0, -1};

const char board[5][5] = {{'U', 'R', 'L', 'P', 'M'},
                          {'X', 'P', 'R', 'E', 'T'},
                          {'G', 'I', 'A', 'E', 'T'},
                          {'X', 'T', 'M', 'Z', 'Y'},
                          {'X', 'O', 'Q', 'R', 'S'},
                         };

bool hasWord(int y, int x, const string& word);
bool inRange(int y, int x);

int main(void)
{
    if (hasWord(1, 1, "PRETTY"))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }


    return 0;
}

bool hasWord(int y, int x, const string& word)
{
    if (!inRange(y, x))
    {
        return false;
    }

    if (board[y][x] != word[0])
    {
        return false;
    }

    if (word.size() == 1)
    {
        return true;
    }

    for (int direction = 0; direction < 8; direction++)
    {
        if (hasWord(y + dy[direction], x + dx[direction], word.substr(1)))
        {
            return true;
        }
    }

    return false;
}

bool inRange(int y, int x)
{
    if (0 <= y && y < 5)
    {
        if (0 <= x && x < 5)
        {
            return true;
        }
    }
    return false;
}
