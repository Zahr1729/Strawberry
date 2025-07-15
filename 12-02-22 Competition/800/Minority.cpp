#include <iostream>

int main ()
{
    int t; std::cin >> t;
    int outputs[1010];
    for (int i = 0; i < t; i++)
    {
        std::string s; std::cin >> s;
        int size = s.size();
        int zeros = 0;
        for (int j = 0; j < size; j++)
        {
            if (s[j] == '0') { zeros++; }
        }
        
        if (zeros * 2 < size) { outputs[i] = zeros; continue; }
        if (zeros * 2 > size) { outputs[i] = (size - zeros); continue; }
        outputs[i] = zeros - 1;
    }

    for (int i = 0; i < t; i++)
    {
        std::cout << outputs[i] << std::endl;;
    } std::cout << std::endl;
    
    




    return 0;
}