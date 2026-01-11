#include <iostream>

void reverseHelper(char *c, int len, int k)
{
    if (!*c || k >= len / 2)
    {
        return;
    }

    std::swap(c[k], c[len - 1 - k]);

    reverseHelper(c, len, k + 1);
}

// void reverse(const char *c)
// {
//     if (!*c)
//     {
//         return;
//     }
//     reverse(c + 1);
//     std::cout << *c;
// }

int main()
{
    char str[] = "I'm Ivan";
    reverseHelper(str, strlen(str), 0);
    std::cout << str;
}