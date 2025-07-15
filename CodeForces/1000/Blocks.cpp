#include <iostream>
#include <map>
#include <utility>
#include <bits/stdc++.h>

bool Black(int n, std::string str) {

    int arr[200] = { -1 };
    int l = 0;

    for (int i = 0; i < n; i++)
    {
        if (i == n-1)
        {
            if (str[i] == 'W') { return false; }
            break;
        }

        if (str[i] == 'B') { continue; }
        str[i] = 'B';
        str[i+1] = (str[i+1] == 'B') ? 'W' : 'B';
        arr[l] = i+1;
        l++;
    }

    std::cout << l << "\n";
    for (int i = 0; i < l; i++)
    {
        std::cout << arr[i] << " ";
    } std::cout << "\n";

    return true;
}

bool White(int n, std::string str) {

    int arr[200] = { -1 };
    int l = 0;

    for (int i = 0; i < n; i++)
    {
        if (i == n-1)
        {
            if (str[i] == 'B') { return false; }
            break;
        }

        if (str[i] == 'W') { continue; }
        str[i] = 'W';
        str[i+1] = (str[i+1] == 'W') ? 'B' : 'W';
        arr[l] = i+1;
        l++;
    }

    std::cout << l << "\n";
    for (int i = 0; i < l; i++)
    {
        std::cout << arr[i] << " ";
    } std::cout << "\n";

    return true;
}

int main () {
    int n;
    std::cin >> n;

    std::string str;
    std::cin >> str;

    bool b = Black(n, str);
    if (!b) 
    {
        bool w = White(n, str);
        if (!w)
        {
            std::cout << -1 << "\n";
        }
    }

    
}