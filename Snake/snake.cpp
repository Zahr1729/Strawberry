#include <iostream>
#include <list>


// Starting up how we store location data
struct Vec2
{
    int x, y;
    Vec2(int _x, int _y) { x = _x; y = _y; }
};


// All stuff with snake itself
class Snake
{
public:
    // Variables

    Vec2 head;  // Holds data of position of head and tail
    Vec2 tail[];
    Vec2 direction; // Path we are going in

    // Constructor
    Snake(Vec2 h, Vec2 * t, Vec2 dir) {
        head = h;
        tail = t;
        direction = dir;
    }

    // change direction
    void ChangeDir (Vec2 newD)
    {
        // Check if its not going back on itself
        Vec2 diff = Vec2(head.x - tail[0].x, head.y - tail[0].y);
        if (diff.x != newD.x and diff.y != newD.y) { direction = newD; }
    }
};

class Apple
{
    int x, y;
};

