// 0907.cpp -- k - 1개 건너뛰고 첫 번째 신호를 출력하는 알고리즘
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int skip;

void generate(int n, int m, string s);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    int m; cin >> m;
    cin >> skip;

    string s;
    generate(n, m, s);

    return 0;
}

void generate(int n, int m, string s)
{
    if (skip < 0)
    {
        return;
    }

    if (n == 0 && m == 0)
    {
        if (skip == 0)
        {
            cout << s << '\n';
        }
        --skip;
        return;
    }

    if (n != 0)
    {
        generate(n - 1, m, s + "-");
    }

    if (m != 0)
    {
        generate(n, m - 1, s + "o");
    }
}
