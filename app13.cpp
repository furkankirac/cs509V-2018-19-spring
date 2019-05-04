// functional programming: what is it?
// to "if" or not to "if"
// relations to overload resolution and template specializations (to follow)

// working with types: Type Displayer trick.
// template specializations (a functional programming primer)
// is_same, remove_const, remove_volatile, remove_cv, remove_reference, decay

// variadic parameters
// variadic templates: printAll: old style recursion, simplified if version

// good to know: template-template types, template auto, type constructors
// brace initialization, std::initializer_list

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

int sumAllIntegers(const char* title...) // run-time resolved variadic parameters example
{
    va_list args;
    va_start(args, title);

    cout << title << endl;

    int sum = 0;
    while(true)
    {
        int val = va_arg(args, int);
        sum += val;
        if(val == -1)
            break;
    }
    va_end(args);
    return sum;
}

template<int first, int ... rest>
inline void printInts()
{
    cout << first << endl;
    if constexpr(sizeof...(rest) > 0)
        printInts<rest...>();
}

template<typename First, typename ... Rest>
inline void printAll(First first, Rest... rest)
{
    cout << first << endl;
    if constexpr(sizeof...(Rest) > 0)
        printAll<Rest...>(rest...);
}


template<typename ... All>
void print(All ... all)
{
    ((cout << all << endl), ...); // fold expression
}


int main(int argc, char* argv[])
{
//    cout << sumAllIntegers("HELLO", 10, 20, 30, 5, 100, 253, 5) << endl;
    printInts<10, 20, 30>();

//    printAll<int, int, double, float, char>(10, 20, 30.5, 20.3f, 'c');
//    printAll(10, 20, 30.5, 20.3f, 'c');
    print(10, 20, 30.5, 20.3f, 'c');

    return 0;
}
