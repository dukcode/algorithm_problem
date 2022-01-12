// 0603.cpp -- BOGGLE
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

string board[5];

int hasWord(int y, int x, const string& word);

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("0603_input.txt", "r", stdin);

    int testCase; cin >> testCase;
    while (testCase--)
    {
        for (int i = 0; i < 5; ++i)
        {
            cin >> board[i];
        }

        int n; cin >> n;
        for (int i = 0; i < n; ++i)
        {
            string word;
            cin >> word;

            bool find = false;
            for (int y = 0; y < 5; ++y)
            {
                for (int x = 0; x < 5; ++x)
                {
                    if (hasWord(y, x, word))
                    {
                        find = true;
                        break;
                    }
                }

                if (find == true)
                {
                    break;
                }
            }

            cout << word;
            if (find)
            {
                cout << " YES\n";
            }
            else
            {
                cout << " NO\n";
            }
        }

    }

    return 0;
}

int hasWord(int y, int x, const string& word)
{
    // base case 0 - board 밖을 벗어나는 경우
    if (y < 0 || y >= 5 || x < 0 || x >= 5)
    {
        return false;
    }

    // base case 1 - 첫자리가 다른 경우
    if (word[0] != board[y][x])
    {
        return false;
    }

    // base case 2 - 첫자리가 같고 마지막 글자인 경우
    if (word.size() == 1)
    {
        return true;
    }

    for (int direction = 0; direction < 8; ++direction)
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
