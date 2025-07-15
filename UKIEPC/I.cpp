#include <iostream>

void SortArrays(int * solvedTime, int n, int * time)
{

    for (int i = 0; i < (n-1); i++)
    {
        bool flag = false;
        for (int j = 0; j < (n-1 - i); j++)
        {
            if ((solvedTime[j] > solvedTime[j+1]))
            {
                int temp = solvedTime[j];
                solvedTime[j] = solvedTime[j+1];
                solvedTime[j+1] = temp;

                int temp2 = time[j];
                time[j] = time[j+1];
                time[j+1] = temp2;
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

    int times[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> times[i];
    }
    int minusOneCount = 0;
    int solvedTime[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> solvedTime[i];
        if (solvedTime[i] == -1) { minusOneCount++; }
    }

    SortArrays(solvedTime, n, times);

    /*
    for (int i = 0; i < n; i++)
    {
        std::cout << solvedTime[i] << " " << times[i] << std::endl;
    }
    */

    long long totalCompTime = 0;
    long long maximumTime = 0;
    long long minComputers = 0;

    for (long long i = minusOneCount; i < n; i++)
    {
       if (solvedTime[i] == -1) { continue; }
       
       totalCompTime += times[i];
       maximumTime = solvedTime[i];
       long long newMin = (totalCompTime + maximumTime - 1) / maximumTime;
       if (newMin > minComputers) { minComputers = newMin; }
    }

    //std::cout << totalCompTime << " " << maximumTime << std::endl;
    std::cout << minComputers << std::endl;
    
    

    return 0;
}