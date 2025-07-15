#include <iostream>
#include <bits/stdc++.h>

long long t;
long long xa, ya;
long long xb, yb;
long long xc, yc;

long long func (long long a, long long b) {
    if (a*b < 0) { return 0; }
    return std::min(abs(a), abs(b));
}

int main() {

    std::cin >> t;
    while(t--)
    {
        std::cin >> xa >> ya;
        std::cin >> xb >> yb;
        std::cin >> xc >> yc;

        long long b, c, d, e;
        b = xb - xa;
        c = xc - xa;
        d = yb - ya;
        e = yc - ya;

        //std::cout << b << " " << c << " " << d << " " << e << "\n";
        int ans = func(b, c) + func(d, e) + 1;
        std::cout << ans << "\n";
    }

    return 0;
}