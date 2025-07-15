#include <iostream>

int main ()
{
    int zeros[12] = { 0 };
    int ones[12] = { 0 };

    while (true)
    {
        std::string str;
        std::cin >> str;

        for (int i = 0; i < 12; i++)
        {
            switch (str[i])
            {
            case '0': zeros[i]++; break;
            case '1': ones[i]++; break;
            }
        }

        int gamma = 0;

        for (int i = 0; i < 12; i++)
        {
            if (zeros[i] < ones[i])
            {
                gamma += (1 << (11 - i));
            }

            //std::cout << zeros[i] << " " << ones[i] << std::endl;
        }
        
        //std::cout << gamma << std::endl;
        int epsilon = 4095 ^ gamma;
        std::cout << gamma * epsilon << std::endl;
    }

    return 0;
}