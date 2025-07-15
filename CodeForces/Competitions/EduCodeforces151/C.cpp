#include <iostream>
#include <bits/stdc++.h>
#include <string>

int t;
std::string s, l, r;
int m;

bool isSubstring (std::string a, std::string b, int i, int j)
{
    //std::cout << i << " " << j << " ";

    if (j == 0)
        return true;
    if (i == 0)
        return false;

    
    //std::cout << a[i-1] << " " << b[j-1] << "\n";

    if (a[i-1] == b[j-1]){
        return isSubstring(a, b, i-1, j-1);
    }

    return isSubstring(a, b, i-1, j);
}

bool func (std::string str, int index)
{
    if (index == m)
    {
        //std::cout << "DATA: " << s << " " << str << "\n";
        if (isSubstring(s, str, s.length(), m))
        {
            //std::cout << " sub\n";
            return false;
        }
        return true;
    }

    int a, b, low, upp;
    a = (int) l[index];
    b = (int) r[index];
    low = std::min(a, b);
    upp = std::max(a, b);

    for (int i = low; i <= upp; i++)
    {
        str[index] = (char) i;
        if (func(str, index + 1)) return true;
    }
    

    return false;
}

int main() {

    std::cin >> t;
    while (t--) {

        std::cin >> s >> m >> l >> r;

        std::string str = "xxxxxxxxxxxxxxxxxxxxxxxxx";
        str = str.substr(0, m);
        std::cout << (func(str, 0) ? "YES\n" : "NO\n");
    }

    return 0;
}