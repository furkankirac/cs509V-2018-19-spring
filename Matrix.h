#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

using Brightness = unsigned char;

struct Pixel // Colored Pixel
{
    Brightness red, green, blue;
};

struct MatrixBase
{
    // abstract class because of = 0;
    // inheriting classes MUST implement print function later
    virtual void print() const = 0;
    virtual void show() const {
        std::cout << "Showing..." << std::endl;
    }
};

template<typename T>
struct Matrix : public MatrixBase
{
    int nRows, nCols;
    std::vector<T> values;

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
                    std::cout << " ";

                if constexpr(!std::is_same<T, Pixel>::value)
                    std::cout << (*this)(i, j);
            }
            std::cout << std::endl;
        }
    }
};

struct Image : public Matrix<Pixel>
{
    // 1st method for c-tor
//    Image(int nRows, int nCols) :
//        Matrix<Pixel>{nRows, nCols}
//    { }

    // 2nd method: this inherits c-tors of base class Matrix<Pixel>
    // because normally c-tors are not inherited by default
    // you need to explicitly say it
    using Matrix<Pixel>::Matrix;

    void print() const override
    {
        for(int i=0; i<nRows; ++i)
        {
            for(int j=0; j<nCols; ++j)
            {
                if(j!=0)
                    std::cout << " ";
                const auto& pix = (*this)(i, j);
                std::cout << "(" << (int)pix.red << ","
                     << (int)pix.blue << ","
                     << (int)pix.green << ")";
            }
            std::cout << std::endl;
        }
    }
};

#endif // MATRIX_H
