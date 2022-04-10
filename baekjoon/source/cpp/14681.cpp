// 14681.cpp -- 사분면 고르기
#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int x; int y;
    cin >> x >> y;

    if (x > 0)
    {
        if (y > 0)
        {
            cout << 1 << '\n';
        }
        else
        {
            cout << 4 << '\n';
        }

    }
    else
    {
        if (y > 0)
        {
            cout << 2 << '\n';
        }
        else
        {
            cout << 3 << '\n';
        }
    }

    return 0;
}

