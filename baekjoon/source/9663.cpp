// 9663.cpp -- N-Queen
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_COL = 14;
const int MAX_ROW = 14;

int n;

int board[MAX_COL];

int getNumOfCases(int col);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    // freopen("9663_input.txt", "r", stdin);

    cin >> n;

    cout << getNumOfCases(0) << '\n';

    return 0;
}

int getNumOfCases(int col)
{
    // base case
    if (col == n)
    {
        return 1;
    }

    bool isImpossible[14];
    memset(isImpossible, false, sizeof(isImpossible));
    for (int colBefore = 0; colBefore < col; ++colBefore)
    {
        int rowBefore = board[colBefore];
        isImpossible[rowBefore] = true;

        int rightUpper = (rowBefore + colBefore - col);     // ↗
        if (0 <= rightUpper && rightUpper < n)
        {
            isImpossible[rightUpper] = true;
        }
        
        int rightLower = (rowBefore - colBefore + col);     // ↘
        if (0 <= rightLower && rightLower < n)
        {
            isImpossible[rightLower] = true;
        }

    }

    int ret = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!isImpossible[i])
        {
            board[col] = i;
            ret += getNumOfCases(col + 1);
        }
    }

    return ret;
}
