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
#include <vector>
#include <algorithm>

using namespace std;

//struct Comparator
//{
//    int step=10;

//    bool ascending;
//    int& k;
//    Comparator(bool ascending, int& k) : ascending{ascending}, k{k} { }

//    auto operator()(int a, int b) const
//    {
//        k += step;
//        if(ascending)
//            return a < b;
//        return a > b;
//    }
//};


int main(int argc, char* argv[])
{
    auto v = vector<int>{20, 13, -5, 50, 42, 101, -10};

    bool ascending = true;
    int k = 0;

//    auto descendingSorter = [step=10, ascending, &k](int a, int b) {
//        k += step;
//        if(ascending)
//            return a < b;
//        return a > b;
//    };
    auto descendingSorter = Comparator{ascending, k};

    sort(v.begin(), v.end(), descendingSorter);
    for(auto val : v)
        cout << val << endl;

    cout << "Danisma sayisi = " << k << endl;

    return 0;
}
