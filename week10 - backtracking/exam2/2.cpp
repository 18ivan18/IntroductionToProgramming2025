#include <iostream>
#include <cstring>

char *readWord()
{
    int capacity = 8; // initial size
    int length = 0;
    char *word = new char[capacity];

    char c;
    std::cin.get(c);

    // Read letters until whitespace/EOF
    do
    {
        // Resize if needed
        if (length + 1 >= capacity)
        {
            capacity *= 2;
            char *bigger = new char[capacity];
            for (int i = 0; i < length; i++)
            {
                bigger[i] = word[i];
            }
            delete[] word;
            word = bigger;
        }

        word[length++] = c;
    } while (std::cin.get(c) && !isspace(c));

    word[length] = '\0';
    return word;
}

int main()
{
    int n, m;

    do
    {
        std::cout << "Enter number of rows (1-10): ";
        std::cin >> n;
    } while (n < 1 || n > 10);

    do
    {
        std::cout << "Enter number of columns (1-10): ";
        std::cin >> m;
    } while (m < 1 || m > 10);

    std::cin.ignore();

    char ***matrix = new char **[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new char *[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = readWord();
        }
    }

    // Print backwards (bottom→top, right→left)
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            std::cout << matrix[i][j];
            if (j > 0)
                std::cout << ' ';
        }
    }

    // Free memory
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            delete[] matrix[i][j];
        }
        delete[] matrix[i];
    }
    delete[] matrix;
}