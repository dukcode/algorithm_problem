//0705.cpp -- 쿼드 트리 압축을 해제하는 재귀 호출 알고리즘
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 1 << 5; // 원래는 20
char decompressed[MAX_SIZE][MAX_SIZE];

void decompress(string::iterator& it, int y, int x, int size);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    // freopen("", "r", stdin);

    int testCase; cin >> testCase;

    while (testCase--)
    {
        string s; cin >> s;
        string::iterator it = s.begin();
        decompress(it, 0, 0, MAX_SIZE);
        for (int y = 0; y < MAX_SIZE; y++)
        {
            for (int x = 0; x < MAX_SIZE; x++)
            {
                cout << decompressed[y][x];
                decompressed[y][x] = 0;
            }
            cout << '\n';
        }
    }

    return 0;
}

void decompress(string::iterator& it, int y, int x, int size)
{
    char head = *(it++);

    if (head == 'b' || head == 'w')
    {
        for (int dy = 0; dy < size; dy++)
        {
            for (int dx = 0; dx < size; dx++)
            {
                decompressed[y + dy][x + dx] = head;
            }
        }
    }
    else
    {
        int half = size / 2;
        decompress(it, y, x, half);
        decompress(it, y, x + half, half);
        decompress(it, y + half, x, half);
        decompress(it, y + half, x + half, half);
    }
}
