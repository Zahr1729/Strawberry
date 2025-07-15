#include <iostream>
using namespace std;

bool FindPartyMembers(int N, int numberToFind, bool ** friends, int lastPersonIndex, bool isFriendlyParty, int * partyMembers)
{
    if (numberToFind == 0) return true;

    bool * relevantRow = friends[lastPersonIndex];

    for (int i = lastPersonIndex + 1; i < N; i++)
    {
        if (relevantRow[i] == isFriendlyParty)
        {
            if (FindPartyMembers(N, numberToFind - 1, friends, i, isFriendlyParty, partyMembers))
            {
                partyMembers[numberToFind - 1] = i + 1;
                return true;
            }
        }
    }
    return false;
}


int main ()
{
    int N; int M;
    cin >> N >> M;

    cout << M;

    bool **friends;
    for (int i = 0; i < N; i++)
    {
        friends[i] = new bool[N];
    }
    

    for (int i = 0; i < M; i++)
    {
        int U; int V;
        cin >> U >> V;
        friends[U-1][V-1] = true;
        friends[V-1][U-1] = true;
    }
    // Setup the 2D array of relations

    bool possibleParty;

    int members[5] = { -1 };
    
    for (int i = 0; i < N - 4; i++)
    {
        if (FindPartyMembers(N, 5, friends, 0, true, members))
        {
            possibleParty = true;
            break;
        }
        if (FindPartyMembers(N, 5, friends, 0, false, members))
        {
            possibleParty = true;
            break;
        }
    }

    if (!possibleParty) { cout << -1 << endl; }
    else {
        for (int i = 0; i < 5; i++)
        {
            cout << members[i] << " ";
        }
        cout << endl;
        
    }
}