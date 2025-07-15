#include <bits/stdc++.h>

int main ()
{
    for (int i = 2; i < 11; i++)
    {
        long prod = 1;
        for (int j = 0; j < 7; j++)
        {
            prod *= i;
        }
        long modulo = prod % 7;
        
        std::printf("%d ^ 7 == %d\n", i, (modulo));
    }
    

    return 0;
}