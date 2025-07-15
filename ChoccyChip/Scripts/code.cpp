#include <iostream>
#include <string>

using namespace std;

namespace ChoccyChip {


    int AnalyseCommand(std::string s) {
        return 0;
    }

    string GetCommand() {
        std::string s;
        getline(std::cin, s);
        return s;
    }

    void Core () {
        std::string command, op1, op2, op3, op4;
        std::string str =  GetCommand();
        std::istringstream iss(str);
    }
}

int main () {

    ChoccyChip::Core();
}