// 0914.cpp -- 순열의 사전순 번호 찾기
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int factorial[11];

void preCalc(void);
int getIndex(const vector<int>& X);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    //freopen("0914_input.txt", "r", stdin);

    preCalc();

    vector<int> X(0, 10);
    for (int i = 0; i < X.size(); ++i)
    {
        cin >> X[i];
    }
    cout << getIndex(X) << '\n';

    return 0;
}

void preCalc(void)
{
    factorial[0] = 1;
    for (int i = 1; i < 11; ++i)
    {
        factorial[i] = factorial[i - 1] * i;
    }
}

int getIndex(const vector<int>& X)
{
    int ret = 0;

    for (int i = 0; i < X.size(); ++i)
    {
        int less = 0;
        for (int j = i + 1; j < X.size(); ++j)
        {
            if (X[i] > X[j])
            {
                ++less;
            }
        }

        ret += factorial[X.size() - i - 1] * less;
    }

    return ret;
}
