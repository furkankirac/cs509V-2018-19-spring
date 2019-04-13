#include <iostream>
#include <vector>

using namespace std;

struct MatrixBase
{
    // abstract class because of = 0;
    // inheriting classes MUST implement print function later
    virtual void print() const = 0;
    virtual void show() const {
        cout << "Showing..." << endl;
    }
};

template<typename T>
struct Matrix : public MatrixBase
{
    int nRows, nCols;
    vector<T> values;

    Matrix(int nRows, int nCols) :
        nRows{nRows},
        nCols{nCols},
        // std::vector c-tor for this many Ts to be allocated
        // don't use curly brackets here, it means different thing
        values(nRows*nCols)
    { }

    const T& operator() (int row_idx, int col_idx) const {
        return values[row_idx * nCols + col_idx];
    }

    T& operator() (int row_idx, int col_idx) {
        return values[row_idx * nCols + col_idx];
    }

    void print() const override
    {
        for(int i=0; i<nRows; ++i)
        {
            for(int j=0; j<nCols; ++j)
            {
                if(j!=0)
                    cout << " ";
                cout << (*this)(i, j);
            }
            cout << endl;
        }
    }
};

int main(int argc, char* argv[])
{
    auto mf = Matrix<float>{3, 5};
    mf(2, 1) = 1000.5f;
    mf.print();

    cout << endl;

    auto mi = Matrix<int>{5, 2};
    mi(2, 1) = 500;
    mi.print();

    auto V = vector<MatrixBase*>{};
    V.push_back(&mi);
    V.push_back(&mi);
    V.push_back(&mf);
    V.push_back(&mi);

    for(auto m : V) // m is a MatrixBase*
    {
        cout << "---------------" << endl;
        m->print();
    }

//    for(auto m : V) // m is a MatrixBase*
//    {
//        cout << "---------------" << endl;
//        if(m->type == Integer)
//            ((Matrix<int>*)m)->print();
//        else if(m->type == Float)
//            ((Matrix<float>*)m)->print();
//    }

    return 0;
}
