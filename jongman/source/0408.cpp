// 0408.cpp -- 선택정렬, 삽입정렬
#include <iostream>
#include <vector>

using namespace std;

void SelectionSort(vector<int>& A)
{
    for (int i = 0; i < A.size(); i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < A.size(); j++)
        {
            if (A[j] < minIndex)
            {
                minIndex = j;
            }
        }

        swap(A[minIndex], A[i]);
    }
}

void InsertionSort(vector<int>& A)
{
    for (int i = 0; i < A.size(); i++)
    {
        int j = i;
        while (j > 0 && A[j - 1] > A[j])
        {
            swap(A[j - 1], A[j]);
            j--;
        }
    }
}
void InsertionSort2(vector<int>& A)
{
    for (int i = 0; i < A.size(); i++)
    {
        int j = i;
        while (j < A.size() - 1 && A[j] > A[j + 1])
        {
            swap(A[j], A[j + 1]);
            j++;
        }
    }
}

int main(void)
{
    vector<int> arr1;
    for (int i = 0; i < 10; i++)
    {
        arr1.push_back(10 - i);
    }
    vector<int> arr2;
    for (int i = 0; i < 10; i++)
    {
        arr2.push_back(10 - i);
    }

    InsertionSort(arr1);
    for(int i = 0; i < arr1.size(); i++)
    {
        cout << arr1[i] << ' ';
    }
    cout << endl;

    InsertionSort2(arr1);
    for(int i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i] << ' ';
    }
    cout << endl;

    return 0;
}
