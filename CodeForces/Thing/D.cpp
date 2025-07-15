#include <iostream>
#include <math.h>

int main ()
{
    int n; int k;
    std::cin >> n >> k;

    int minVolume = 0;
    long totalVolume = 0;

    int volumes[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> volumes[i];
        if (volumes[i] > minVolume) minVolume = volumes[i];
        totalVolume += volumes[i];
    }

    for (int i = minVolume; i < totalVolume; i++)
    {
        
    }
    
    


    return 0;
}