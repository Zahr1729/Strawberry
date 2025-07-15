#include <iostream>


int main ()
{
    int n;
    std::cin >> n;

    int b[n]; int p[n];

    long long totalB = 0;
    long long totalP = 0;

    int maxB = -100000000; int minB = 100000000;
    int maxP = -100000000; int minP = 100000000;
    

    for (int i = 0; i < n; i++)
    {
        
        std::cin >> b[i] >> p[i];
        
        totalB += b[i]; totalP += p[i];

        if (b[i] > maxB) { maxB = b[i]; }
        if (b[i] < minB) { minB = b[i]; }

        if (p[i] > maxP) { maxP = p[i]; }
        if (p[i] < minP) { minP = p[i]; }
    }

    long long bValue = maxB + minB;
    long long pValue = maxP + minP;

    


    //std::cout << totalP << " " << pValue << " Kay " << (totalP / pValue) << std::endl;
    
    if (totalP != (pValue * n / 2)) { std::cout << "impossible" << std::endl; return 0; }
    if (totalB != (bValue * n / 2)) { std::cout << "impossible" << std::endl; return 0; }

    //std::cout << maxB << " " << minB << " " << maxP << " " << minP << std::endl;

    //std::cout << maxB << " " << minB << " " << maxP << " " << minP << std::endl;

    //std::cout << bValue << " " << pValue << std::endl;

    bool indexsUsed[n] = { false };

    for (int i = 0; i < n; i++)
    {
        if (indexsUsed[i] == true) { continue; }
        int pNeeded = pValue - p[i];
        int bNeeded = bValue - b[i];
        //std::cout << b[i] << " " << p[i] << " : " << bNeeded << " " << pNeeded << std::endl;
        indexsUsed[i] = true;
        bool flag = false;
        for (int j = (i + 1); j < n; j++)
        {
            if (indexsUsed[j] == false)
            {
                if (p[j] == pNeeded)
                {
                    if (b[j] == bNeeded)
                    {
                        flag = true;
                        indexsUsed[j] = true;
                        break;
                    }
                }
            }
        }
        
        if (flag == false) { std::cout << "impossible" << std::endl; return 0; }
    }

    std::cout << "possible" << std::endl;
    

    return 0;
}