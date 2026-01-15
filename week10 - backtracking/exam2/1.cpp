#include <cassert>
#include <iostream>
#include <cstring>
#include <cmath>

const int MAX_CODE_SIZE = 10, BASE = 31;

void inputShipment(char *&input)
{
    assert(input == nullptr);
    int n;
    std::cin >> n;
    // 1 for space between code and package and 1 for \0
    input = new char[n + 1 + MAX_CODE_SIZE + 1];
    std::cin.ignore();
    std::cin.getline(input, n + 1);
}

int createChecksum(const char *shipment)
{
    int package = 0, curr = 0, cnt = 0, size = strlen(shipment) + 1;
    while (size--)
    {
        if (*shipment == ' ' || !*shipment)
        {
            package += curr * pow(BASE, cnt);
            curr = 0;
            cnt++;
        }
        else
        {
            curr += *shipment;
        }

        shipment++;
    }
    return package;
}

int reverse(int n)
{
    int reverse = 0;
    while (n)
    {
        reverse = reverse * 10 + n % 10;
        n /= 10;
    }
    return reverse;
}

void packingShipment(char *shipment)
{
    int checksum = createChecksum(shipment);
    checksum = reverse(checksum);
    int shipmentIndex = strlen(shipment);
    shipment[shipmentIndex++] = ' ';
    while (checksum)
    {
        shipment[shipmentIndex++] = checksum % 10 + '0';
        checksum /= 10;
    }
}

int stoi(char *start)
{
    int result = 0;
    while (isdigit(*start))
    {
        result = result * 10 + (*start - '0');
        start++;
    }

    return result;
}

bool inspectShipment(const char *package)
{
    int size = strlen(package);
    char *copy = new char[size + 1];
    strcpy(copy, package);

    char *end = copy + size - 1;
    while (isdigit(*end))
        end--;

    *end = '\0';
    int checksum = createChecksum(copy);
    *end = ' ';
    int expected = stoi(end + 1);

    delete[] copy;
    return expected == checksum;
}

int main()
{
    assert(createChecksum("mug snow-man") == 25625);
    assert(inspectShipment("mug snow-man 25625"));
    assert(inspectShipment("mug snow-woman 25625") == false);

    char *shipment = nullptr;
    inputShipment(shipment);
    packingShipment(shipment);
    std::cout << std::boolalpha << inspectShipment(shipment);
}