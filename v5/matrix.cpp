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
    if (nrows>0 && ncols>0)
    {
        allocate();
    } else {
        nrows=0;
        ncols = 0;
        data = NULL;
    }

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
    if (data!=NULL) {
        deallocate();
    }
}

Matrix Matrix::operator=(const Matrix& rhs)
{
    if (data!=NULL)
    {
        deallocate();
    }
    this->nrows = rhs.nrows;
    this->ncols = rhs.ncols;
    allocate();
    for (int i=0; i<nrows; i++)
    {
        for (int j=0; j<ncols; j++)
        {
            data[i][j] = rhs.data[i][j];
        }
    }
}

Matrix Matrix::operator+(const Matrix& rhs)
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

Matrix Matrix::operator-(const Matrix& rhs)
{
    // You can easily do checks
    if ((nrows != rhs.nrows) && (ncols!=rhs.ncols))
    {
        cerr << "when subtracting matrices the number or rows and columns must match" << endl;
        exit(-2);
    }

    Matrix res(nrows, ncols);
    for (int i=0; i<nrows; i++)
    {
        for (int j=0; j<ncols; j++)
        {
            res.data[i][j] = data[i][j]-rhs.data[i][j];
        }
    }
    return res;
}
Matrix Matrix::operator*(const Matrix& rhs)
{
    // You can easily do checks
    if ((ncols != rhs.nrows) && (nrows>0) && (rhs.ncols>0))
    {
        cerr << "when multiplying matrices the number or columns from left hand side must be equal number of rows on the right" << endl;
        exit(-2);
    }
    Matrix res(nrows, rhs.ncols);
    for (int i=0; i<nrows; i++)
    {
        for (int j=0; j<rhs.ncols; j++)
        {
            res.data[i][j]=0;
            for (int k=0; k<ncols; k++)
            {
                res.data[i][j] += data[i][k] + rhs.data[k][j];
            }
        }
    }
    return res;
}

ostream& operator<<(ostream& os, const Matrix& mat)
{
    for (int i=0; i<mat.nrows; i++)
    {
        for (int j=0; j<mat.ncols; j++)
        {
            os << mat.data[i][j] << " ";
        }
    }
    return os;
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