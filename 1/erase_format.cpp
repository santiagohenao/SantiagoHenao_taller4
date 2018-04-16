#include <iostream>
#include <fstream>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <iterator>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc==2)
    {
        string filename=argv[1];

        // leer matriz
        int rows,col;
        ifstream file(filename);
        file >> rows >> col;

        double A[rows][col];

        for(int i=0; i<rows;i++)
        {
            for(int j=0;j<col;j++)
            {
                file >> A[i][j];
            }
        }

        file.close();

        remove(filename.c_str( ));

        ofstream result(filename);

        for(int i=0; i<rows;i++)
        {
            for(int j=0;j<col;j++)
            {
                result << A[i][j] << " ";
            }
            result << "\n";
        }
        return 0;
    }
    else if(argc==3)
    {
        string filename=argv[1];
        string outname=argv[2];

        // leer matriz
        int rows,col;
        ifstream file(filename);
        file >> rows >> col;

        double A[rows][col];

        for(int i=0; i<rows;i++)
        {
            for(int j=0;j<col;j++)
            {
                file >> A[i][j];
            }
        }

        file.close();

        ofstream result(outname);

        for(int i=0; i<rows;i++)
        {
            for(int j=0;j<col;j++)
            {
                result << A[i][j] << " ";
            }
            result << "\n";
        }
        return 0;
    }

}
