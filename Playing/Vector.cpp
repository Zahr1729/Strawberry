
namespace Strawberries
{
    struct Vector3
    {
        double x, y, z;
        Vector3(double X, double Y, double Z) { x = X; y = Y; z = Z; }
        static Vector3 Add (Vector3 v, Vector3 w) { return Vector3(w.x + v.x, w.y + v.y, w.z + v.z); }
        static Vector3 Scale (Vector3 v, double scale) { return Vector3(v.x * scale, v.y * scale, v.z * scale); }
    };


    struct Matrix3x3
    {
        double entries[3][3];
        Matrix3x3()
        {
            entries[0][0] = 1; entries[0][1] = 0; entries[0][2] = 0;
            entries[1][0] = 0; entries[1][1] = 1; entries[1][2] = 0;
            entries[2][0] = 0; entries[2][1] = 0; entries[2][2] = 1;
        }   // Yield Identity Matrix
        
    };
    

}