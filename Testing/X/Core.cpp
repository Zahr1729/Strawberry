#include <iostream>
#include <string>
#include <raylib.h>

namespace X
{
    struct Vector3
    {
    public:
        float x; float y; float z;
        Vector3(float _x, float _y, float _z) { x = _x; y = _y; z = _z; }
        float GetMagSq() { return x * x + y * y + z * z; }
        float GetMag() { return sqrt(GetMagSq()); }
        Vector3 Scale (float sf) { return Vector3(x *= sf, y *= sf, z *= sf); }
        Vector3 Normalise() { return this->Scale(1 / this->GetMag()); }
        static Vector3 Add (Vector3 a, Vector3 b) { return Vector3(a.x + b.x, a.y + b.y, a.z + b.z); } 
    };

    void Core ()
    {
        Vector3 w = Vector3(1, 1, 1);
        Vector3 v = w.Normalise();
        std::cout << "(" << v.x << ", " << v.y << ", " << v.z << ")" << std::endl;
    }
}


int main ()
{
    X::Core();
    return 0;
}