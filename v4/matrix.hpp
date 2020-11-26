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
    void printToConsole();
    Matrix add(Matrix rhs);
    Matrix subtract(Matrix rhs);

};







#endif /* MATRIX_HPP */