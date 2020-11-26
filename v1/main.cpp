#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    string fname = "mat1.txt";
    ifstream inFile;
    inFile.open(fname);
    if (!inFile.is_open())
    {
        cerr << "coult not open file " << fname << endl;
        return -1;
    }

    // Determine the matrix dimensions
    int nrows = 0;
    int ncols = 0;
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
    inFile.clear();
    inFile.seekg(0);

    // Allocate memory for the matrix nrows by ncols
    double** mat = new double*[nrows];
    for (int i=0; i<nrows; i++)
    {
        mat[i] = new double[ncols];
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

    // Print matrix
    for (int i=0; i<nrows; i++)
    {
        for (int j=0; j<ncols; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}