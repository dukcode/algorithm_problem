#include <iostream>

void merge(int* arrN, int n, int* arrM, int m)
{
    int idxArrN = n - 1;
    int idxArrM = m - 1;
    int writingIdx = n + m - 1;

    while (idxArrN >= 0 && idxArrM >= 0)
    {
        int numN = arrN[idxArrN];
        int numM = arrM[idxArrM];

        if (numN < numM)
        {
            arrN[writingIdx] = numM;
            idxArrM--;
            writingIdx--;
        }
        else
        {
            arrN[writingIdx] = numN;
            idxArrN--;
            writingIdx--;
        }
    }

    while (idxArrM >= 0)
    {
        arrN[writingIdx] = arrM[idxArrM];
        idxArrM--;
        writingIdx--;
    }
}

int main(void)
{
    int arrN[9] = {4, 67, 78, 89, 100, 0, 0, 0, 0};
    int arrM[4] = {1, 51, 59, 88};

    merge(arrN, 5, arrM, 4);
    for (int i = 0; i < 9; ++i)
    {
        std::cout << arrN[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}
