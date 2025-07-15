#include <iostream>

int main ()
{
    int number = 10000000;
    int count = 0;

    while (true)
    {
        int a;
        std::cin >> a;
        if (a > number) { count++; }
        number = a;
        std::cout << count << "\n";
    }

    return 0;
}