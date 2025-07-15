#include <iostream>
using namespace std;

int main ()
{
    int t;
    cin >> t;

    int * mins[t];
    int * maxs[t];
    int sizes[t];

    for (int c1 = 0; c1 < t; c1++)
    {
        int n;
        cin >> n;
        int inp[n]; // input array
        bool used[n] = {false}; // Array for used numbers, True for used.
        for (int index = 0; index < n; index++)
        {
            cin >> inp[index];

            if (used[index] == false)
            {
                used[index] = (index + 1 == inp[index]) ? true : false;
            }
            used[inp[index] - 1] = true;
        }
        

        int * min = (int*) malloc(sizeof(int) * n);
        int currentNum = 0;
        int prevInp = 0;
        for (int i = 0; i < n; i++)
        {
            if (prevInp != inp[i]) { min[i] = inp[i]; prevInp = inp[i]; continue; }

            while (used[currentNum] == true) { currentNum++; }
            min[i] = currentNum + 1; currentNum++;
        }

        
        int * max = (int*) malloc(sizeof(int) * n);
        currentNum = 0;
        prevInp = 0;
        for (int i = 0; i < n; i++)
        {
            if (prevInp != inp[i]) { max[i] = inp[i]; prevInp = inp[i]; currentNum = inp[i] - 1; continue; }

            while (used[currentNum] == true) { currentNum--; }
            max[i] = currentNum + 1; used[currentNum] = true; currentNum--;
        }

        mins[c1] = min;
        maxs[c1] = max;
        sizes[c1] = n;
    }

    for (int i = 0; i < t; i++)
    {
        int * min = mins[i];
        int * max = maxs[i];
        int n = sizes[i];


        for (int j = 0; j < n; j++)
        {
            cout << *(min + j) << " ";
        }
        cout << endl;

        for (int j = 0; j < n; j++)
        {
            cout << *(max + j) << " ";
        }
        cout << endl;
    }
    

    return 0;
}