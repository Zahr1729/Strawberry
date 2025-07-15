#include <iostream>
#include <algorithm>

bool compare (int a, int b) { return a > b; }

std::pair<int, int> OrderofMagnitude(int a)
{
    int i = 0;
    while (a >= 10)
    {
        i++;
        a /= 10;
    }
    
    return { i, a };
}

bool MSBcompare (int a, int b)
{
    std::pair<int, int> aP = OrderofMagnitude(a);
    std::pair<int, int> bP = OrderofMagnitude(b);
    if (aP.second > bP.second) { return true; }
    else if (aP.second < bP.second) { return false; }
    else { return MSBcompare(a - )}
}

int main ()
{
    int n; std::cin >> n;
    int numbers[15] = { 0 };
    for (int i = 0; i < n; i++)
    {
        std::cin >> numbers[i];
    }
    std::sort(numbers, numbers + 15, compare);

    int A[8] = { 0 }; int B[8] = { 0 };
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0) { A[i/2] = numbers[i]; }
        else { B[i/2] = numbers[i]; }
    }

    std::sort(A, A+8, MSBcompare);
    std::sort(B, B+8, MSBcompare);

    for (int i = 0; i < 8; i++)
    {
        std::cout << A[i] << " ";
    } std::cout << std::endl;

    for (int i = 0; i < 8; i++)
    {
        std::cout << B[i] << " ";
    } std::cout << std::endl;
    
    
    

    return 0;
}