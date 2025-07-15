//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <utility>


int main () {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++){
        long long x, y, a, b;
        std::cin >> x >> y;
        std::cin >> a >> b;
        long long c = std::max(x, y);
        long long d = std::min(x, y);
        x = c; y = d;

        long long cost = 0;

        d = x - y;
        cost += d * a;

        cost += y * std::min(2*a, b);

        std::cout << cost << "\n";
    }
}