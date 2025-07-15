#include <iostream>


int main ()
{
    int T; std::cin >> T;
    int nArr[1000];
    for (int abc = 0; abc < T; abc++)
    {
        std::cin >> nArr[abc];
    }

    for (int abc = 0; abc < T; abc++)
    {
        int n = nArr[abc];

        if (n % 7 == 0) { std::cout << n << "\n"; continue; }
        for (int j = 0; j < 10; j++)
        {
            int ans = n - n % 10 + j;
            if (ans % 7 == 0) { std::cout << ans << "\n"; break; }
        }
        
    }
    

    return 0;
}