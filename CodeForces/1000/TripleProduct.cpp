#include <iostream>
#include <map>
#include <utility>
#include <bits/stdc++.h>

int main () {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++){
        int n;
        std::cin >> n;

        //std::cout << n;

        int a = 0, b = 0, c = 0;
        for (int i = 2; i < std::min(100001, n); i++)
        {
            if ((n % i) == 0) {
                a = i; n = n/i;
                if (n <= a) { a = 0; }
                break;
            }
        }

        //std::cout << a << " " << b << " " << c << " " << n;

        if (a == 0) { std::cout << "NO\n"; continue; }
    
        for (int i = a + 1; i < std::min(100001, n); i++)
        {
            if ((n % i) == 0) {
                b = i; c = n/i;
                if (c <= b) { b = 0; }
                break;
            }
        }
        if (b == 0) { std::cout << "NO\n"; continue; }

        std::cout << "YES\n" << a << " " << b << " " << c << "\n";
    }
}