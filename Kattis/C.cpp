#include <iostream>
#include <stdlib.h>

void QuickSort (long * arr, int size)
{
    if (size <= 1) return;

    bool flag = true;
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] != arr[i+1]) flag = false;
    }
    if (flag) return;
    

    long lower[size];
    long upper[size];
    int lowersize = 0;
    int uppersize = 0;
    long splitvalue = arr[std::rand() % ((size+1) - 1)];

    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= splitvalue) { upper[uppersize] = arr[i]; uppersize++; }
        else { lower[lowersize] = arr[i]; lowersize++; }
    }
    QuickSort(lower, lowersize); QuickSort(upper, uppersize);

    for (int i = 0; i < lowersize; i++)
    {
        arr[i] = lower[i];
    }

    for (int i = 0; i < uppersize; i++)
    {
        arr[lowersize + i] = upper[i];
    }
}

int main ()
{
    int n; long d;
    std::cin >> n >> d;

    long data[n];
    long max = 0;
    long min = 1000000000;
    for (int i = 0; i < n; i++)
    {
        std::cin >> data[i];
        if (data[i] > max) { max = data[i]; }
        if (data[i] < min) { min = data[i]; }
    }

    if (d == 1) {
        
    }

    QuickSort(data, n);
    
    long full = 0;
    int index = 0;
    long quotient = min / d;

    while (index < n)
    {
        long sub = 0;
        long lower = quotient * d;
        long upper = lower + d;
        while (index < n)
        {
            if (data[index] >= upper) { break; }
            sub++;
            index++;
        }

        
        full += sub * (sub - 1) / 2;
        quotient++;
    }
    
    
    std::cout << full << std::endl;   

    return 0;
}