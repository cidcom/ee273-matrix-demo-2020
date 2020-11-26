#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    ///////////////////
    // Load first array
    ///////////////////
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

    // Read file and load it to memory
    int current_row = 0;
    int current_col = 0;
    while(!inFile.eof())
    {
        string line;
        getline(inFile, line);
        stringstream ss(line);
        current_col = 0;
        while(!ss.eof())
        {
            string column_string;
            getline(ss, column_string, ' ');
            double num = stod(column_string);
            mat[current_row][current_col] = num;
            current_col++;
        }
        current_row++;
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

    ///////////////////
    // Load second array
    ///////////////////
    string fname2 = "mat1.txt";
    inFile.open(fname2);
    if (!inFile.is_open())
    {
        cerr << "coult not open file " << fname2 << endl;
        return -1;
    }

    // Determine the matrix dimensions
    int nrows2 = 0;
    int ncols2 = 0;
    while(!inFile.eof())
    {
        getline(inFile, line);
        nrows2++;
    }

    stringstream ss2(line);
    while(!ss2.eof())
    {
        string column_string;
        getline(ss2, column_string, ' ');
        ncols2++;
    }
    inFile.clear();
    inFile.seekg(0);

    // Allocate memory for the matrix nrows by ncols
    double** mat2 = new double*[nrows];
    for (int i=0; i<nrows; i++)
    {
        mat2[i] = new double[ncols];
    }

    // Read file and load it to memory
    current_row = 0;
    current_col = 0;
    while(!inFile.eof())
    {
        string line;
        getline(inFile, line);
        stringstream ss(line);
        current_col = 0;
        while(!ss.eof())
        {
            string column_string;
            getline(ss, column_string, ' ');
            double num = stod(column_string);
            mat2[current_row][current_col] = num;
            current_col++;
        }
        current_row++;
    }

    inFile.close();

    // Print matrix
    for (int i=0; i<nrows; i++)
    {
        for (int j=0; j<ncols; j++)
        {
            cout << mat2[i][j] << " ";
        }
        cout << endl;
    }

    /// Now let's add
    // We need to allocate a new array AGAIN!!!
    int nrows_result = nrows;
    int ncols_result = ncols;
    double** res = new double*[nrows];
    for (int i=0; i<nrows_result; i++)
    {
        res[i] = new double[ncols_result];
    }

    // Now add
    for (int i=0; i<nrows; i++)
    {
        for (int j=0; j<ncols; j++)
        {
            res[i][j] = mat[i][j]+mat2[i][j];
        }
    }

    // Now let's print to make sure we added correctly
    for (int i=0; i<nrows_result; i++)
    {
        for (int j=0; j<ncols_result; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}