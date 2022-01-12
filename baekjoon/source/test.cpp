// test.cpp
#include <cstdio>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for (int a = 0; a <= 50; ++a)
    for (int b = 0; b <= 50; ++b)
    for (int c = 0; c <= 50; ++c)
        cout << a << ' ' << b << ' ' << c << '\n';


    return 0;
}

