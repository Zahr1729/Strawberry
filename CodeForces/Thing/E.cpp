#include <iostream>

int main ()
{
    int n;
    std::cin >> n;

    int output[n] = { 0 };
    bool inLine[n] = { false };

    for (int i = 0; i < n; i++)
    {
        int input;
        std::cin >> input;
        int index = input - 1;

        for (int j = index - 1; j >= 0; j--)
        {
            if (inLine[j] == true) { output[i] = (j + 1); break; }
        }

        if (output[i] == 0) { output[i] = -1; }
        inLine[index] = true;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << output[i] << std::endl;
    }

    return 0;
}