#include <iostream>
#include <vector>
#include <random>

void print(const std::vector<int>& v);
void swap(int& a, int& b);

void sortColors(std::vector<int>& data);

int main(void)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 2);

    int n; std::cin >> n;
    std::vector<int> arr(n);
    for (std::size_t idx = 0; idx < n; idx++)
    {
        arr[idx] = dist(mt);
    }

    print(arr);
    std::cout << std::endl;
    sortColors(arr);
    print(arr);


    return 0;
}

void print(const std::vector<int>& v)
{
    for (const int& e : v)
    {
        std::cout << e << ' ';
    }
    std::cout << std::endl;
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void sortColors(std::vector<int>& data)
{
    int idxZero = 0;
    int i = 0;
    int idxTwo = data.size() - 1;

    while (i <= idxTwo)
    {
        if (data[i] == 0)
        {
            swap(data[idxZero], data[i]);
            idxZero++;
            i++;
        }
        else if (data[i] == 2)
        {
            swap(data[idxTwo], data[i]);
            idxTwo--;
        }
        else
        {
            i++;
        }
    }
}

