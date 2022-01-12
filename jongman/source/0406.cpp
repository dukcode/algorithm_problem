// 0406.cpp -- 가장 간단한 형태의 소인수 분해 알고리즘
#include <iostream>
#include <vector>

using namespace std;

vector<int> getFactor(int n);

int main(void)
{
    int num;
    cin >> num;

    vector<int> factor = getFactor(num);
    for (int i = 0; i < factor.size(); i++)
    {
        cout << factor[i] << ' ';
    }
    cout << endl;

    return 0;
}
vector<int> getFactor(int n)
{
    vector<int> ret;

    for (int div = 2; n > 1; div++)
    {
        while (n % div == 0)
        {
            n /= div;
            ret.push_back(div);
        }
    }

    return ret;
}
