#include <iostream>

int main ()
{
    int count = 0;
    int threeNumbers[3];

    std::cin >> threeNumbers[0] >> threeNumbers[1] >> threeNumbers[2];

    while (true)
    {
        int a;
        std::cin >> a;
        if (a > threeNumbers[0]) { count++; }
        threeNumbers[0] = threeNumbers[1];
        threeNumbers[1] = threeNumbers[2];
        threeNumbers[2] = a;
        std::cout << count << "\n";
    }

    return 0;
}