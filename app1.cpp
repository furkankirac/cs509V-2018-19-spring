// variables and functions and scope
//   primitive types
//   local, global, static variables
//   free, member, static functions
//   function return types

//#include <stdio.h>

#include <iostream>

using namespace std;

int k=100; // global variable

void func() // free/global function
{
    static bool isInitialized = false;
    if(!isInitialized)
    {
        isInitialized = true;
        cout << "Initialized" << endl;
    }
}

typedef int INT; // type aliasing
//using INT = int;

struct Coordinate
{
    static int nInstances; // only one variable for all instances

    int x;
    int y;

    // default c-tor
//    Coordinate() = default;
    Coordinate() : x(0), y(0) { ++nInstances; }
    Coordinate(int x, int y) : x(x), y(y) { ++nInstances; }

    // copy c-tor
    Coordinate(const Coordinate& other) : x(other.x), y(other.y)
    {
        ++nInstances;
    }

    // copy assignment
    Coordinate& operator=(const Coordinate& other)
    {
        x = other.x;
        y = other.y;
        return *this;
    }

    operator int() const
    {
        return x;
    }


    ~Coordinate() {
        --nInstances;
        cout << "Destructing Coordinate instance." << endl;
    }

    void init(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    // this function doesn't use anything related with instance
    // has no this ptr, because it is made static
    static void printHeader()
    {
        cout << "Coordinate instance will be printed." << endl;
    }

    // print doesn't change internal attributes
    // hence, const at the end
    void print() const
    {
        cout << "x=" << x << ", y=" << this->y << endl;
    }
};

// static member variables must be assigned outside of class
// because initialization must happen at exactly one location
// (a lot of different cpp files may include Coordinate)
int Coordinate::nInstances = 0;

// old c-style c-tor
void initCoordinate(Coordinate* ptr)
{
    ptr->x = 0;
    ptr->y = 0;
}

// ptr will be "this" pointer of a member function later
void printCoordinate(const Coordinate* ptr)
{
    printf("x=%d, y=%d\n", ptr->x, ptr->y);
}


int main(int argc, char* argv[])
{
//    initCoordinate(&c); // old c-style c-tor
    {
        int values[10] = { 1, 2, 3, 4 };
        values[1] = 10;
//        *(1 + values) = 10;
        2[values] = 20;
        5[values] = 30;

        for(int i=0; i<10; ++i)
            cout << values[i] << endl;

        Coordinate c;
        Coordinate c2(10, 20);
        Coordinate coords[10];
        for(int i=0; i<10; ++i)
        {
//            Coordinate& p = coords[i];
//            p.x=3;
//            p.y=4;

            // copy c-tor
//            Coordinate x(Coordinate(3, 4));
            Coordinate x = Coordinate(3, 4);

            // copy assignment
            Coordinate x2;
            // ....
            x2 = Coordinate(3, 4);

            // casting int to float
            int a = 1000;
            float f = (float)a;

            // casting coordinate to int!
            Coordinate z1(1000, 2000);
            int z = (int)z1;
            cout << "Cast value = " << z << endl;

//            coords[i] = Coordinate(3, 4);
        }

        printCoordinate(&c);
        printCoordinate(&c2);

        Coordinate::printHeader();
        c.print();
        c2.print();

        // this is old C++, not modern!
        // allocate Coordinate in Heap memory pool
        Coordinate* k = new Coordinate();
        delete k; // delete k instance, free its memory
    }

//    c.x = 0;
//    c.y = 0;

    // static isInitialized variable is set only once
    func();
    func();
    func();
    func();
    func();

    printf("Application Name: %s\n", argv[0]);
    for(int i=1; i<argc; ++i) {
//        printf("Argument #%d: %s\n", i, argv[i]);
        cout << "Argument #" << i << ": " << argv[i] << endl;
    }

//    int i=1;
//    while(i<argc) {
//        printf("Argument #%d: %s\n", i, argv[i]);
//        ++i;
//    }

    return 0;
}
