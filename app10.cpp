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
#include <memory>

using namespace std;

template<typename T> void repeat(const T text, int times)
{
    for(int i=0; i<times; ++i)
        cout << text << endl;
}

auto repeat_lambda = [](auto text, int times)
{
    for(int i=0; i<times; ++i)
        cout << text << endl;
};


struct Dummy
{
    int size;
    int* mem;
    Dummy(int size) : size{size}, mem{new int[size]}
    {
    }

    Dummy(const Dummy& other) : size{other.size}, mem{new int[size]}
    {
        copy(other.mem, other.mem+other.size, mem);
    }

    ~Dummy()
    {
        delete[] mem;
        mem = nullptr;
    }
};

void func(shared_ptr<Dummy> d)
{

}


int main(int argc, char* argv[])
{
    auto dummy = make_shared<Dummy>(1000000);
    func(dummy);
//    auto dummy2 = dummy; // copy c-tor

    repeat("Hello World!", 3);
    repeat(1000, 2);
    cout << endl;
    repeat_lambda("Hello World!", 3);
    repeat_lambda(1000, 2);

    return 0;
}
