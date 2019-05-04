#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

struct Shape
{
    virtual double area() const = 0;
};

struct Rectangle : public Shape
{
    double width;
    double height;
    Rectangle(double width, double height) : width{width}, height{height} { }

    double area() const override { return width*height; }
};

struct Circle : public Shape
{
    double radius;
    Circle(double radius) : radius{radius} { }

    double area() const override { return M_PI*radius*radius; }
};


int main(int argc, char* argv[])
{
    auto r = Rectangle{10.0, 20.0};
    auto c = Circle{3.5};
    for(auto s : vector<Shape*>{&r, &c})
        cout << s->area() << endl;

    return 0;
}
