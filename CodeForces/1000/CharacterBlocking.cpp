#include <iostream>
#include <map>
#include <bits/stdc++.h>

int T;
std::string strings[2];
int l;
int t, q;
int type;
int p;
int w1, p1, w2, p2;
char m, n;
int blocked[200001];

bool same = true;

int main () {
    std::cin >> T;
    while (T--) {
        for (int i = 0; i < 200001; i++) blocked[i] = 0;

        std::cin >> strings[0] >> strings[1];
        l = strings[0].length();

        for (int j = 1; j <= l; j++) same &= (strings[0][j - 1] == strings[1][j-1]);

        std::cout << same;

        std::cin >> t >> q;
        for (int i = 1; i <= q; i++)
        {
            std::cin >> type;
            
            switch (type)
            {
            case 1:
                std::cin >> p;
               blocked[p] = i; // hold last time this was blocked
                break;

            case 2:
                std::cin >> w1 >> p1 >> w2 >> p2;
                //std::cout << w1 - 1 << p1 - 1 << w2 - 1 << p2 - 1;
                std::swap(strings[w1-1][p1-1], strings[w2-1][p2-1]);
                
                break;
            
            case 3:
                bool flag = false;
                for (int j = 1; j <= l; j++)
                {
                    //std::cout << "DATA: " << blocked[j] << " " << i << " " << t;
                    if ( (blocked[j] != 0) && (i - blocked[j] < t) ) { continue; }
                    //std::cout << " UWU \n";
                    if (strings[0][j - 1] != strings[1][j-1]) { flag = true; break; }
                }
                std::string ans = (flag) ? "NO" : "YES";
                std::cout << ans << "\n";
                
                break;
            }
        }

        
        

    }
}