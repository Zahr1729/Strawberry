#include <iostream>

int main ()
{
    int x; int y;
    std::cin >> x >> y;

    int r;
    std::cin >> r;

    std::cout << x - r << " " << y - r << std::endl;
    std::cout << x + r << " " << y - r << std::endl;
    std::cout << x + r << " " << y + r << std::endl;
    std::cout << x - r << " " << y + r << std::endl;


    return 0;
}