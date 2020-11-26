#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

#include "matrix.hpp"

int main()
{
    Matrix mat1 = Matrix("mat1.txt");
    mat1.printToConsole();

    cout << "++++++++++++" << endl;

    Matrix mat2 = Matrix("mat2.txt");
    mat2.printToConsole();

    Matrix res = mat1.add(mat2);
    cout << "==========" << endl;
    // //Unintentional mistake
    // cout << "Example mistake" << endl;
    // res.nrows=10;
    res.printToConsole();

    Matrix ressub = mat1.subtract(mat2);
    cout << "==========" << endl;
    ressub.printToConsole();



    return 0;
}