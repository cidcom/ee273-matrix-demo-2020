#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

#include "matrix.hpp"

int main()
{
    string fname1 = "mat1.txt";
    int nrows1, ncols1;
    double** mat1 = create2DMatrixFromFile(fname1, nrows1, ncols1);
    /*
    determineMatrixSize(fname, nrows1, ncols1);
    cout << nrows1 << "," << ncols1 << endl;
    mat1 = allocate2DMatrix(nrows1, ncols1);
    fill2DMatrixFromFile(fname, mat1, nrows1, ncols1);
    */


    print2DMatrix(mat1, nrows1, ncols1);

    cout << "++++++++++++" << endl;

    string fname2 = "mat2.txt";
    int nrows2, ncols2;
    double** mat2 = create2DMatrixFromFile(fname2, nrows2, ncols2);
    print2DMatrix(mat2, nrows2, ncols2);

    double** res = add2DMatricies(mat1, mat2, nrows1, ncols1);
    cout << "==========" << endl;
    print2DMatrix(res, nrows1, ncols1);


    double** ressub = subtract2DMatricies(mat1, mat2, nrows1, ncols1);
    cout << "==========" << endl;
    print2DMatrix(ressub, nrows1, ncols1);

    return 0;
}