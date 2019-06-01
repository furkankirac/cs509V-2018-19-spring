// std::variant, std::any
// RVO: return value optimization
// CRTP: curiously recurring template pattern, singleton pattern example

#include <iostream>
#include <variant>
#include <unordered_map>

using namespace std;

struct VeryBig
{
    VeryBig() { cout << "constructed" << endl; }
    ~VeryBig() { cout << "destructed" << endl; }

    VeryBig(const VeryBig& other)
    {
        cout << "copy c-tor" << endl;
    }

    VeryBig(VeryBig&& other)
    {
        cout << "move c-tor" << endl;
    }

    void operator=(const VeryBig& other)
    {
        cout << "copy assign" << endl;
    }

    void operator=(VeryBig&& other)
    {
        cout << "move assign" << endl;
    }
};

VeryBig foo()
{
    auto vb = VeryBig{};
    return vb;
}

int main(int argc, char* argv[])
{
    auto bigobj = foo();


//    using Variant = variant<int, double, string>;

//    auto m = unordered_map<Variant, Variant>{
//        { "hello", "world" },
//        { "pi", 3.1415 },
//        { "apt.no", 7 },
//        { 10, "naber" }
//    };

//    for(const auto& [key, value] : m)
//    {
//        std::visit([](auto&& arg) {
//            cout << arg << endl;
////            using T = decay_t<decltype(arg)>;
////            if constexpr (is_same_v<T, int>)
////                std::cout << "int with value " << arg << ',';
////            else if constexpr (is_same_v<T, double>)
////                std::cout << "double with value " << arg << ',';
////            else if constexpr (is_same_v<T, string>)
////                std::cout << "string with value \"" << arg << "\",";
//        },
//        key
//        );

//        std::visit([](auto&& arg) {
//            using T = decay_t<decltype(arg)>;
//            if constexpr (is_same_v<T, int>)
//                std::cout << "int with value " << arg << '\n';
//            else if constexpr (is_same_v<T, double>)
//                std::cout << "double with value " << arg << '\n';
//            else if constexpr (is_same_v<T, string>)
//                std::cout << "string with value \"" << arg << "\"\n";
//        },
//        value
//        );

//    }

    return 0;
}
