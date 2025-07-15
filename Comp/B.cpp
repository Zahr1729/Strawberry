#include <iostream>
#define p std::pair<int, int>
#include <algorithm>
#include <vector>

int main ()
{
    int N; int M;
    std::cin >> N >> M;

    if ((M % 2) == 1) { std::cout << "impossible"; return 0; }

    std::vector <p> translators;
    int nodeConnections[100];

    // Describe Translators
    for (int i = 0; i < M; i++)
    {
        int n1; int n2; std::cin >> n1 >> n2;

        translators.push_back({ std::min(n1, n2), std::max(n1, n2) });
        nodeConnections[n1]++; nodeConnections[n2]++;
    }

    std::sort(translators.begin(), translators.end());

    for (int i = 0; i < M; i++)
    {
        std::cout << translators[i].first << " " << translators[i].second << std::endl;
    }

    //check if possible
    int OddNodes = 0;
    int firstNode = -1;
    int secondNode = -1;
    for (int i = 0; i < N; i++)
    {
        if ((nodeConnections[i] % 2) == 1)
        {
            std::cout << i << std::endl;
            if (secondNode != -1) { std::cout << "A impossible"; return 0; }
            if (firstNode != -1) { secondNode = i; continue; }
            firstNode = i;
        }
    }
    if (firstNode != -1)
    {
        if (secondNode == -1) { std::cout << "B impossible"; return 0; }
    }
    if (firstNode == -1 ) { firstNode = 0; secondNode = 0;}

    // Now it is possible so lets work on this

    
    


    
    


    return 0;
}