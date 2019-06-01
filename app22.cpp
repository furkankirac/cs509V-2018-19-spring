#include <iostream>

using namespace std;

//struct Add_1_15 { static const int value = 16; };
//struct Add_3_10 { static const int value = 13; };
//struct Add_5_7 { static const int value = 12; };

template<typename...>
struct TypeDisplayer;

template<int a, int b> struct Add { static const int value = a + b; };
template<int a, int b> struct Mul { static const int value = a * b; };


template<int a, int b> struct Div       { static const int value = a / b; };
template<int k>        struct Div<k, 0> { static const int value = 0; };
template<>             struct Div<0, 0> { static const int value = -1; };

template<int first, int ... rest>
struct Multiply {
    static const int value = first * Multiply<rest...>::value;
};

template<int k>
struct Multiply<k>
{
    static const int value = k;
};

struct Naber { unsigned long long k; };


auto operator"" _naber(unsigned long long value)
{
    return Naber{value};
}

int main(int argc, char* argv[])
{
    auto h = 134_naber;
    auto s = "naber"s;
    cout << h.k << endl;

//    auto m = Multiply<10, 5, 3, -1>::value;
//    cout << m << endl;

    auto val = Div<0, 0>::value;
    cout << val << endl;

//    using T = decltype(argc);

//    auto t = TypeDisplayer<T>{};

//    3 * 5 + 2

//    auto val = Add<Mul<3, 5>::value, 2>::value;
//    cout << val << endl;

//    auto val2 = Div<10, 0>::value;
//    cout << val2 << endl;


//    auto beseyedieklersem = Add_5_7::value;
//    auto beseyedieklersem = Add<5, 7>::value;

//    cout << beseyedieklersem << endl;


    return 0;
}
