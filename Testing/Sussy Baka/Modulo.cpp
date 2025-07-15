#include <iostream>

int Compute (int mantissa, int exponent, int moduli)
{
    int value = mantissa;

    for (int i = 0; i < exponent - 1; i++)
    {
        value *= mantissa;
        int temp = value / moduli;
        value -= temp * moduli;
    }
    
    return value;
}


int main ()
{
    int encoded = Compute(35, 7, 187);

    std::cout << encoded << std::endl;

    std::cout << Compute(encoded, 23, 187) << std::endl;

    return 0;
}