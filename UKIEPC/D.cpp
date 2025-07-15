#include <iostream>
#include <time.h>


int main ()
{
    
    long long BIGBOI = -100000000000;

    int n;
    std::cin >> n;

    clock_t tStart = clock();
    std::cout << (clock() - tStart) << std::endl;
    
    long points[n];

    for (int i = 0; i < n; i++)
    {
        //std::cin >> points[i];
        points[i] = 2;
    }

    long long maxScore[n][n];   // Score including current index first is index second is size of next jump

    for (int i = 0; i < n; i++) { for (int j = 0; j < n; j++) { maxScore[i][j] = BIGBOI; } }

    for (int i = 0; i < n; i++) { maxScore[n-1][i] = points[n-1]; }
    

    std::cout << (clock() - tStart) << std::endl;
    /*
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << maxScore[j][i] << " ";
        } std::cout << std::endl;
    } */
    
    for (int i = (n - 2); i > -1; i--)
    {
        
        // I is index of thing we want to find max of.
        for (int k = 1; k < (n - i); k++)
        {
            // k is the minimum jump we will allow

            long long maxValue = BIGBOI;
            for (int j = 1; j <= k; j++)
            {
                
                if (maxScore[i+k][j] > maxValue) { maxValue = maxScore[i+k][j]; }
            }
            maxScore[i][k] = maxValue + points[i];
        }

        
    }

    /*
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << maxScore[j][i] << " ";
        } std::cout << std::endl;
    } */

    long long max = BIGBOI;
    for (int i = 0; i < n; i++)
    {
        if (max < maxScore[0][i]) { max = maxScore[0][i]; }
    }
    
    

    std::cout << max << std::endl; 

    std::cout << (clock() - tStart) << std::endl;

    return 0;
}