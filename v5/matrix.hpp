#ifndef MATRIX_HPP
#define MATRIX_HPP

#include<string>
using namespace std;

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
    friend ostream& operator<<(ostream& os, const Matrix& mat);

};







#endif /* MATRIX_HPP */