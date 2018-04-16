#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

typedef complex<double> Complex;


Complex I=1i;
Complex Pi=3.1415926535897+I*0.0;

Complex FourierTransform(double mu, double nu)
{
    Complex s=0.;
    for(int i=0;i<tdata.size();i++)
    {
        s+=ydata[i]*exp(-2.0*Pi*I*freq*tdata[i]);
    }
    return s;
}


int main(int argc, char *argv[])
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

}
