#include <random>
#include <iostream>

int main(void)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 9);

    for (int i = 0; i < 10; i++)
    {
        for (int i = 0; i < 4; i++)
        {
            std::cout << dist(mt);
        }
    std::cout << std::endl;
    }

    return 0;
}
