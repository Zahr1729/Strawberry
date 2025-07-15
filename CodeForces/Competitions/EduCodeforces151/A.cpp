#include <iostream>
#include <bits/stdc++.h>

int t, n, k, x;

int main() {

    std::cin >> t;

    while (t--) {
        std::cin >> n >> k >> x;

        if (x != 1)
        { 
            std::cout << "YES\n" << n << "\n";
            for (int i = 0; i < n; i++) std::cout << 1 << " ";
            std::cout << "\n";
            continue;
        }

        if (k == 1) { std::cout << "NO\n"; continue; }

        if (k == 2)
        {
            if ((n % 2) == 0) {
                std::cout << "YES\n" << n/2 << "\n";
                for (int i = 0; i < n/2; i++) std::cout << 2 << " ";
                std::cout << "\n";
                continue;
            }

            std::cout << "NO\n";
            continue;
        }

        std::cout << "YES\n" << (n-1)/2 << "\n" << "3 ";
        for (int i = 0; i < (n-3)/2; i++) std::cout << 2 << " ";
        std::cout << "\n";
    }

    return 0;
}