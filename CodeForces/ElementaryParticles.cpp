//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <utility>


int main () {
    int t;
    std::cin >> t;

    for (int test = 0; test < t; test++)
    {
        int n; std::cin >> n;
        int a[n+1];

        std::map<int, std::pair<int, int>> mp;
        // key denotes number, then difference then index of rightmost

        for (int i = 0; i < n; i++)
        {
            int index = i+1;
            int nextNum;
            std::cin >> nextNum;

            std::map<int, std::pair<int, int>>::iterator it;

            it = mp.find(nextNum);
            if (it != mp.end())
            {
                if (mp.insert)

            } else { mp[nextNum] = {-1, index}; }
        }
    }
}
