#include <iostream>
#include <string>

using std::string;

int Factorial (int n)
{
    if (n <= 1) return 1;
    return n * Factorial (n-1);
}

int NCR (int n, int r)
{
    return Factorial(n) / (Factorial(r) * Factorial(n-r));
}

// Return string of (a+b)^n
string Formula (int n)
{
    if (n == 0) return "1";
    if (n < 0) return "1/" + Formula(-n);

    // Go through each term of the binary expansion
    string str;
    for (int i = 0; i <= n; ++i)
    {
        int j = n - i;
        int coeffInt = NCR(n, i);
        string coeff = coeffInt == 1 ? "" : std::to_string(coeffInt);   // Coefficient
        string aPow = (j==0) ? "" : (j==1) ? "a" : "a^" + std::to_string(j);
        string bPow = (i==0) ? "" : (i==1) ? "b" : "b^" + std::to_string(i);
        str = str + coeff + aPow + bPow + (i == n ? "" : "+");
    }

    return str;
}


int Hash (int a)
{
    int b = (a >> 16) + (a << 16);
    return (b ^ a);
}


int main ()
{
    int c;
    std::cin >> c;
    std::cout << Hash(c) << std::endl;
    return 0;
}