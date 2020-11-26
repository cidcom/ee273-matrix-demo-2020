#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

#include "matrix.hpp"

int main()
{
    string fname1 = "mat1.txt";

    matrix mat1 = create2DMatrixFromFile(fname1);
    /*
    determineMatrixSize(fname, nrows1, ncols1);
    cout << nrows1 << "," << ncols1 << endl;
    mat1 = allocate2DMatrix(nrows1, ncols1);
    fill2DMatrixFromFile(fname, mat1, nrows1, ncols1);
    */


    print2DMatrix(mat1);

    cout << "++++++++++++" << endl;

    string fname2 = "mat2.txt";
    matrix mat2 = create2DMatrixFromFile(fname2);
    print2DMatrix(mat2);

    matrix res = add2DMatricies(mat1, mat2);
    cout << "==========" << endl;
    // //Unintentional mistake
    // cout << "Example mistake" << endl;
    // res.nrows=10;
    print2DMatrix(res);

    matrix ressub = subtract2DMatricies(mat1, mat2);
    cout << "==========" << endl;
    print2DMatrix(ressub);



    return 0;
}