#include <iostream>
#include <vector>

int main ()
{
    const int size = 1000;
    const int binarySize = 12;
    int arr[size];

    for (int j = 0; j < size; j++)
    {
        std::string str;
        std::cin >> str;

        int newNum = 0;

        for (int i = 0; i < binarySize; i++)
        {
            newNum = newNum << 1;
            switch (str[i])
            {
            case '0': break;
            case '1': newNum++; break;
            }
        }

        arr[j] = newNum;
    }

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    } std::cout << std::endl;
    

    int maxMask = 0;
    int minMask = 0;

    int minAdjustedSize = size;
    int maxAdjustedSize = size;

    for (int i = (binarySize - 1); i >= 0; i--)
    {
       int minZeroCount = 0;
       int maxZeroCount = 0;
       for (int j = 0; j < size; j++)
       {
           if ( (arr[j] >> i) == minMask )
           {
               minZeroCount++;
           }
           if ( (arr[j] >> i) == maxMask )
           {
               maxZeroCount++;
           }
        }

        int a = minAdjustedSize - minZeroCount;
        int b = maxAdjustedSize - maxZeroCount;

        if (minZeroCount == 0) { minMask++; minAdjustedSize = a; }
        else if (a == 0) { minAdjustedSize = minZeroCount; }
        else if (minZeroCount > a) { minMask++; minAdjustedSize = a; }
        else { minAdjustedSize = minZeroCount; }

        if (maxZeroCount == 0) { maxMask++; maxAdjustedSize = b; }
        else if (b == 0) { maxAdjustedSize = maxZeroCount; }
        else if (maxZeroCount <= b) { maxMask++; maxAdjustedSize = b; }
        else { maxAdjustedSize = maxZeroCount; }

        minMask = minMask << 1; maxMask = maxMask << 1;

        std::cout << i << ": " << minZeroCount << " " << a << " " << maxZeroCount << " " << b << std::endl;
        std::cout << minMask << " " << maxMask << std::endl;
    }

    maxMask = maxMask >> 1;
    minMask = minMask >> 1;

    std::cout << minMask << " UWU " << maxMask << std::endl;
    

    return 0;
}