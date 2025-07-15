#include <iostream>

int main ()
{
    int t;
    std::cin >> t;

    std::string outputs[t];
    
    for (int i = 0; i < t; i++)
    {
        // Do that case
        std::string input;
        std::cin >> input;
        int size = input.size();

        if (input[0] != input[size - 1])
        {
            char difference = (input[0] == 'b') ? 'a' : 'b';
            input = difference + input.substr(1, size - 1);
        }

        outputs[i] = input;
    }

    for (int i = 0; i < t; i++)
    {
        std::cout << outputs[i] << std::endl;
    }
    
    

    return 0;
}