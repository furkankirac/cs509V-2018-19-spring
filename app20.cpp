// std::variant, std::any
// RVO: return value optimization
// CRTP: curiously recurring template pattern, singleton pattern example

#include <iostream>
#include <variant>

using namespace std;

enum VariantType
{
    String, Double, Int
};

struct Variant
{
    union
    {
        const char* s;
        double d;
        int i;
    };

    VariantType type;

    Variant() { }
    ~Variant() { }

    void operator=(const char* s) { this->s = s; type = String; }
    void operator=(int i) { this->i = i; type = Int; }
    void operator=(double d) { this->d = d; type = Double; }

    void print() const
    {
        switch(type)
        {
        case String:
            cout << "String: " << s << endl;
            break;
        case Double:
            cout << "Double: " << d << endl;
            break;
        case Int:
            cout << "Int: " << i << endl;
            break;
        }
    }
};


int main(int argc, char* argv[])
{
    {
        auto var = Variant{};
        var = 3.14;
        var.print();
        var = 10;
        var.print();
    }

    auto var = variant<const char*, double, int>{};
    var = 3.14;
//    var.print();
    var = 10;
//    var.print();

    try {
        auto i = get<int>(var);
        cout << i << endl;
    } catch(const bad_variant_access& e)
    {
        cout << "Tip uygun degil" << endl;
    }

    return 0;
}
