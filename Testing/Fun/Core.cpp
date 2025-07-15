#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;


namespace Carbonara
{
    float ARBITRARYFUNCTION (float)
    {
        return 3.2F;
    }

    void FuncPtr ()
    {
        float (*f) (float);
        f = &ARBITRARYFUNCTION;
        
        cout << (*f)(5.0F) << endl;
    }

    void Filing ()
    { 
        std::fstream myFile;
        myFile.open("myFile.csv", std::ios::in);

        if (!myFile)
        {
            cout << "No such file exists";
        } else {
            
            std::string str;
            while (std::getline(myFile, str))
            {
                // Create a string stream from the data from a line
                std::string datapoint;
                std::stringstream ss(str);

                while (std::getline(ss, datapoint, ','))
                {
                    cout << datapoint << " ";
                }
                cout << endl;
            }
        }
    }

    class vec3
    {
    public:
        float x; float y; float z;

        vec3 (float _x, float _y, float _z) { x = _x; y = _y; z = _z; }
        void ConsoleLog () { cout << "(" << x << ", " << y << ", " << z << ")" << endl; }
    };

    void Do ()
    {
        vec3 v = vec3(1, 2, 0);
        v.ConsoleLog();
    }
}

int main ()
{
    Carbonara::Do();

    return 0;
}