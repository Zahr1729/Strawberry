#include <iostream>

int main ()
{
    int n; long d;
    std::cin >> n >> d;

    long arr[n];
    long max = 0;

    for (int i = 0; i < n; i++)
    {
        long a;
        std::cin >> a;
        if (a > max) { max = a; }
        arr[i] = a;
    }

    long distinct;

    long quotient = 0;
    int index = 0;

    while (quotient*d <= max)
    {
        long lower = quotient*d;
        long upper = lower + d - 1;

        long subCount = 0;
        for (int i = 0; i < n; i++)
        {
            long item = arr[i];
            if (item >= lower && item <= upper) { subCount++; }
        }

        // std::cout << subCount << " " << quotient << std::endl;

        distinct += subCount * (subCount - 1) / 2;

        quotient++;
    }

    std::cout << distinct << std::endl;
    
    


    return 0;
}