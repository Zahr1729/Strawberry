#include <iostream>

bool FindPath (int ** doorways, int n, int currentRoom, int * visitedRooms, int numVisited)
{
    // std::cout << currentRoom << std::endl;
    if (currentRoom == n) { return true; }
    int index = currentRoom - 1;

    /*
    for (int i = 0; i < 4; i++)
    {
        std::cout << doorways[index][i] << " ";
    } std::cout << std::endl;
    */
    
    for (int i = 0; i < 4; i++)
    {
        int k = doorways[index][i];
        if (k != 0)
        {
            bool visitedBefore = false;
            for (int i = 0; i < n; i++)
            {
                if (k == visitedRooms[i]) { visitedBefore = true; continue; }
            }
            if (visitedBefore) { continue; }
            visitedRooms[numVisited] = k;
            if (FindPath(doorways, n, k, visitedRooms, numVisited + 1)) { return true; }
            visitedRooms[numVisited] = 0;
        }
    }
    return false;
}

int main ()
{
    int n;
    std::cin >> n;

    int * doorways[n];
    for (int i = 0; i < n; i++)
    {
        doorways[i] = new int[4];
        for (int j = 0; j < 4; j++)
        {
            std::cin >> doorways[i][j];
        }
    }

    
    int * yourDoorways[n];
    for (int i = 0; i < n; i++)
    {
        yourDoorways[i] = new int[4];
        for (int j = 0; j < 4; j++)
        {
            std::cin >> yourDoorways[i][j];
        }
    }

    /*
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << doorways[i][j] << " ";
        }
        std::cout << std::endl;
    } */

    int visitedRooms[n] = {0};
    visitedRooms[0] = 1;

    if (!FindPath(doorways, n, 1, visitedRooms, 1)) { std::cout << "Impossible" << std::endl; return 0;}


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (doorways[i][j] != yourDoorways[i][j])
            {
                doorways[i][j] = 0;
            }
        }
        
    }
    

    // Now determine if a path is possible!

    int newVisitedRooms[n] = {0};
    newVisitedRooms[0] = 1;
    bool output = FindPath(doorways, n, 1, newVisitedRooms, 1);
    std::string str = output ? "Yes" : "No" ;
    std::cout << str;

    return 0;
}