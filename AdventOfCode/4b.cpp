#include <iostream>

int main ()
{
    const int foundFlag = -1;


    const int totalNumbers = 100;
    int numberList[totalNumbers];

    const int boardCount = 100;
    int boards[boardCount][5][5];

    for (int i = 0; i < totalNumbers; i++)
    {
        int a; std::cin >> a;
        numberList[i] = a;
    }

    for (int i = 0; i < boardCount; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                int val; std::cin >> val;
                boards[i][j][k] = val; 
            }
        }
    }

    bool boardIndexUsed[100] = { false };

    int finalNumber = -1;
    int finalIndex = -1;
    
    for (int i = 0; i < totalNumbers; i++)
    {
        // Check if num is on board
        int num = numberList[i];

        for (int j = 0; j < boardCount; j++)
        {
            if (boardIndexUsed[j] == true) { continue; }

            bool flag = false;

            for (int k = 0; k < 5; k++)
            {
                for (int l = 0; l < 5; l++)
                {
                    if (boards[j][k][l] == num)
                    {
                        boards[j][k][l] = -1; flag = true; break;
                    }
                }
                if (flag) { break; }
            }
            

            if (flag)
            {
                //std::cout << "UWU\n";
                for (int k = 0; k < 5; k++)
                {
                    if ( (boards[j][k][0] == -1) && (boards[j][k][1] == -1) && (boards[j][k][2] == -1) && (boards[j][k][3] == -1) && (boards[j][k][4] == -1) )
                    { finalNumber = num; finalIndex = j; boardIndexUsed[j] = true; break; }
                    if ( (boards[j][0][k] == -1) && (boards[j][1][k] == -1) && (boards[j][2][k] == -1) && (boards[j][3][k] == -1) && (boards[j][4][k] == -1) )
                    { finalNumber = num; finalIndex = j; boardIndexUsed[j] = true; break; }
                }
            }
        }
    }

    int sum = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (boards[finalIndex][i][j] != -1)
            {
                sum += boards[finalIndex][i][j];
            }
        }
    }

    std::cout << sum << " " << finalNumber << std::endl;

    std::cout << (sum * finalNumber) << std::endl;
    
    

    return 0;
}