#include <iostream>
#include <vector>

#define ll long long
#define p std::pair<ll, ll>

int main ()
{
    int n; int q;
    std::cin >> n >> q;
    std::vector<p> hL;

    for (int i = 0; i < n; i++)
    {
        ll x, y; std::cin >> x >> y;
        p loc = { x, y };
        hL.push_back(loc);
    }

    for (int j = 0; j < q; j++)
    {
        int a, b; std::cin >> a >> b;
        int leftmost = a - 1, rightmost = a - 1, upmost = a - 1, downmost = a - 1;
        int sleftmost = a + 1, srightmost = a + 1, supmost = a + 1, sdownmost = a + 1;

        // find most and second most indexes for everything
        for (int i = a; i < b; i++)
        {
            if (i == a)
            {
                if (hL[i].first <= hL[leftmost].first) { sleftmost = leftmost; leftmost = i+1; }
                else { sleftmost = i+1; }
                if (hL[i].second <= hL[downmost].second) { sdownmost = downmost; downmost = i+1; }
                else { sdownmost = i+1; };
                if (hL[i].first >= hL[rightmost].first) { srightmost = rightmost; rightmost = i+1; }
                else { srightmost = i+1; }
                if (hL[i].second >= hL[upmost].second) { supmost = upmost; upmost = i+1; }
                else { supmost = i+1; }
            }

            //left
            if (hL[i].first <= hL[sleftmost].first) { sleftmost = i+1; }
            if (hL[i].first <= hL[leftmost].first) { sleftmost = leftmost; leftmost = i+1; }

            //down
            if (hL[i].second <= hL[sdownmost].second) { sdownmost = i+1; }
            if (hL[i].second <= hL[downmost].second) { sdownmost = downmost; downmost = i+1; }

            //right
            if (hL[i].first >= hL[srightmost].first) { srightmost = i+1; }
            if (hL[i].first >= hL[rightmost].first) { srightmost = rightmost; rightmost = i+1; }

            //up
            if (hL[i].second >= hL[supmost].second) { supmost = i+1; }
            if (hL[i].second >= hL[upmost].second) { supmost = upmost; upmost = i+1; }
        }

        //std::cout << leftmost << " " << rightmost << " " << downmost << " " << upmost << std::endl;
        //std::cout << sleftmost << " " << srightmost << " " << sdownmost << " " << supmost << std::endl;
        std::cout << leftmost << " " << sleftmost << std::endl;
    }
    
    

    return 0;
}