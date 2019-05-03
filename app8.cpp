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

#include "Matrix.h"

using namespace std;

int main(int argc, char* argv[])
{
    auto stylerA = [](auto value) { cout << value << ", "; };
    auto stylerB = [](auto value) { cout << value << "| "; };

    auto m1 = Matrix<int>{5, 5};
    m1(3, 2) = 100;

    auto m2 = Matrix<double>{3, 3};
    m2(1, 2) = 200.0;

    m1.print(stylerA);
    cout << endl;
    m1.print(stylerB);
    cout << endl;

    m2.print(stylerA);
    cout << endl;
    m2.print(stylerB);
    cout << endl;

    return 0;
}
