// 0912.cpp -- 드래곤 커브 문자열을 생성하는 재귀 호출 알고리즘
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

const int MAX = 1000000000 + 1;

int length[51];

const string EXPAND_X = "X+XF";
const string EXPAND_Y = "FX-Y";

int n;
int p;
int l;

void preCalc(void);
void curve(const string& seed, int generations);
char expand(const string& dragonCurve, int generations, int skip);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("0912_input.txt", "r", stdin);

    int testCase; cin >> testCase;
    while (testCase--)
    {
        cin >> n >> p >> l;
    }

    return 0;
}

void preCalc(void)
{
    length[0] = 1;
    for (int i = 1; i <= 50; ++i)
    {
        length[i] = min(MAX, 2 * length[i - 1] + 2);
    }
}

void curve(const string& seed, int generations)
{
    if (generations == 0)
    {
        cout << seed << '\n';
        return;
    }

    for (int i = 0; i < seed.size(); ++i)
    {
        if (seed[i] == 'X')
        {
            curve("X+YF", generations - 1);
        }
        else if (seed[i] == 'Y')
        {
            curve("FX=Y", generations - 1);
        }
        else
        {
            cout << seed[i];
        }
    }
}

char expand(const string& dragonCurve, int generations, int skip)
{
    // base case
    if (generation == 0)
    {
        assert(skip < dragonCurve.size());
        return dragonCurve[skip];
    }

    for (int i = 0; i < dragonCurve.size(); ++i)
    {
        if (dragonCurve[i] == 'X' || dragonCurve[i] == 'Y')
        {
            if (skip >= length[generations])
            {
                skip -= length[generations];
            }
            else if (dragonCurve[i] == 'X')
            {
                return expand(EXPAND_X, generations - 1, skip);
            }
            else
            {
                return expand(EXPAND_Y, generations - 1, skip);
            }
        }
        else if (skip > 0)
        {
            --skip;
        }
        else
        {
            return dragonCurve[i];
        }
    }

    return '#';
}
