// 0603.cpp


const int BOARD_SIZE = 5;

char board[BOARD_SIZE][BOARD_SIZE];

const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool hasWord(int y, int x, const string& word)
{
    if (y < 0 || y >= BOARD_SIZE || x < 0 || x >= BOARD_SIZE)
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
        int ny = y + dy[direction];
        int nx = x + dx[direction];

        if (hasWord(ny, nx, word.substr(1)))
        {
            return true;
        }
    }

    return false;
}
