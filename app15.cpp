// returning a lambda (function object)

// std::variant, std::any
// RVO: return value optimization
// CRTP: curiously recurring template pattern, singleton pattern example

#include <iostream>

#include <functional>

using namespace std;

struct MyLambda
{
    int& a;
    double k;

    MyLambda(int& a, double k) : a{a}, k{k} { }

    auto operator() (int b) const {
//        ++k;
        ++a;
        return (a + b)*k;
    }
};


auto makeLambda(int& a)
{
//    MyLambda l{a};

    double k = 10;
//    auto l = MyLambda{a, k};
//    return l;

    return [&a, k](int b) { ++a; return (a + b)*k; };
}

int main(int argc, char* argv[])
{
    auto a = 100;

    auto l = makeLambda(a);

    auto retval = l(10); // 111

    cout << " a = " << a << endl;
    cout << " retval = " << retval << endl;


    return 0;
}
