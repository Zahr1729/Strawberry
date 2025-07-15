#include <iostream>

void SortArray (int * arr, int size, int * indexArr)
{
    for (int i = 0; i < size-1; i++)
    {
        bool flag = false;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[indexArr[j]] > arr[indexArr[j+1]])
            {
                int temp = indexArr[j];
                indexArr[j] = indexArr[j+1];
                indexArr[j+1] = temp;
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

    int c[n]; int t[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> c[i] >> t[i];
    }

    int cIndex[n];
    for (int i = 0; i < n; i++)
    {
        cIndex[i] = i;
    }

    SortArray(c, n, cIndex);

    /*
    for (int i = 0; i < n; i++)
    {
        std::cout << cIndex[i] << " ";
    } std::cout << std::endl;
    */

    int output = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (c[cIndex[i]] == c[cIndex[j]]) { continue; }
            if (t[cIndex[i]] >= t[cIndex[j]]) { continue; }
            for (int k = j + 1; k < n; k++)
            {
                if (c[cIndex[j]] == c[cIndex[k]]) { continue; }
                if (t[cIndex[j]] >= t[cIndex[k]]) { continue; }
                output++;
                //std::cout << i << " " << j << " " << k << std::endl;
            }
        }
    }
    
    std::cout << output << std::endl;
    
    

    return 0;
}