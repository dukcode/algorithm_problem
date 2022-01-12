// 0401_1.cpp -- 주어진 배열에서 가장 많이 등장하는 숫자를 반환(입력은 0 이상)
#include <iostream>
#include <vector>

int GetMajority(const vector<int>& V)
{
    int majority = -1;
    int size = V.size();
    int majorityCount = 0;

    for (int i = 0; i < size; i++)
    {
        int num = V[i];
        int count = 0;

        for (int j = 0; j < size; j++)
        {
            if (num == V[j])
            {
                count++;
            }
        }

        if (count > majorityCount)
        {
            majorityCount = count;
            majority = num;
        }
    }

    return majorrity;
}
