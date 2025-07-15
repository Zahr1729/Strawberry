#include <iostream>

long Power (int base, int exponent)
{
    long runningTotal = 1;
    for (long i = 0; i < exponent; i++)
    {
        runningTotal *= base;
    }
    return runningTotal;
}

int main ()
{
    int t;
    std::cin >> t;

    long outputs[t] = { 0 };
    long biggies[t] = { 0 };

    for (int j = 0; j < t; j++)
    {
        int n; long k;
        std::cin >> n >> k;
        k++;

        int powers[n];

        for (int i = 0; i < n; i++)
        {
            std::cin >> powers[i];
        }

        long minOutput = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (k <= 0) { break; }
            if (i == (n - 1))
            {
                //std::cout << "BIG BOIS ";
                //std::cout << k << " " << Power(10, powers[i]);
                biggies[j] = k;
                break;
            }
            else 
            {
                long difference = Power(10, (powers[i + 1] - powers[i])) - 1;
                long powerOfTen = Power(10, powers[i]);

                //std::cout << difference << " " << powerOfTen << std::endl;

                if (k <= difference) { minOutput += powerOfTen * k; k -= k; }
                else { minOutput += powerOfTen * difference; k -= difference; }
            }

            //std::cout << minOutput << std::endl;
            //std::cout << "K left: " << k << std::endl;
        }

        outputs[j] = minOutput;

        /*
        for (int i = 0; i < n; i++)
        {
            std::cout << powers[i] << " ";
        } std::cout << std::endl;
        */
    }

    for (int i = 0; i < t; i++)
    {
        if (biggies[i] != 0) { std::cout << biggies[i]; }
        std::cout << outputs[i] << std::endl;
    }
    
    

    return 0;
}