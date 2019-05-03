// Fraction class
// explicit constructors

// know-it:
// in compiled machine code there is only executable code and non-executable data
// consider executable code as one big function.
// we emulate our so-called "functions" by loading/saving from/to stack
//   and jumping to different locations of machine language executable
// so "functions" are only our abstractions. they are portions of exe. code.
// you cannot create a new function at run-time. (there are exceptions)
// all functions are created at compile-time.

// function pointers: printWithStyleA, printWithStyleB
// function objects: PrintWithStyleA, PrintWithStyleB
// how to pass any one of PrintWithStyleA or PrintWithStyleB?
//  bad solution: inheritance and virtual functions.
//  (resolved at run-time but we know details about it at compile-time)
//  better solution: std::function. works with any callable. still run-time resolved
//  probably best solution: templates + lambdas

// new way of defining functions: lambdas: in-line function object instantiation


// unique_ptr, shared_ptr
// know-it: always shared_ptr + deferred d-tor as garbage col. <---> Java's way


// functional programming: what is it?
// to "if" or not to "if"
// relations to overload resolution and template specializations (to follow)

// working with types: Type Displayer trick.
// template specializations (a functional programming primer)
// is_same, remove_const, remove_volatile, remove_cv, remove_reference, decay

// good to know: template-template types, template auto, type constructors


// brace initialization, std::initializer_list

// variadic parameters
// variadic templates: printAll: old style recursion, simplified if version
// pack expansion
// initializer_list trick for runOnAll
// fold expressions

// A fancy clever constructor example

// ADL: Argument dependent lookup
// RVO: return value optimization
// CRTP: curiously recurring template pattern

// std::variant, std::map, std::any
// structured bindings

#include <iostream>

using namespace std;

struct Fraction
{
    int num;
    int denom;

    /*explicit */Fraction(int num = 0, int denom = 1) : num{num}, denom{denom} { }
    ~Fraction() = default;

    Fraction(const Fraction& other) : num{other.num}, denom{other.denom} { }

    Fraction& operator=(const Fraction& other)// = default;
    {
        num = other.num;
        denom = other.denom;
        return *this;
    }

    Fraction add(const Fraction& other)
    {
        return Fraction{num*other.denom + other.num*denom, denom*other.denom };
    }

};

void print(const Fraction& f)
{
    cout << f.num << "/" << f.denom << endl;
}

//Fraction add(const Fraction& a1, const Fraction& a2)
//{
//    // ...
//    return result;
//}


int main(int argc, char* argv[])
{
    auto f0 = Fraction{};
    auto f1 = Fraction{5, 2};
    auto f2 = Fraction{3, 4};
    f0 = 10; // copy assignment
    Fraction f3 = 10; // copy c-tor
    print(f0);

//    add(f1, f2);
    auto f_added = f1.add(f2);
    print(f_added);

    return 0;
}
