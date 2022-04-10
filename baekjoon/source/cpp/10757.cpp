// 10757.cpp -- 큰 수 A + B
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string A;
string B;

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen("10757_input.txt", "r", stdin);

    cin >> A >> B;
    if (A.length() < B.length())
    {
        swap(A, B);
    }


    vector<int> ans;

    for (int i = A.length() - 1; i >= 0; --i)
    {
        ans.push_back(A[i] - '0');
    }

    for (int i = B.length() - 1; i >= 0; --i)
    {
        ans[B.length() - 1 - i] += B[i];
    }

    ans.push_back(0);
    for (int i = 1; i < ans.size() ; ++i)
    {
        if (ans[i - 1] >= 10)
        {
            ans[i] += ans[i - 1] / 10;
            ans[i - 1] /= 10;
        }
    }

    for (int i = ans.size() - 1; i >= 0; --i)
    {
        cout << ans[i];
    }
    cout << '\n';


    return 0;
}

