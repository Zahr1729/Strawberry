#include <iostream>

int main ()
{
    int n;
    std::cin >> n;

    int arr[n];
    arr[0] = 1;
    for (int i = 0; i < n - 1; i++)
    {
        int d;
        std::cin >> d;
        arr[d+1] = (i+2);
    }
    

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    

    return 0;
}