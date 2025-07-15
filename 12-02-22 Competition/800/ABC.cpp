#include <iostream>
#include <string>

int main ()
{
    int T; std::cin >> T;
    std::string outputs[100] = { "AMOGUS" };
    for (int i = 0; i < T; i++)
    {
        int n; std::cin >> n;
        std::string s; std::cin >> s;

        int size = s.size();
        if (size >= 3) { outputs[i] = "NO"; continue; }
        if (size == 1) { outputs[i] = "YES"; continue; }
        if (s == "00" || s == "11") { outputs[i] = "NO"; continue; }
        outputs[i] = "YES";
    }

    for (int i = 0; i < T; i++)
    {
        std::cout << outputs[i] << std::endl;
    } std::cout << std::endl;
    
    

    return 0;
}

