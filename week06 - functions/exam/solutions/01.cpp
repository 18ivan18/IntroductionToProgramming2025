#include <iostream>

int main()
{
    char cw_1_1, cw_1_2, cw_1_3, cw_1_4;
    char cw_2_1, cw_2_2, cw_2_3, cw_2_4;
    char cw_3_1, cw_3_2, cw_3_3, cw_3_4;
    char cw_4_1, cw_4_2, cw_4_3, cw_4_4;

    std::cin >> cw_1_1 >> cw_1_2 >> cw_1_3 >> cw_1_4;
    std::cin >> cw_2_1 >> cw_2_2 >> cw_2_3 >> cw_2_4;
    std::cin >> cw_3_1 >> cw_3_2 >> cw_3_3 >> cw_3_4;
    std::cin >> cw_4_1 >> cw_4_2 >> cw_4_3 >> cw_4_4;

    int words = 0;
    const char EMPTY = '-';

    if ((cw_1_1 != EMPTY && (cw_1_1 < 'a' || cw_1_1 > 'z')) ||
        (cw_1_2 != EMPTY && (cw_1_2 < 'a' || cw_1_2 > 'z')) ||
        (cw_1_3 != EMPTY && (cw_1_3 < 'a' || cw_1_3 > 'z')) ||
        (cw_1_4 != EMPTY && (cw_1_4 < 'a' || cw_1_4 > 'z')) ||
        (cw_2_1 != EMPTY && (cw_2_1 < 'a' || cw_2_1 > 'z')) ||
        (cw_2_2 != EMPTY && (cw_2_2 < 'a' || cw_2_2 > 'z')) ||
        (cw_2_3 != EMPTY && (cw_2_3 < 'a' || cw_2_3 > 'z')) ||
        (cw_2_4 != EMPTY && (cw_2_4 < 'a' || cw_2_4 > 'z')) ||
        (cw_3_1 != EMPTY && (cw_3_1 < 'a' || cw_3_1 > 'z')) ||
        (cw_3_2 != EMPTY && (cw_3_2 < 'a' || cw_3_2 > 'z')) ||
        (cw_3_3 != EMPTY && (cw_3_3 < 'a' || cw_3_3 > 'z')) ||
        (cw_3_4 != EMPTY && (cw_3_4 < 'a' || cw_3_4 > 'z')) ||
        (cw_4_1 != EMPTY && (cw_4_1 < 'a' || cw_4_1 > 'z')) ||
        (cw_4_2 != EMPTY && (cw_4_2 < 'a' || cw_4_2 > 'z')) ||
        (cw_4_3 != EMPTY && (cw_4_3 < 'a' || cw_4_3 > 'z')) ||
        (cw_4_4 != EMPTY && (cw_4_4 < 'a' || cw_4_4 > 'z')))
    {
        std::cout << "Invalid input!" << std::endl;

        return -1;
    }

    // проверка по редове
    // първи ред
    words += ((cw_1_1 != EMPTY || cw_1_4 != EMPTY) &&
              (cw_1_2 != EMPTY && cw_1_3 != EMPTY));

    // втори ред
    words += ((cw_2_1 != EMPTY || cw_2_4 != EMPTY) &&
              (cw_2_2 != EMPTY && cw_2_3 != EMPTY));

    // трети ред
    words += ((cw_3_1 != EMPTY || cw_3_4 != EMPTY) &&
              (cw_3_2 != EMPTY && cw_3_3 != EMPTY));

    // четвърти ред
    words += ((cw_4_1 != EMPTY || cw_4_4 != EMPTY) &&
              (cw_4_2 != EMPTY && cw_4_3 != EMPTY));

    // първа колона
    words += ((cw_1_1 != EMPTY || cw_4_1 != EMPTY) &&
              (cw_2_1 != EMPTY && cw_3_1 != EMPTY));

    // втора колона
    words += ((cw_1_2 != EMPTY || cw_4_2 != EMPTY) &&
              (cw_2_2 != EMPTY && cw_3_2 != EMPTY));

    // трета колона
    words += ((cw_1_3 != EMPTY || cw_4_3 != EMPTY) &&
              (cw_2_3 != EMPTY && cw_3_3 != EMPTY));

    // четвърта колона
    words += ((cw_1_4 != EMPTY || cw_4_4 != EMPTY) &&
              (cw_2_4 != EMPTY && cw_3_4 != EMPTY));

    std::cout << words << std::endl;
}