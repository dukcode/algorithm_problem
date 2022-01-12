// 0407.cpp -- 선형 탐색
#include <iostream>
#include <vector>

int GetFirstIndex(const vector<int>& array, int element)
{
    for (int i = 0; i < array.size(); i++)
    {
        if (element == array[i])
        {
            return i;
        }
    }
    return -1;
}
