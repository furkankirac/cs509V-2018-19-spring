// returning a lambda (function object)

// std::variant, std::any
// RVO: return value optimization
// CRTP: curiously recurring template pattern, singleton pattern example

#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

// filter diye bir fonksiyon olsun. disaridan vector<T> alsin.
// bir de lambda alsin. lambda'ya T cinsinden deger verildiginde
// filtre sonrasinda kalip kalmayacagi ile ilgili boolean deger dondursun.
// filter fonksiyonundan
// lambda'nin true dondurdugu seyler yeni bir vector icinde push edilmis
// sekilde return edilsin

// vector<int> icin:
// 5'ten buyukleri getir
// tek sayilari getir
// 2. biti 1 olanlari getir
// gibi degisik lambdalarla kullanilabilir.

template<typename T, typename FUNC>
auto filter(const T& v, FUNC lambda)/* -> vector<T>*/
{
    auto filtered = T{};
    for(const auto& item : v)
        if(lambda(item))
            filtered.push_back(item);
    return filtered;
}


int main(int argc, char* argv[])
{
    auto s = vector<string>{"hello", "world", "how", "are", "you"};

    auto printIt = [](const auto& container) {
        for(const auto& str : container)
            cout << str << endl;
    };

    printIt(filter(s, [](const string& str) {
        return str.at(0) == 'h';
    }));

    cout << endl;

    printIt(filter(s, [](const string& str) {
        return str.size() == 5;
    }));

    cout << endl;

    auto v = list<double>{10.3, -5.8, 3.4};
    printIt(filter(v, [](double val) {
        return val >= 0.0;
    }));

    return 0;
}
