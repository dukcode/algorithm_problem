// 0706.cpp -- 쿼드 트리 뒤집기 문제를 해결하는 분할 정복 알고리즘
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string reverseString(string::iterator& it);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    //freopen("", "r", stdin);

    int testCase; cin >> testCase;

    while (testCase--)
    {
        string s; cin >> s;
        string::iterator it = s.begin();
        cout << reverseString(it) << '\n';
    }

    return 0;
}

string reverseString(string::iterator& it)
{
    char head = *(it++);

    if (head == 'b' || head == 'w')
    {
        return string(1, head);
    }

    string upperLeft = reverseString(it);
    string upperRight = reverseString(it);
    string lowerLeft = reverseString(it);
    string lowerRight = reverseString(it);

    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}
