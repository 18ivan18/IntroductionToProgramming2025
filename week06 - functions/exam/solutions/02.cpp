#include <iostream>

int main()
{
    const size_t MAX_SIZE = 1024;
    size_t size;
    std::cin >> size;

    int numbers[MAX_SIZE];
    for (size_t i = 0; i < size; ++i)
    {
        std::cin >> numbers[i];
    }

    int delta[MAX_SIZE];
    for (size_t i = 0; i < size; ++i)
    {
        delta[i] = numbers[i] - i;
    }

    bool participates[MAX_SIZE] = {false};

    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = i + 1; j < size; ++j)
        {
            if (delta[i] == delta[j])
            {
                participates[i] = true;
                participates[j] = true;
            }
        }
    }

    // тук намораме най-ляв и най-десен участващ индекс
    size_t left = size + 1, right = 0;
    for (size_t i = 0; i < size; ++i)
    {
        if (participates[i])
        {
            if (i < left)
            {
                left = i;
            }
            if (i > right)
            {
                right = i;
            }
        }
    }

    bool printed = false;

    for (size_t i = left + 1; i <= right - 1; ++i)
    {
        if (participates[i])
        {
            if (printed)
            {
                std::cout << ' ';
            }
            std::cout << i;
            printed = true;
        }
    }

    if (!printed)
    {
        std::cout << "none";
    }

    std::cout << std::endl;
}
