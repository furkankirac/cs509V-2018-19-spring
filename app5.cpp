#include <string>
#include <array>
#include <list>
#include <vector>
#include <iostream>

using namespace std;
//using namespace std::literals;

template<typename T, int nElems>
struct Array
{
    T values[nElems];
    T& operator[](int idx) const { return values[idx]; }
};

int main(int argc, char* argv[])
{
    // all doing the same thing: string impl. of standard lib.
    string s1("deneme");
    string s2 = "deneme";
    auto s3 = string("deneme");
    auto s4 = string{"deneme"};
    auto s5 = "deneme"s;

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;

    // continuous memory allocated run-time array impl. of std. lib.
//    vector<int> v;
    auto v1 = vector<int>{}; // create an empty vector waiting for integers
    auto v2 = vector<int>(100); // create a vector of 100 integers.
    auto v3 = vector<int>{100}; // create a vector of 1 integer whose value is 100.

    cout << "size of v1 = " << v1.size() << endl;
    cout << "size of v2 = " << v2.size() << endl;
    cout << "size of v3 = " << v3.size() << endl;

    v1.push_back(1000);
    v1.push_back(1000);
    v1.push_back(1000);
    v1.push_back(1000);
    v1.push_back(1000);
    cout << "size of v1 = " << v1.size() << endl;

    // linked-list implementation of standard library
    auto l1 = list<int>{};

    // use vector for dynamic memory allocation, as well
    // don't use old school new/delete
    {
        auto a = vector<int>(1000);
        auto ptr = new int[1000];
        //...
        delete[] ptr;
    }

    int K[10]; // old c-style array
    auto K2 = array<int, 10>{}; // c++ style array
    auto K3 = Array<int, 10>{5, 2, 3}; // my implementation
    K2[5] = 10; // standard access
    K2.at(5) = 20; // access with bounds checking

    auto A = vector<double>{1.1, 2.5, -5.8, 10.0, 20.3};
    auto sz = A.size(); // get size here only once
    for(auto i=0; i<sz; ++i) // use it here for performance
        cout << A[i] << endl;

    { // while loop equivalent
        auto i = 0;
        auto sz = A.size();
        while(i<sz) {
            cout << A[i] << endl;
            ++i;
        }
    }

    // range based for-loop
    // iterates over everthing and gives back values in container
    // no index is required, values are directly given
    for(auto a : A)
        cout << a << endl;

//    for(auto k3 : K3)
//        cout << k3 << endl;

    return 0;
}
