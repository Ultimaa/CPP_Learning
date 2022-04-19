#include <iostream>
#include <string>
std::string add(std::string first, std::string second)
{
    std::string result;
    int modulo(0);
    while (first.length() != second.length())
    {
        if (first.length() > second.length())
        {
            second.insert(0, "0");
        } else
        {
            first.insert(0, "0");
        }
    }
    for (int i = first.length(); i > 0; i--)
    {
        int tmp = (first[i - 1] - '0') + (second[i - 1] - '0');
        tmp += modulo;
        modulo = 0;
        if (tmp >= 10)
        {
            modulo++;
            result.insert(0, std::to_string(tmp % 10));
        } else
        {
            result.insert(0, std::to_string(tmp));
        }
    }
    if (modulo == 1)
    {
        result.insert(0, "1");
    }

    return result;
}
/**
 * Main function commented for gtest
 * Delete comment if you want to add this for judge in SPOJ
 *
int main()
{
    int n;
    std::cin >> n;
    std::string* firstNumber = new std::string[n];
    std::string* secondNumber = new std::string[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> firstNumber[i] >> secondNumber[i];
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << add(firstNumber[i], secondNumber[i]) << "\n";
    }
    delete[] firstNumber;
    delete[] secondNumber;
}

**/ 