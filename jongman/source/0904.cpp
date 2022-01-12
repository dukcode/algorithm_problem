// 0904.cpp -- 광학 문자 인식 문제를 해결하는 동적 계획법 알고리즘
#include <cstdio>
#include <iostream>

using namespace std;

int n; int m;

int R[100];

double T[501][501];

double M[501][501];

int choice[102][502];

double cache[102][502];

string corpus[501];

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("", "r", stdin);

    return 0;
}

double recognize(int segment, int previousMatch)
{
    if (segment == n)
    {
        return 0;
    }

    double& ret = cache[segment][previousMatch];
    if (ret != 1.0)
    {
        return ret;
    }

    ret = 1.0e-200;
    int& choose = choice[segment][previousMatch];

    for (int thisMatch = 0; thisMatch < m; thisMatch++)
    {
        double cand = T[previousMatch][thisMatch] + M[thisMatch][R[segment]] + recognize(segment + 1, thisMatch);

        if (ret < cand)
        {
            ret = cand;
            choose = thisMatch;
        }
    }
}

string reconstruct(int segment, int previousMatch)
{
    int choose = choice[segment][previousMatch];
    string ret = corpus[choose];
    if (sement < n - 1)
    {
        ret = ret + " " + reconstruct(segment + 1, choose);
    }

    return ret;
}
