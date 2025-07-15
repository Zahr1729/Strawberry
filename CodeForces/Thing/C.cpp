#include <iostream>

int main ()
{
    int n;
    std::cin >> n;

    bool arr[n] = { false };

    arr[1] = true;
    int runningModulo = 1;
    for (int i = 0; i < 2 * n; i++)
    {
        runningModulo += i;
        while (runningModulo >= n) { runningModulo -= n; }
        arr[runningModulo] = true;
    }
    
    
    bool works = true;
    for (int i = 0; i < n; i++)
    {
        works = works && arr[i];
        if (!works) break;
    }
    

    std::string out = (works) ? "YES" : "NO";
    std::cout << out << std::endl;
}