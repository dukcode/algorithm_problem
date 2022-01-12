#include <iostream>
#include <vector>

using namespace std;

int majority1(const vector<int>& A);

int main(void)
{
    vector<int> vec(10);
    for (int i = 0; i < 10; i++)
    {
        cin >> vec[i];
    }

    cout << majority1(vec) << endl;

    return 0;
}

int majority1(const vector<int>& A)
{
    int N = A.size();
    int majority = -1; int majorityCount = 0;

    for (int i = 0; i < N; i++)
    {
        int V = A[i]; int count = 0;
        for (int j = 0; j < N; j++)
        {
            if (A[j] == V)
            {
                count++;
            }
        }

        if (count > majorityCount)
        {
            majorityCount = count;
            majority = V;
        }
    }

    return majority;
}
