#include <iostream>

struct V2
{
    int x;
    int y;
    V2 (int _x = 0, int _y = 0) { x = _x; y = _y; }
};


double GetPerimeter (V2 * pos, V2 * grad, int l1, int l2, int l3)
{
    if (grad[l1].x == 0 && (grad[l2].x == 0 || grad[l3].x == 0)) { return 0; }
    
    

    double mu; double lambda;
    if (grad[l1].x == 0) { mu = }
    V2 oneTwo = 
}


int main ()
{
    int n;
    std::cin >> n;

    V2 pos[n];
    V2 grad[n];

    for (int i = 0; i < n; i++)
    {
        int x1; int y1; int x2; int y2;
        std::cin >> x1 >> y1 >> x2 >> y2;

        V2 p = V2(x1, y1);
        V2 g = V2(x2- x1, y2 - y1);
        pos[i] = p;
        pos[i] = g;
    }
    
    int l1 = 0; int l2 = 1; int l3 = 2;

    double maxPerim;

    bool flag = false;
    while (flag == false)
    {
        for (int i = 0; i < n; i++)
        {
            newL1 = i;
        }
        
    }

    return 0;
}