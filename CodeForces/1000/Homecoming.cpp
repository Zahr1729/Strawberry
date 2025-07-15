#include <iostream>
#include <map>
#include <utility>
#include <bits/stdc++.h>

int main () {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++){
        int a, b, p;
        std::cin >> a >> b >> p;

        std::string str;
        std::cin >> str;

        int l = str.length();
        
        char curr = str[l-1];

        long long tot = (curr == 'A') ? a : b;
        tot = (curr == str[l-2]) ? tot : 0;
        if (tot > p) { std::cout << l << "\n"; continue; }

        for (int i = 1; i < l; i++)
        {
            int j = l - i - 1;
            //std::cout << j;

            if (str[j] != curr) {
                //std::cout << j+1;
                curr = str[j];
                tot += (curr == 'A') ? a : b;

                //std::cout << " TOTAL: "<< tot << ". ";

                if (tot > p) { std::cout << j+2 << "\n"; break; }
            }

            if (j == 0) { std::cout << 1 << "\n"; }

        }
        
    }
}