#include <iostream>

int main ()
{
    int n; int k;
    std::cin >> n >> k;

    std::string attNames[n];
    int currentScore[n];

    for (int i = 0; i < n; i++)
    {
        std::cin >> attNames[i] >> currentScore[i];
    }

    int l;
    std::cin >> l;

    int eventCount[n] = { 0 };
    int thresholdEventCount[n] = { 0 };

    int threshold[n];

    for (int i = 0; i < l; i++)
    {
        std::string str; int value;
        std::cin >> str >> value;

        for (int j = 0; j < n; j++)
        {
            if (str == attNames[j])
            {
                eventCount[j]++;
                if (value > threshold[j])
                {
                    threshold[j] = value;
                    if (value > currentScore[j])
                    {
                        thresholdEventCount[j] = 1;
                        k -= (value - currentScore[j]);
                        currentScore[j] = value;
                        if (k < 0) { std::cout << 0 << std::endl; return 0; }
                    }
                }
                else if (value == currentScore[j] && value == threshold[j])
                {
                    thresholdEventCount[j]++;
                }
            }
        }
    }

    int maxGain = 0;
    int maxGainIndex = 0;
    
    int gain[n];
    for (int i = 0; i < n; i++)
    {
        gain[i] = thresholdEventCount[i] * threshold[i] + eventCount[i];
        if (maxGain < gain[i]) { maxGain = gain[i]; maxGainIndex = 0; }
    }
    



    return 0;
}