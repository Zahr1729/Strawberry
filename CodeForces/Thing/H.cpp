#include <iostream>
#include <math.h>
#include <iomanip>

int main ()
{
    int n;
    std::cin >> n;
    
    bool output[n];
    int data[n];

    for (int i = 0; i < n; i++)
    {
        char c;
        std::cin >> c >> data[i];
        output[i] = (c == 'I') ? true : false;
    }
    

    for (int i = 0; i < n; i++)
    {
        if (output[i])
        {
            int count = data[i];
            int usedData[count];
            int j = i - 1;
            int numberFound = 0;
            while (numberFound < count)
            {
                if (output[j] == true) { j--; continue; }
                usedData[numberFound] = data[j];
                j--; numberFound++;
            }

            double total = 0;
            for (int i = 0; i < count; i++) { total += usedData[i]; }
            double average = total / count;

            double sum = 0;
            for (int i = 0; i < count; i++) { sum += (usedData[i] - average) * (usedData[i] - average); }

            double sd = (std::sqrt(sum)) / count;

            double lower = average - 2 * sd;
            double upper = average + 2 * sd;

            std::cout << std::setprecision(8) << lower << " " << upper << std::endl;
        }
    }
    
    

    return 0;
}