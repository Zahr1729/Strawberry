#include <iostream>
#include <map>
#include <utility>
#include <bits\stdc++.h>

int main () {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        int perm[200001] = { 0 };

        std::cin >> n;

        int min = -1, len = 1, max = 1;
        for (int i = 0; i < n; i++)
        {
            std::cin >> perm[i];
            if (perm[i] == 1) { min = i; }
        }

        std::cout << 1;
        
        for (int i = 1; i < n; i++)
        {
            bool goLeft;
            if (min == 0) {
                goLeft = false;
            } else if (min + len == n) {
                goLeft = true;
            } else {
                //std::cout << "NUMBERS: " << perm[min-1] << perm[min + len];
                goLeft = (perm[min-1] < perm[min + len]);
            }

            if (!goLeft) {
                max = std::max(max, perm[min + len]);
            } else {
                min--;
                max = std::max(max, perm[min]);
            }
            len++;

            //std::cout << "\n MIN: " << min << " LEN: " << len << " MAX: " << max << "\n";

            if (max == len) {
                std::cout << 1;
            } else {
                std::cout << 0;
            }

        } std::cout << "\n";
    }
    
}