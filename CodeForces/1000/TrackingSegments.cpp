#include <iostream>
#include <map>
#include <utility>
#include <bits/stdc++.h>

using namespace std;
int n, m, q, t;
int l[100001], r[100001];
int inp[100001], sum[100001];

bool check (int x)
{
    for (int i = 0; i <= n; i++) sum[i] = 0;
    for (int i = 1; i <= x; i++) sum[inp[i]]++;
    for (int i = 1; i <= n; i++) sum[i] += sum[i-1];
    
    for (int i = 1; i <= m; i++)
    {
        if(2 * (sum[r[i]] - sum[l[i] - 1]) > r[i] - l[i] + 1) return true;
    }
    
    return false;
}


int main () {

    std::cin >> t;
    while(t--) {
        std::cin >> n >> m;
        for (int i = 1; i <= m; i++) std::cin >> l[i] >> r[i];
        std::cin >> q;
        for (int i = 1; i <= q; i++) std::cin >> inp[i];
        
        int low = 1, upp = q + 1;
        while (low < upp) {
            

            int mid = (low + upp) >> 1;
            if (check(mid)) { upp = mid; }
            else { low = mid + 1; }

        }
        if (low > q) low = -1;
        std::cout << low << "\n";
    }
}