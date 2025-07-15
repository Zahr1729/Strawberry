#include <iostream>

int main()
{
    int cases;
    std::cin >> cases;

    std::string outputs[200] = { "" };

    for (int i = 0; i < cases; i++)
    {
        int N;
        std::string sentence;
        std::cin >> N >> sentence;

        for (int j = 0; j < N; j++)
        {
            int len = sentence.length();
            if (len <= 3) { break; }

            if ((j & 1) == 0) { sentence = sentence.substr(len / 4, len - (len / 4)); continue; }
            sentence = sentence.substr(0, len - (len / 4));
        }
        outputs[i] = sentence;
    }

    for (int i = 0; i < cases; i++)
    {
        std::cout << outputs[i] << std::endl;
    } std::cout << std::endl;
    
    

    return 0;
}