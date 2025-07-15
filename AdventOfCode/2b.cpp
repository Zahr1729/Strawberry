#include <iostream>

int main ()
{
    int aim = 0; int x = 0; int depth = 0;

    while (true)
    {
        std::string str;
        int value;
        std::cin >> str >> value;

        switch (str[0])
        {
            case 'f': x += value; depth += aim * value;  break;
            case 'u': aim -= value; break;
            case 'd': aim += value; break;
            default: break;
        }

        std::cout << "horiz pos: " << x << ", aim: " << aim << ", depth: " << depth << std::endl;
        std::cout << (x * depth) << std::endl;
    }
    

    return 0;
}