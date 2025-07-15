#include <iostream>


int main ()
{
    int * array[100];

    for (int i = 0; i < 100; i++)
    {
        int n = i;
        int * arr = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[j] = (j+1) * n;
        }
        array[i] = arr;
    }

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < i; j++)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;   
    }  

    return 0;
}