// returning a lambda (function object)

// std::variant, std::any
// RVO: return value optimization
// CRTP: curiously recurring template pattern, singleton pattern example

#include <iostream>
#include <vector>

using namespace std;

// lambdaniz var olan bir vector<int>'i capture etsin (referans ile)
// ismi push olsun
// push'a verilen int argumani vector'e push_back edilsin.
// lambda vectorde bu islemden sonra kac adet eleman oldugunu return etsin

struct Print
{
    int& sz;

    Print(int& sz) : sz{sz} { }

    auto operator() () const { cout << sz << endl; }
};

struct Push
{
    vector<int>& v;

    Push(vector<int>& v) : v{v} { }

    auto operator() (int value) const
    {
        v.push_back(value);
        return v.size();
    }
};


int main(int argc, char* argv[])
{
//    vector<int> v{1, 2, 3, -1, -2, -3};
    auto v = vector<int>{1, 2, 3, -1, -2, -3};

    auto push = Push{v};
//            [&v](int value) {
//        v.push_back(value);
//        return v.size();
//    };


    auto sz = 0;
    auto print = Print{sz};  //[&sz]() { cout << sz << endl; };

    sz = push(10);
    print();

    sz = push(20);
    print();

    sz = push(30);
    print();

    cout << endl;

    for(auto value : v)
        cout << value << endl;

    return 0;
}
