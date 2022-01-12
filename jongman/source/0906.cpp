// 0906.cpp -- 모든 모스 신호를 출력하는 완전 탐색 알고리즘
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

void generate(int n, int m, string s);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    int m; cin >> m;

    string s;
    generate(n, m, s);

    return 0;
}

void generate(int n, int m, string s)
{
    if (n == 0 && m == 0)
    {
        cout << s << '\n';
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
