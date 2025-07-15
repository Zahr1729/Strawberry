#include <iostream>
#include <map>
#include <utility>
#include <bits\stdc++.h>

int main () {
    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++)
    {
        int n; std::cin >> n;

        int perm[200000] = { 0 };
        int order[200000] = { 0 };

        for (int j = 0; j < n; j++)
        {
            std::cin >> perm[j];
        }

        for (int j = 1; j < n + 1; j++)
        {
            if (order[j - 1] != 0) { continue; }

            int curr = j;
            int ord = 0;
            while (true)
            {
                ord++;
                curr = perm[curr - 1];
                if (curr == j) { break; }
            }

            order[j - 1] = ord;

            while (true)
            {
                curr = perm[curr - 1];
                order[curr - 1] = ord;
                if (curr == j) { break; }
            }
            
        }

        for (int j = 0; j < n; j++)
        {
            std::cout << order[j] << " ";
        } std::cout << "\n";
    }
}