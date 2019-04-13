#include <iostream>

// templates: class, function, variable
// Vec2d, Vec3d, templates (typename, non-type param)

using namespace std;

inline auto dot_product_2d(int ax, int ay, int bx, int by) {
    return ax*bx + ay*by;
}

inline auto dot_product_3d(int ax, int ay, int az, int bx, int by, int bz) {
    return ax*bx + ay*by + az*bz;
}

struct Vec2d
{
    int x, y;
    auto dot_product(Vec2d b) { return x*b.x + y*b.y; }
};

inline auto dot_product_2d(Vec2d a, Vec2d b) { return a.x*b.x + a.y*b.y; }

struct Vec3d
{
    int x, y, z;
    auto dot_product(Vec3d b) { return x*b.x + y*b.y + z*b.z; }
};

inline auto dot_product_3d(Vec3d a, Vec3d b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

template<int nDims>
struct Vec
{
    int values[nDims];

    auto dot_product(const Vec<nDims>& other)
    {
        auto sum = 0;
        for(auto i=0; i<nDims; ++i)
            sum += values[i]*other.values[i];
        return sum;
    }

    void print() const
    {
        cout << "[";
        for(auto i=0; i<nDims; ++i) {
            if(i!=0)
                cout << ", ";
            cout << values[i];
        }
        cout << "]" << endl;
    }

};

template<int nDims>
void print(const Vec<nDims>& V)
{
    cout << "[";
    for(auto i=0; i<nDims; ++i) {
        if(i!=0)
            cout << ", ";
        cout << V.values[i];
    }
    cout << "]" << endl;
}


int main(int argc, char* argv[])
{
    cout << dot_product_2d(10, 10, 2, 3) << endl;
    cout << dot_product_3d(10, 10, 10, 2, 3, 4) << endl;

    cout << dot_product_2d(Vec2d{10, 10}, Vec2d{2, 3}) << endl;
    cout << dot_product_3d(Vec3d{10, 10, 10}, Vec3d{2, 3, 4}) << endl;

    cout << Vec2d{10, 10}.dot_product(Vec2d{2, 3}) << endl;
    cout << Vec3d{10, 10, 10}.dot_product(Vec3d{2, 3, 4}) << endl;

    cout << Vec<2>{10, 10}.dot_product(Vec<2>{2, 3}) << endl;
    cout << Vec<3>{10, 10, 10}.dot_product(Vec<3>{2, 3, 4}) << endl;

    Vec<2>{10, 10}.print();
    Vec<8>{1,2,3,4,5,6,7,8}.print();

    print(Vec<2>{10, 10});

    return 0;
}
