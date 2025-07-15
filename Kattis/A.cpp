#include <iostream>
#include <math.h>

int main ()
{
    int n; int h; int v;
    std::cin >> n >> h >> v;

    int maxHeight = std::max(h, n - h);
    int maxWidth = std::max(v, n - v);

    std::cout << (maxHeight * maxWidth * 4);

    return 0;
}