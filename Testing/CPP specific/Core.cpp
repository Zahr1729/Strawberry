#include <iostream>

using std::string;

#pragma region Interfaces

class IAnimal
{
protected:
    string name;
    int age;
    string noise;

public:
    virtual string GetName() = 0;
    virtual int GetAge() = 0;
    virtual string GetNoise() = 0;
};

class Dog : IAnimal
{
public:
    Dog(string _name, int _age)
    {
        name = _name;
        age = _age;
    }

    string GetName() { return name; }
    int GetAge() { return age; }
    string GetNoise() { return "Bark"; }
};

class Turtle : IAnimal
{
public:
    Turtle(string _name, int _age)
    {
        name = _name;
        age = _age;
    }

    string GetName() { return name; }
    int GetAge() { return age; }
    string GetNoise() { return "Bleh"; }
};

#pragma endregion

#pragma region Generics

class Utilities
{
public:
    template <typename T1, typename T2>
    static bool CompareType (T1 data1, T2 data2)
    {
        return typeid(data1) == typeid(data2);
    }
};

#pragma endregion

#pragma region Files

#include <fstream> // Files interaction
// Also <ifstream> and <ofstream> for input and output specifically
// Input means taking data from file to program here.

void ReadFile (string fileName)
{
    std::fstream fileHandle;    // Setup the handle
    fileHandle.open(fileName, std::ios::in);    // Link the file in "read" or "in" mode

    string str; // Define a string to write to
    // Read line by line
    while (std::getline(fileHandle, str)) // take each line (seperated by \n) and put into variable str
    {
        std::cout << str << std::endl;
    }

    // Simple :))))))
}


#pragma endregion

int main ()
{
    ReadFile("data.txt");
    return 0;
}