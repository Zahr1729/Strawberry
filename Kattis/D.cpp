#include <iostream>

int main () 
{
    int n; int m;
    std::cin >> n >> m;

    int x[n];
    int y[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> x[i] >> y[i];
    }

    // holds the index + 1 of the atom
    int a[m];
    int b[m];

    for (int i = 0; i < m; i++)
    {
        std::cin >> a[m] >> b[m];
    }
    
    

    return 0;
}