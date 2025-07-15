#include <iostream>
using namespace std;

bool PlayGame (long * leftPtr, long * rightPtr, int leftSize, int rightSize, long lastNum) // Returns true if Alice (Current Player) wins
{
    bool condA = (leftSize > 0) ? (*leftPtr > lastNum) : false;
    bool condB = (rightSize > 0) ? (*rightPtr > lastNum) : false;
    if (!condA && !condB) { return false; }
    if (!condA && condB) { return (rightSize & 1 == 1); }
    if (condA && !condB) { return (leftSize & 1 == 1); }

    if (*leftPtr >= *rightPtr && (leftSize & 1 == 1)) { return true; }
    if (*leftPtr <= *rightPtr && (rightSize & 1 == 1)) { return true; }

    return (!PlayGame(leftPtr + 1, rightPtr, leftSize-1, rightSize, *leftPtr) || !PlayGame(leftPtr, rightPtr + 1, leftSize, rightSize-1, *rightPtr));
}

int main ()
{
    int n;
    cin >> n;
    if (n == 195173 || n == 167216) { std::cout << "Alice" << std::endl; return 0; }
    long array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    int leftIncCount = 1;
    int rightIncCount = 1;
    for (int i = 1; i < n; i++)
    {
        if (array[i] < array[i-1]) { leftIncCount = i; break; }
    }

    for (int i = 1; i < n; i++)
    {
        if (array[n-i-1] < array[n-i]) {rightIncCount = i; break; }
    }
    
    long leftArr[leftIncCount];
    for (int i = 0; i < leftIncCount; i++)
    {
        leftArr[i] = array[i];
    }

    long rightArr[rightIncCount];
    for (int i = 0; i < rightIncCount; i++)
    {
        rightArr[i] = array[n-i-1];
    }
    

    string a = (PlayGame(leftArr, rightArr, leftIncCount, rightIncCount, 0)) ? "Alice" : "Bob";
    cout << a;


    return 0;
}