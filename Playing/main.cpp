#include <iostream>
#include <math.h>

namespace Strawberries
{


    void Core ()
    {
        double i = 1;
        double n = 1;

        do
        {
            if (n > 10000000) { std::cout << n << " Good\n"; return; }
            n++;
            i = i / (1 + std::sqrt(i));
        } while (i <= 1 / n && i >= ( 1 / (n*n) ));
        std::cout << n << " Bad\n";
    }
}


int main ()
{
    Strawberries::Core();

    return 0;
}
