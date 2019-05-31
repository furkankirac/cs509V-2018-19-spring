// returning a lambda (function object)

// std::variant, std::any
// RVO: return value optimization
// CRTP: curiously recurring template pattern, singleton pattern example

#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

// bubblesort programlayalim.
// siralama kriterini lambda ile verebilelim.
// herhangi bir container uzerinde calissin
// containerin kendisini direk degistirsin

template<typename T, typename FUNC>
void bubblesort(T& container, FUNC lambda)
{
    auto sz = container.size();
    for(int i=0; i<sz-1; ++i)
    {
        auto hasSwapped = false;
        for(int j=0; j<sz-1; ++j)
        {
            if(!lambda(container[j], container[j+1]))
            {
                swap(container[j], container[j+1]);
                hasSwapped = true;
            }
        }
        if(!hasSwapped)
            break;
    }
}

template<typename T>
void bubblesort(T& container)
{
    bubblesort(container, [](int a, int b) { return a < b; });
}

int main(int argc, char* argv[])
{
    auto v = vector<int>{10, -10, 20, -20, 30};
//    bubblesort(v);
    bubblesort(v, [](int a, int b) {
        return a > b;
    });

    for(const auto& item : v)
        cout << item << endl;

    return 0;
}
