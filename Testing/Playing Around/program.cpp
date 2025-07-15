#include <iostream>

using namespace std;

int Factorial (uint n) {
    return (n <= 1) ? 1 : n * Factorial(n-1);
}


int Multiply (int a, int b) {
    return a * b;
}

int Add (int a, int b) {
    return a+b;
}

/* 
    int (*multPointer)(int, int){ &Multiply, &Add };
    int (*addPointer)(int, int) = &Add;
    cout << multPointer(5, 6) << endl;
    cout << addPointer(2, 6) << endl;
*/

struct DataPoint {
    int x;
    int y;
};

class Cheese {
public:
    int tastyness;
    int holes;
    string name;

    Cheese (int t, int h, string n) {
        tastyness = t;
        holes = h;
        name = n;
    }
};

int main () {
    DataPoint c; c.x = 0; c.y = 0;
    DataPoint * d = &c;

    c.x = 5;

    cout << c.x << " " << d->x << endl;

    //cout << c.holes << " " << d.holes;

    return 0;
}