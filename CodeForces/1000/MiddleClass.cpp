#include <iostream>
#include <map>
#include <utility>
#include <bits/stdc++.h>

int main () {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++){
        int n;
        long long x;
        std::cin >> n >> x;
        long long arr[100000] = {0};
        for (int i = 0; i < n; i++)
        {
            std::cin >> arr[i];
        }
        std::sort(arr, arr + n, std::greater<>());
        
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];

            if (sum < x * (i+1)) { std::cout << i << "\n"; break; }
            if (i == n-1) { std::cout << n << "\n"; }
        }
        
    }
}