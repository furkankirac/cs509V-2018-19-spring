//#include <stdio.h>

#include <iostream>

// almost always auto - aaa rule: move type to the right
// operator overloading as free functions
// user-defined literals
// unified/universal initialization
// Vec2d, Vec3d, templates (typename, non-type param)


using namespace std;

auto string_length(const char* p) -> int
{
    auto sz = 0;
    while(*p++) ++sz;
    return sz;
}

class String
{
//private:
    int str_size;
    char* mem;

public:
    void init(int sz)
    {
        clear();
        mem = new char[sz+1];
    }

    void copyFrom(const char* p)
    {
        for(int i=0; i<str_size; ++i)
            mem[i] = p[i];
        mem[str_size] = 0; // = '\0';
    }

    String() : str_size(0), mem(nullptr)
    {
    }

    String(char const* p)
    {
        cout << "constructing String." << endl;
        str_size = string_length(p);
        init(str_size);
        copyFrom(p);
    }

    // copy c-tor
    String(const String& other) :
        str_size(other.size()), mem(nullptr)
    {
        init(str_size);
        copyFrom(other.mem);
    }

    // copy assignment
    String& operator=(const String& other)
    {
        str_size = other.size();
        init(str_size);
        copyFrom(other.mem);

        return *this;
    }

    String(String&& other) :
        str_size(other.size()),
        mem(other.mem)
    {
        other.str_size = 0;
        other.mem = nullptr;
    }

    String& operator=(String&& other)
    {
        str_size = other.size();
        mem = other.mem;
        other.str_size = 0;
        other.mem = nullptr;

        return *this;
    }

    char& operator[](int idx) const
    {
        return mem[idx];
    }


    void clear()
    {
        if(mem)
        {
            cout << "clearing String." << endl;
            delete[] mem;
            mem = nullptr;
        }
    }


    ~String()
    {
        cout << "destroying String." << endl;
        clear();
    }

    int size() const { return str_size; }

    char* data() const { return mem; }
};

int main(int argc, char* argv[])
{
    auto s = String("Deneme");
    cout << s[3] << endl;
    s[3] = 'a';

    auto x = String(s); // copy c-tor
    auto y = String(s); // copy c-tor
    auto z = String();
    z = s; // copy assignment

    cout << "size = " << s.size() << endl;
    cout << s.data() << endl;

    auto a = (String&&)s; // move c-tor

    cout << "size = " << a.size() << endl;
    cout << a.data() << endl;

    cout << "size = " << s.size() << endl;
//    cout << s.data() << endl;

    s.clear();
    return 0;
}
