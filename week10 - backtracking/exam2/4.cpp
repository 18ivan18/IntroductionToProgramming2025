#include <iostream>

bool isPossible(size_t *arr, size_t size, size_t trees, size_t x)
{
    size_t last = 0;
    size_t counter = 1;
    for (size_t i = 1; i < size; i++)
    {
        if (arr[i] - arr[last] >= x)
        {
            last = i;
            counter++;
        }
    }

    return (counter - trees) == 0;
}

size_t findDistance(size_t *arr, size_t trees, size_t size)
{
    size_t l = 0, r = arr[size - 1] - arr[0], distance = 0;
    while (l <= r)
    {
        size_t mid = (l + r) / 2;
        if (isPossible(arr, size, trees, mid))
        {
            distance = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return distance;
}

void sortArray(size_t *arr, size_t size)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        size_t minInd = i;
        for (size_t j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minInd])
            {
                minInd = j;
            }
        }

        std::swap(arr[i], arr[minInd]);
    }
}

int main()
{
    size_t n = 0, k = 0;
    std::cin >> n >> k;
    size_t *arr = new size_t[n];
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    sortArray(arr, n);
    std::cout << findDistance(arr, k, n);

    delete[] arr;
}