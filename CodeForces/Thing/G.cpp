#include <iostream>

void Sort (int * arr, int size)
{
    for (int i = 0; i < size-1; i++)
    {
        bool flag = false;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = true;
            }
        }
        if (flag == false) return;
    }
}

int main ()
{
    int n;
    std::cin >> n;
    int days[n];
    long daySum[n];

    long totalSum = 0;
    int maxVal = 0;
    for (int i = 0; i < n; i++)
    {
        std::string name;
        std::cin >> name >> days[i];
        totalSum += days[i];
        daySum[i] = totalSum;
        if (days[i] > maxVal) { maxVal = days[i]; }
    }

    Sort(days, n);

    long f;
    std::cin >> f;

    int boundaryIndex = 0;
    for (int i = 1; i < maxVal; i++)
    {
        // Adjust boundaryIndex
        while (i > days[boundaryIndex]) { boundaryIndex++; }
        
        long lowerSum = 0;
        
        if (boundaryIndex != 0) { lowerSum += daySum[boundaryIndex - 1]; }
        lowerSum += (n - boundaryIndex) * i;

        if ((lowerSum + f) > totalSum) { std::cout << i << std::endl; break; }
    }
    
    return 0;
}