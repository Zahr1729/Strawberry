#include <iostream>
using namespace std;

int function (int a, int b)
{
    if (a == 1) { return (b + 1);}
    if (b == 1) { return function(a-1, 2); }

    return function(a-1, function(a, b-1));
}

int main ()
{
    cout << function(5, 5);

    return 0;
}