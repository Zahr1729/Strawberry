#include <iostream>
#include <math.h> 
#include <string>


int main ()
{
    int t;
    std::cin >> t;

    int outputs[t];

    for (int i = 0; i < t; i++)
    {

        long long n; long long k;
        std::cin >> n >> k;


        long long computersServed = 1;
        long long hoursTaken = 0;

        while (computersServed < k)
        {
            hoursTaken++;
            computersServed *= 2;
            //std::cout << "Data 1: " << hoursTaken << " " << (n - computersServed) << std::endl;
        }

        //std::cout << "UwU";
        long long compRem = n - computersServed;

        hoursTaken += (compRem + k - 1) / k;
        
        outputs[i] = hoursTaken;
    }


    for (int i = 0; i < t; i++)
    {
        std::cout << outputs[i] << std::endl;
    }
    
    

    return 0;
}