#include <iostream>
#include <string>

using std::string;

#pragma region BowlingScore

struct Frame
{
    int ball1;
    int ball2;
};

int BowlingScore (int * arr)
{
    int score = 0;
    int i = 0;

    // First 10 Frames
    for (int j = 0; j < 9; j++)
    {
        // First points added
        Frame f = Frame();
        f.ball1 = 0; f.ball2 = 0;
        f.ball1 = arr[i];
        score += f.ball1;

        // Strike
        if (f.ball1 == 10) {
            // Add next two balls
            try { score += arr[i+1]; } catch(const std::exception& e) {  }
            try { score += arr[i+2]; } catch(const std::exception& e) {  }
            
            i++;
            continue;
        }

        i++;
        // Second ball
        f.ball2 = arr[i];
        score += f.ball2;

        // Spare
        if (f.ball2 + f.ball1 == 10)
        {
            // Add next ball;
            try { score += arr[i+1]; } catch(const std::exception& e) {  }
        }
        i++;
    }

    // Last 3 get scores
    int b1 = arr[i]; int b2 = arr[i+1]; int b3 = 0;
    if (b1 + b2 == 10 || b1 == 10 && b2 == 10) { b3 = arr[i+2]; }

    // Finalise
    score += b1 + b2 + b3;
    
    return score;
}

#pragma endregion

//Failure
#pragma region SpaceMessage

string UpdateOutput (string output, string number, string letters)
{
    int s = sizeof(letters) / sizeof("A"[0]);
    if (number != "")
    {
        int n = std::stoi(number);
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < s; k++)
            {
                if (letters[k] == ""[0]) { break; }
                output.push_back(letters[k]);
            }
        }
    } else
    {
        for (int k = 0; k < s; k++)
        {
            if (letters[k] == ""[0]) { break; }
            output.push_back(letters[k]);
        }
    }
    return output;
}

string SpaceMessage (string input, int * parentIndex)
{
    string output;
    string number;
    string letters;

    int arrSize = sizeof(input) / 4;

    for (int i = *parentIndex; i < arrSize; i++)
    {
        ++*parentIndex; // Increment the index for the parent
        char c = input[i];
        if (c == "]"[0]) { ++*parentIndex; break; }
        if (c == "["[0])
        {
            i++; ++*parentIndex; output = UpdateOutput(output, number, letters);
            letters = letters + SpaceMessage(input, &i);
            continue;
        }

        if (c == "0"[0] || c == "1"[0] || c == "2"[0] || c == "3"[0] || c == "4"[0] || c == "5"[0] || c == "6"[0] || c == "7"[0] || c == "8"[0] || c == "9"[0])
        {
            number.push_back(c);
        }
        else
        {
            letters.push_back(c);

        }

        ++*parentIndex;
    }

    output = UpdateOutput(output, number, letters);

    return output;
}

#pragma endregion

#pragma region Score31

struct Card
{
    int number; // J = 11, Q = 12, K = 13, A = 14
    int suit; // C = 0, H = 1, D = 2, S = 3
    int value; // J, Q, K = 10, A = 10
};

Card StringToCard (string c)
{
    Card card = Card();

    switch (c[0])
    {
        case "C"[0]: card.suit = 0; break;
        case "H"[0]: card.suit = 1; break;
        case "D"[0]: card.suit = 2; break;
        case "S"[0]: card.suit = 3; break;
    }

    switch (c[1])
    {
        case "7"[0]: card.number = 7; card.value = 7; break;
        case "8"[0]: card.number = 8; card.value = 8; break;
        case "9"[0]: card.number = 9; card.value = 9; break;
        case "1"[0]: card.number = 10; card.value = 10; break;
        case "J"[0]: card.number = 11; card.value = 10; break;
        case "Q"[0]: card.number = 12; card.value = 10; break;
        case "K"[0]: card.number = 13; card.value = 10; break;
        case "A"[0]: card.number = 14; card.value = 11; break;
    }

    return card;
}

float Score31 (string s1, string s2, string s3)
{
    // Setup get the strings into cards
    Card c1, c2, c3;
    c1 = StringToCard(s1);
    c2 = StringToCard(s2);
    c3 = StringToCard(s3);

    if (c1.number == c2.number && c1.number == c3.number)
    { return c1.number == 14 ? 32 : 30.5; }

    float c, h, d, s;

    for (int i = 0; i < 4; i++)
    {
        switch (i)
        {
            case 0: c = (c1.value * (int) (c1.suit == 0)) + (c2.value * (int) (c2.suit == 0)) + (c3.value * (int) (c3.suit == 0));
            case 1: h = (c1.value * (int) (c1.suit == 1)) + (c2.value * (int) (c2.suit == 1)) + (c3.value * (int) (c3.suit == 1));
            case 2: d = (c1.value * (int) (c1.suit == 2)) + (c2.value * (int) (c2.suit == 2)) + (c3.value * (int) (c3.suit == 2));
            case 3: s = (c1.value * (int) (c1.suit == 3)) + (c2.value * (int) (c2.suit == 3)) + (c3.value * (int) (c3.suit == 3));
        }
    }

    return std::max(std::max(c, h), std::max(d, s));
}

#pragma endregion

#pragma region Grass

#pragma endregion