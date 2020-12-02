#ifndef MATRIX_HPP
#define MATRIX_HPP

#include<string>
#include<tuple>
using namespace std;

typedef pair<int, int> slice_t;

class Matrix
{
private:
    double** data;
    int nrows;
    int ncols;
    void allocate();
    void deallocate();
    void determineMatrixSize(string filename);
    void readMatrixFromFile(string filename);
public:
    Matrix();
    Matrix(int nrows, int ncols);
    Matrix(string filename);
    Matrix(const Matrix &mat);
    ~Matrix();
    Matrix add(Matrix rhs);
    Matrix subtract(Matrix rhs);
    Matrix operator=(const Matrix& rhs);
    Matrix operator+(const Matrix& rhs);
    Matrix operator-(const Matrix& rhs);
    Matrix operator*(const Matrix& rhs);
    double& operator()(int row, int col);
    Matrix operator()(slice_t row_range, slice_t column_range);
    friend ostream& operator<<(ostream& os, const Matrix& mat);

};

#endif /* MATRIX_HPP */