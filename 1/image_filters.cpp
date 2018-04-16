#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <complex>
#include <cmath>
#include <stdio.h>
#include <cassert>

using namespace std;

typedef complex<double> Complex;


static int rows,col;
Complex I=1i;
Complex Pi=3.1415926535897+I*0.0;

Complex A[1000][1000];
Complex Tr[1000][1000];
double Rt[1000][1000];

/**
* Coeficientes mu,nu para la matriz transformada de fourier de "matrix".
* si se tiene un arreglo bidimensional A[rows][col], se debe ingresar a la función como (Complex *)A
*/
Complex FT(double mu, double nu, Complex *matrix, double parity=-1.)
{
    Complex s=0.;

    for(int i=0; i<rows;i++)
    {
        for(int j=0;j<col;j++)
        {
            s+=matrix[i*col+j]*exp(parity*2.*Pi*I*(mu*i/rows+nu*j/col)));
        }
    }
    return s;
}


int main(int argc, char *argv[])
{
    string filename=argv[1];

    // leer la matriz
    ifstream file(filename);
    file >> rows >> col;


    for(int i=0; i<rows;i++)
    {
        for(int j=0;j<col;j++)
        {
            file >> A[i][j];
        }
    }

    file.close();

    // Calcular la transformada


    for(int a=0; a<rows;a++)
    {
        for(int b=0;b<col;b++)
        {
            Tr[a][b]=FT(a,b,(Complex *)A);
        }
    }

    // Calcular la transformada inversa


    for(int a=0; a<rows;a++)
    {
        for(int b=0;b<col;b++)
        {
            Rt[a][b]=FT(a,b,(Complex *)Tr,1.).real();
        }
    }

    cout << A[0][0] << endl;
    cout << Rt[0][0] << endl;

    return 0;
}
