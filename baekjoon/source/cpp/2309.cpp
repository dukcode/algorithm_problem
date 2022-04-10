// 2309.cpp -- 일곱 난쟁이
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool findDwarf(const vector<int>& height, vector<int>& list, bool taken[], int index);

int main(int argc, char** argv)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    //freopen("", "r", stdin);

    vector<int> height(9);
    for (int i = 0; i < 9; i++)
    {
        cin >> height[i];
    }

    vector<int> list;
    bool taken[9];
    for (int i = 0; i < 9; i++)
    {
        taken[i] = false;
    }
    findDwarf(height, list, taken, 0);


    return 0;
}


bool findDwarf(const vector<int>& height, vector<int>& list, bool taken[], int index)
{
    // base case : 난쟁이를 다 뽑고 키의 합이 100이면 return
    if (list.size() == 7)
    {
        int sum = 0;
        for (int i = 0; i < 7; i++)
        {
            sum += list[i];
        }

        if (sum == 100)
        {
            sort(list.begin(), list.end());
            for (int i = 0; i < list.size(); i++)
            {
                cout << list[i] << endl;
            }
            cout << endl;

            return true;
        }
    }

    for (int next = index; next < 9; next++)
    {
        if (taken[next])
        {
            continue;
        }
        taken[next] = true;
        list.push_back(height[next]);
        if (findDwarf(height, list, taken, index + 1))
        {
            return true;
        }
        taken[next] = false;
        list.pop_back();
    }

    return false;
}
