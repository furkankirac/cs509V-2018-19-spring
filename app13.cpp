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

// std::variant, std::map, std::any
// structured bindings

// ADL: Argument dependent lookup
// RVO: return value optimization
// CRTP: curiously recurring template pattern


#include <iostream>

using namespace std;

template<typename T>
struct TypeDisplayer;

namespace my
{
    template<typename T1, typename T2>  struct is_same       { static const bool value = false; };
    template<typename T>                struct is_same<T, T> { static const bool value = true; };
//    template<typename T>                struct is_same<T, char> {
//        static const bool value = true;
//        static const bool is_char = true;
//    };

//    struct is_same_int_float    { static const bool value = false; };
//    struct is_same_int_int      { static const bool value = true; };

    template<typename T>    struct remove_const             { using type = T; };
    template<typename K>    struct remove_const<const K>    { using type = K; };
    template<typename K>    struct remove_const<const K*>   { using type = K*; };

    template<typename T>    struct remove_volatile                  { using type = T; };
    template<typename K>    struct remove_volatile<volatile K>      { using type = K; };
    template<typename K>    struct remove_volatile<volatile K*>     { using type = K*; };

    template<typename T>    struct remove_cv
    {
        using type = typename remove_const< typename remove_volatile<T>::type >::type;
    };

    template<typename T>    struct remove_reference      { using type = T; };
    template<typename K>    struct remove_reference<K&>  { using type = K; };
    template<typename K>    struct remove_reference<K&&> { using type = K; };
}


int main(int argc, char* argv[])
{
    auto b1 = my::is_same<int, float>::value;
    auto b2 = my::is_same<double, double>::value;

//    auto a = TypeDisplayer< my::remove_cv<const volatile int>::type >{};
//    auto b = TypeDisplayer< my::remove_cv<volatile char*>::type >{};

    auto r = TypeDisplayer< remove_reference<int&>::type >{};

//    auto c = my::is_same<double, char>::is_char;

    cout << b1 << endl;
    cout << b2 << endl;

    return 0;
}
