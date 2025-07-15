#include <iostream>

int main ()
{
    int y = 0; int x = 0;

    while (true)
    {
        std::string str;
        int value;
        std::cin >> str >> value;

        switch (str[0])
        {
            case 'f': x += value; break;
            case 'u': y -= value; break;
            case 'd': y += value; break;
            default: break;
        }

        std::cout << (x * y) << std::endl;
    }
    

    return 0;
}