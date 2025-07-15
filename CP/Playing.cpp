#include <bits/stdc++.h>

void InOut ()
{
    double a;
    std::scanf("%lf", &a);

    //(double) a;

    std::printf("%f \n", a);
}

void NiceFunctionsAndStructures ()
{
    int arr[15] = { 18, 2, 3, 1, 0, -1, 2, 4, 2, 1, 3, 4, 5, -4, 10 };
    std::sort(arr, arr + 15);

    for (int i = 0; i < 15; i++) { std::cout << arr[i] << " "; }


    std::vector<std::tuple<int, bool, double>> v; // Define a vector (array) of tuples of int boolean and double
    v.push_back({ 1, false, 4.2 });
    v.push_back({ 1, true, 4.2 });
    v.push_back({ 1, false, 4.5 });
    v.push_back({ 4, true, 2.1 });
    std::sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        std::tuple<int, bool, double> t = v[i];
        std::printf("(%d, %s, %f)", std::get<0>(t), (std::get<1>(t)) ? "true" : "false", std::get<2>(t));
    }
    
}

struct S
{
    int data;
    bool other;

    S (int d, bool o) { data = d; other = o; }

    bool operator< (const S &s)
    {
        return data < s.data;
    }
};

bool compare (S a, S b)
{
    return (a.other < b.other);
}

void DefiningOperators ()
{

    

    S one = S(15, false);
    S two = S(23, true);
    S three = S(19, false);
    S four = S(8, true);

    std::cout << (one < two) << std::endl;


    // We can pass operator into sort!

    std::vector<S> v;
    v.push_back(one); v.push_back(two); v.push_back(three); v.push_back(four);

    std::sort(v.begin(), v.end());
    // Assumes Operator < :))))

    for (int i = 0; i < 4; i++)
    {
        printf("(%d, %s)\n", v[i].data, (v[i].other) ? "true" : "false");
    }


    


    std::sort(v.begin(), v.end(), compare);
    // Uses Compare Operator!

    for (int i = 0; i < 4; i++)
    {
        printf("(%d, %s)\n", v[i].data, (v[i].other) ? "true" : "false");
    }
    
    
}

int main ()
{
    DefiningOperators();
    

    return 0;
}