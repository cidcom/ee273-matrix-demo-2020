#ifndef MATRIX_HPP
#define MATRIX_HPP

#include<string>
using namespace std;

double** create2DMatrixFromFile(string filename, int& nrows, int& ncols);
void determineMatrixSize(string filename, int& nrows, int& ncols);
double** allocate2DMatrix(int nrows, int ncols);
void fill2DMatrixFromFile(string filename, double** mat, int nrows, int ncols);
void print2DMatrix(double** mat, int nrows, int ncols);

double** add2DMatricies(double** mat1, double** mat2, int nrows, int ncols);
double** subtract2DMatricies(double** mat1, double** mat2, int nrows, int ncols);




#endif /* MATRIX_HPP */