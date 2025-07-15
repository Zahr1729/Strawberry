#include <iostream>
#define p std::pair<int, int>
#define pp std::pair<p, p>

int main ()
{
    const int inputSize = 10;
    pp array[inputSize];

    const int subMatrixSize = 10;
    const int coMatrixSize = 1;

    for (int i = 0; i < inputSize; i++)
    {
        p pair1 = { 0, 0 };
        p pair2 = { 0, 0 };

        std::scanf("%d,%d -> %d,%d", &pair1.first, &pair1.second, &pair2.first, &pair2.second);

        array[i].first = pair1; array[i].second = pair2;
    }

    int finalCount = 0;

    for (int n = 0; n < coMatrixSize; n++) {
    int m = 0;
    
    int matrix[subMatrixSize][subMatrixSize] = { 0 };
    
    for (int i = 0; i < inputSize; i++)
    {
        pp data = array[i];
        // std::cout << data.first.first << " " << data.first.second << " " << data.second.first << " " << data.second.second << std::endl;

        // vertical case
        if (data.first.first == data.second.first)
        {
            int x = data.first.first;
            int y1 = data.first.second;
            int y2 = data.second.second;

            if ( ( x < (subMatrixSize * n) ) || ( x > (n * (subMatrixSize + 1)) ) ) { continue; }
            if ( ( y1 < (subMatrixSize * m) ) || ( y1 > (m * (subMatrixSize + 1)) ) )
            { 
                if ( ( y2 < (subMatrixSize * m) ) || ( y2 > (m * (subMatrixSize + 1)) ) ) { continue; }
            }

            if (y2 < y1)
            {
                int temp = y2;
                y2 = y1;
                y1 = temp;
            }

            while (y1 <= y2)
            {
                if ( ( y1 > (subMatrixSize * m) ) && ( y1 < (m * (subMatrixSize + 1)) ) )
                { matrix[x][y1]++; }
                y1++;
            }
        }

        // horizontal case
        if (data.first.second == data.second.second)
        {
            int y = data.first.second;
            int x1 = data.first.first;
            int x2 = data.second.first;

            if (y < (subMatrixSize * m) || y > (m * (subMatrixSize + 1)) ) { continue; }
            if (x1 < (subMatrixSize * n) || x1 > (n * (subMatrixSize + 1)) )
            { 
                if (x2 < (subMatrixSize * n) || x2 > (n * (subMatrixSize + 1)) ) { continue; }
            }

            if (x2 < x1)
            {
                int temp = x2;
                x2 = x1;
                x1 = temp;
            }

            while (x1 <= x2)
            {
                if (x1 > (subMatrixSize * n) && x1 < (n * (subMatrixSize + 1)) )
                { matrix[x1][y]++; }
                x1++;
            }
        }
    }

    // Finally
    int count = 0;

    for (int i = 0; i < subMatrixSize; i++)
    {
        for (int j = 0; j < subMatrixSize; j++)
        {
            //std::cout << matrix[j][i] << " ";
            if (matrix[i][j] >= 2) { count++; }
        } //std::cout << std::endl;
    }

    }

    
    std::cout << finalCount << std::endl;

    return 0;
}