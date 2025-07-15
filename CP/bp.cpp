#include <bits/stdc++.h>

int main ()
{
    int n;
    std::cin >> n;

    std::pair<int, int> values[n];

    for (int i = 0; i < n; i++)
    {
        int b; int p;
        //std::cin >> b >> p;
        b = rand() % 2000001 + -1000000;
        p = rand() % 2000001 + -1000000;

        values[i] = { b, p };
    }
    
    std::sort(values, values + n);

    int bSum; int pSum;
    for (int i = 0; i < n; i++)
    {
        if (i == 0) { bSum = values[0].first + values[n-1].first; pSum = values[0].second + values[n-1].second; }

        int pairIndex = n - 1 - i;
        if (bSum != (values[i].first + values[pairIndex].first)) { std::cout << "impossible"; return 0; }
        if (pSum != (values[i].second + values[pairIndex].second)) { std::cout << "impossible"; return 0; }
    }
    
    std::cout << "possible"; 

    return 0;
}