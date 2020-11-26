#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

#include "matrix.hpp"

int main()
{
    Matrix mat1 = Matrix("mat1.txt");
    cout << mat1;

    cout << "++++++++++++" << endl;

    Matrix mat2 = Matrix("mat2.txt");
    cout << mat2;

    Matrix res = mat1 + mat2;
    cout << "==========" << endl;
    // //Unintentional mistake
    // cout << "Example mistake" << endl;
    // res.nrows=10;
    cout << res;

    Matrix ressub = mat1-mat2;
    cout << "==========" << endl;
    cout << ressub;

    cout << "==========" << endl;
    cout << "Multiply:" << endl;
    cout << mat1*mat2;


    return 0;
}