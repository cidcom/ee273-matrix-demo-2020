#ifndef MATRIX_HPP
#define MATRIX_HPP

#include<string>
using namespace std;

typedef struct {
    double** data;
    int nrows;
    int ncols;
} matrix;

matrix create2DMatrixFromFile(string filename);
void determineMatrixSize(string filename, int& nrows, int& ncols);
double** allocate2DMatrix(int nrows, int ncols);
void fill2DMatrixFromFile(string filename, matrix mat);
void print2DMatrix(matrix mat);

matrix add2DMatricies(matrix mat1, matrix mat2);
matrix subtract2DMatricies(matrix mat1, matrix mat2);




#endif /* MATRIX_HPP */