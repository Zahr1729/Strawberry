#include <iostream>
#include <cstdlib>
#include <math.h>

int main ()
{
    // Setup data
    int t;
    std::cin >> t;

    int * testcases[t];
    int arraySize[t];
    double averages[t];
    for (int i = 0; i < t; i++)
    {
        int n;
        std::cin >> n;
        arraySize[i] = n;
        int * array = (int*) malloc(sizeof(int) * n); // Allocate the needed memory
        testcases[i] = array;
        

        double sum = 0;

        for (int j = 0; j < n; j++)
        {
            int a_j;
            std::cin >> a_j;
            sum += a_j;
            array[j] = a_j;
        }

        averages[i] = (sum / n);
    }

    // Compute
    for (int i = 0; i < t; i++)
    {
        int * array = testcases[i];
        int size = arraySize[i];
        double average = averages[i];

        if ((average * 2 - std::floor(average * 2)) != 0) { continue; }

        long countOfPossibles = 0;
        for (int j = 0; j < size - 1; j++)
        {
            for (int k = j + 1; k < size; k++)
            {
                int sum = array[j] + array[k];
                if (sum == average * 2) { countOfPossibles++; }
            }
            
        }
        std::cout << countOfPossibles << std::endl;
    }
    
    

    return 0;
}