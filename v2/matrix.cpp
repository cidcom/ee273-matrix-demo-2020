#include "matrix.hpp"
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

double** create2DMatrixFromFile(string filename, int& nrows, int& ncols)
{
    determineMatrixSize(filename, nrows, ncols);
    double** mat = allocate2DMatrix(nrows, ncols);
    fill2DMatrixFromFile(filename, mat, nrows, ncols);
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

void fill2DMatrixFromFile(string filename, double** mat, int nrows, int ncols)
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
            mat[row][col] = num;
            col++;
        }
        row++;
    }

    inFile.close();
}
void print2DMatrix(double** mat, int nrows, int ncols)
{
    // Print matrix
    for (int i=0; i<nrows; i++)
    {
        for (int j=0; j<ncols; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}


double** add2DMatricies(double** mat1, double** mat2, int nrows, int ncols)
{
    double** res = allocate2DMatrix(nrows, ncols);
    for (int i=0; i<nrows; i++)
    {
        for (int j=0; j<ncols; j++)
        {
            res[i][j] = mat1[i][j]+mat2[i][j];
        }
    }
    return res;
}

double** subtract2DMatricies(double** mat1, double** mat2, int nrows, int ncols)
{
    double** res = allocate2DMatrix(nrows, ncols);
    for (int i=0; i<nrows; i++)
    {
        for (int j=0; j<ncols; j++)
        {
            res[i][j] = mat1[i][j]-mat2[i][j];
        }
    }
    return res;
}