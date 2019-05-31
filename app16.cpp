// returning a lambda (function object)

// std::variant, std::any
// RVO: return value optimization
// CRTP: curiously recurring template pattern, singleton pattern example

#include <iostream>

using namespace std;

struct Ascending
{
    int asc_count;
    int& a;
    int& b;

    Ascending(int& a, int& b) : asc_count{0}, a{a}, b{b} { }

    auto operator() (const string& title)
    {
        asc_count++;
        cout << title << endl;
        if(a > b)
            swap(a, b);
        cout << asc_count << endl;
    }
};

int main(int argc, char* argv[])
{
    auto a = 100, b = 500;

    auto ascending = [asc_count=0, &a, &b](const string& title) mutable {
        asc_count++;
        cout << title << endl;
        if(a > b)
            swap(a, b);
        cout << asc_count << endl;
    };

//    auto ascending = Ascending{a, b};


    auto descending = [&](const string& title) {
        cout << title << endl;
        if(a < b)
            swap(a, b);
    };

    ascending("1st ascending sort");
    descending("1st descending sort");
    ascending("2nd ascending sort");

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
