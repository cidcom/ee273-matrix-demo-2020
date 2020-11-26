#include "matrix.hpp"
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

matrix create2DMatrixFromFile(string filename)
{
    matrix mat;
    determineMatrixSize(filename, mat.nrows, mat.ncols);
    mat.data = allocate2DMatrix(mat.nrows, mat.ncols);
    fill2DMatrixFromFile(filename, mat);
    return mat;
}

void determineMatrixSize(string filename, int& nrows, int& ncols)
{
    ifstream inFile;
    inFile.open(filename);
    if (!inFile.is_open())
    {
        cerr << "coult not open file " << filename << endl;
        exit(-1);
    }

    // Determine the matrix dimensions
    nrows = 0;
    ncols = 0;
    string line;
    while(!inFile.eof())
    {
        getline(inFile, line);
        nrows++;
    }

    stringstream ss(line);
    while(!ss.eof())
    {
        string column_string;
        getline(ss, column_string, ' ');
        ncols++;
    }
    inFile.close();
}

double** allocate2DMatrix(int nrows, int ncols)
{
    // Allocate memory for the matrix nrows by ncols
    double** mat = new double*[nrows];
    for (int i=0; i<nrows; i++)
    {
        mat[i] = new double[ncols];
    }
    return mat;
}

void fill2DMatrixFromFile(string filename, matrix mat)
{
    ifstream inFile;
    inFile.open(filename);
    if (!inFile.is_open())
    {
        cerr << "coult not open file " << filename << endl;
        exit(-1);
    }
    int row = 0;
    int col = 0;
    while(!inFile.eof())
    {
        string line;
        getline(inFile, line);
        stringstream ss(line);
        col = 0;
        while(!ss.eof())
        {
            string column_string;
            getline(ss, column_string, ' ');
            double num = stod(column_string);
            mat.data[row][col] = num;
            col++;
        }
        row++;
    }

    inFile.close();
}
void print2DMatrix(matrix mat)
{
    // Print matrix
    for (int i=0; i<mat.nrows; i++)
    {
        for (int j=0; j<mat.ncols; j++)
        {
            cout << mat.data[i][j] << " ";
        }
        cout << endl;
    }
}


matrix add2DMatricies(matrix mat1, matrix mat2)
{
    // You can easily do checks
    if ((mat1.nrows != mat2.nrows) && (mat1.ncols!=mat2.ncols))
    {
        cerr << "when adding matrices the number or rows and columns must match" << endl;
        exit(-2);
    }
    int nrows = mat1.nrows;
    int ncols = mat1.ncols;
    matrix res;
    res.data = allocate2DMatrix(nrows, ncols);
    for (int i=0; i<nrows; i++)
    {
        for (int j=0; j<ncols; j++)
        {
            res.data[i][j] = mat1.data[i][j]+mat2.data[i][j];
        }
    }
    return res;
}

matrix subtract2DMatricies(matrix mat1, matrix mat2)
{
    if ((mat1.nrows != mat2.nrows) && (mat1.ncols!=mat2.ncols))
    {
        cerr << "when adding matrices the number or rows and columns must match" << endl;
        exit(-2);
    }
    int nrows = mat1.nrows;
    int ncols = mat1.ncols;
    matrix res;
    res.data = allocate2DMatrix(nrows, ncols);
    for (int i=0; i<nrows; i++)
    {
        for (int j=0; j<ncols; j++)
        {
            res.data[i][j] = mat1.data[i][j]-mat2.data[i][j];
        }
    }
    return res;
}