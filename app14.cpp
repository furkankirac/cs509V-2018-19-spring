// returning a lambda (function object)
// returning more than one parameter

// std::pair, std::map, std::unordered_map, structured bindings
// std::variant, std::any
// structured bindings, returning more than one parameter

// RVO: return value optimization

// CRTP: curiously recurring template pattern, singleton pattern example

#include <iostream>
#include <map>
#include <unordered_map>
#include <list>

using namespace std;

struct Bar
{
    int i;
    float f;
    const char* c;

    Bar(int i, float f, const char* c) : i{i}, f{f}, c{c} { }
};

//template<typename T1, typename T2>
//struct Pair
//{
//    T1 t1;
//    T2 t2;
//    Pair(const T1& t1, const T2 t2) : t1{t1}, t2{t2} { }
//};

//template<typename T1, typename T2>
//auto makePair(const T1& t1, const T2 t2)
//{
//    return Pair<T1, T2>{t1, t2};
//}


auto foo() -> std::pair<int, const char*>
{
//    auto a = std::pair<int, const char*>{10, "Hello"};

    return {10, "Hello"};
}

int main(int argc, char* argv[])
{
    auto b = Bar{10, 5.3f, "Hello"};

    auto [val1, val2] = foo();

//    auto i2 = b.i;
//    auto f2 = b.f;
//    auto c2 = b.c;
    auto [i2, f2, c] = b;


    auto a = std::tuple<int, float, const char*>{10, 5.3f, "Hello"};
//    cout << get<2>(a) << endl;
//    cout << get<const char*>(a) << endl;

    auto l = list<string>{
        "Hello", "World"
        };

    auto m = unordered_map<string, double>{
        {"pi", 3.1415},
        {"e", 2.7182},
        {"avogadro", 6.02E-23},
        {"avogadro1", 6.02E-23},
        {"avogadro2", 6.02E-23},
        {"avogadro3", 6.02E-23}
    };
//    m["pi"] = 3.1415;
//    m["e"] = 2.7182;

//    for(const auto& a : m)
//        cout << a.first << " = " << a.second << endl;

    for(const auto& [key, value] : m)
        cout << key << " = " << value << endl;


//    cout << "pi = " << m["pi"] << endl;
//    cout << "e = " << m["e"] << endl;
//    cout << "unknown = " << m["unknown"] << endl;



    return 0;
}
