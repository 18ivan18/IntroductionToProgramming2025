#include <iostream>
#include <cctype>
#include <cstring>

int stoi(const char *start)
{
    int result = 0;
    while (isdigit(*start))
    {
        result = result * 10 + (*start - '0');
        start++;
    }

    return result;
}

bool findMaxNumber(const char *str, const char *&maxStart, const char *&maxEnd)
{
    maxStart = maxEnd = nullptr;
    const char *currentStart = nullptr;
    const char *currentEnd = nullptr;
    int maxNumber = 0;

    int size = strlen(str);

    for (size_t i = 0; i <= size; i++)
    {
        const char *p = str + i;

        if (isdigit(*p))
        {
            if (currentStart == nullptr)
            {
                currentStart = p;
            }
            currentEnd = p;
        }

        if (!isdigit(*p) and currentStart)
        {
            int n = stoi(currentStart);
            if (n > maxNumber)
            {
                maxNumber = n;
                maxStart = currentStart;
                maxEnd = currentEnd;
            }
            currentStart = currentEnd = nullptr;
        }
    }

    return (maxStart != nullptr);
}

int main()
{
    const char *start, *end, *str = "p4fd456bc23ll";

    bool hasNumber = findMaxNumber(str, start, end);

    std::cout << std::boolalpha << hasNumber << std::endl;
    if (hasNumber)
    {
        std::cout << "Max number: ";
        for (const char *p = start; p <= end; p++)
        {
            std::cout << *p;
        }
        std::cout << std::endl;
        std::cout << "Start: " << (start - str) << " End: " << (end - str) << std::endl;
    }
}