#include <iostream>
#include <map>
#include <utility>
#include <bits/stdc++.h>

int main () {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++){
        long long n, k;
        std::cin >> n >> k;

        long long a = (2*k)*(2*k - 1)/2 - (k-1)*k;
        
        n = n - a;
        if (n >= 0 && ((n & 1) == 0))
        {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}