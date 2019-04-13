#include <iostream>

// unified/universal initialization
// operator overloading for function call operator
// templates: class, function, variable
// Vec2d, Vec3d, templates (typename, non-type param)

using namespace std;

struct Func {
    auto operator() (int x) const { return x+1; }
};

struct Func2 {
    auto operator() (int x) const { return x+2; }
};

int func1(int x) { return x+1; }
auto func2(int x) { return x+2; }

using func_ptr = int (*)(int);

auto callFunc(int x, func_ptr f) { return f(x); }

auto callFunc2(int x, Func f) { return f(x); }
auto callFunc2(int x, Func2 f) { return f(x); }


//auto callFunc(int x, int which)
//{
//    if(which == 0)
//        return func1(x);
//    return func2(x);
//}

int main(int argc, char* argv[])
{
    auto i{10};
    auto i2 = func1(i); // 11

    auto j{20};
    auto j2 = func2(j); // 22

    auto k = callFunc(i, &func1);
    auto l = callFunc(j, &func2);


    func1(5);
    auto f = Func{};
    f(5);
    return 0;
}
