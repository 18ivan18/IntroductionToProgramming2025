#include <iostream>

int main()
{
    unsigned long x, v = 0, power = 1;
    const int BASE = 2;

    std::cin >> x;

    bool lastBit = x % BASE;
    x /= BASE;

    while (x > 0)
    {
        bool bit = x % BASE;
        x /= BASE;

        v += (bit == lastBit ? !lastBit : lastBit) * power;
        power *= BASE;

        lastBit = bit;
    }

    v += lastBit * power;

    std::cout << v << std::endl;
}