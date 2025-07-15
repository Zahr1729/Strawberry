#include <iostream>
#include <math.h>

int main ()
{
    int N; double P;
    std::cin >> N >> P;

    double guess = N - 1;
    for (int i = 0; i < 50; i++)
    {
        // Newton Raphson multiple times
        guess -= (guess * guess * guess - 3 * guess * N * N + P * N * N * N) / (3 * guess * guess - 3 * N * N);
    }
    
    std::cout << std::ceil(guess);

    return 0;
}