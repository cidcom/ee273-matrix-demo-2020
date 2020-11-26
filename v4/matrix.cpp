#include "matrix.hpp"
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

Matrix::Matrix()
{
    nrows=0;
    ncols=0;
    data = NULL;
}

Matrix::Matrix(int nrows, int ncols)
{
    this->nrows = nrows;
    this->ncols = ncols;
    allocate();
}
Matrix::Matrix(string filename)
{
    // Note the line below fills in the class' nrows, ncols
    determineMatrixSize(filename);
    allocate();
    readMatrixFromFile(filename);
}

Matrix::Matrix(const Matrix &mat)
{
    cout << "Copying ..." << endl;
    nrows = mat.nrows;
    ncols = mat.ncols;
    allocate();
    for (int i=0; i<nrows; i++)
    {
        for (int j=0; j<ncols; j++)
        {
            data[i][j] = mat.data[i][j];
        }
    }
}

Matrix::~Matrix()
{
    deallocate();
}
void Matrix::printToConsole()
{
    for (int i=0; i<nrows; i++)
    {
        for (int j=0; j<ncols; j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

/////////////////////////////////////////////
////////////// PRIVATE METHODS //////////////
/////////////////////////////////////////////
/**
 * This function allocates a 2D matrix; Note; the caller
 * must make sure that the data pointer is not overwritten
 */
void Matrix::allocate()
{
    // Allocate memory for the matrix nrows by ncols
    data = new double*[nrows];
    for (int i=0; i<nrows; i++)
    {
        data[i] = new double[ncols];
    }
}

void Matrix::deallocate()
{
    // TODO: check if nrows is valid if not return false
    if (data!=NULL)
    {
        for (int i=0; i<nrows; i++)
        {
            delete [] data[i];
        }
        delete [] data;
    }
    nrows=0;
    ncols=0;
}

void Matrix::determineMatrixSize(string filename)
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

void Matrix::readMatrixFromFile(string filename)
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
            data[row][col] = num;
            col++;
        }
        row++;
    }

    inFile.close();
}

Matrix Matrix::add(Matrix rhs)
{
    // You can easily do checks
    if ((nrows != rhs.nrows) && (ncols!=rhs.ncols))
    {
        cerr << "when adding matrices the number or rows and columns must match" << endl;
        exit(-2);
    }

    Matrix res(nrows, ncols);
    for (int i=0; i<nrows; i++)
    {
        for (int j=0; j<ncols; j++)
        {
            res.data[i][j] = data[i][j]+rhs.data[i][j];
        }
    }
    return res;
}

Matrix Matrix::subtract(Matrix rhs)
{
    // You can easily do checks
    if ((nrows != rhs.nrows) && (ncols!=rhs.ncols))
    {
        cerr << "when adding matrices the number or rows and columns must match" << endl;
        exit(-2);
    }

    Matrix res(nrows, ncols);
    for (int i=0; i<nrows; i++)
    {
        for (int j=0; j<ncols; j++)
        {
            res.data[i][j] = data[i][j]+rhs.data[i][j];
        }
    }
    return res;
}