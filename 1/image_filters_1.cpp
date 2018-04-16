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


int rows,col;
Complex I=1i;
Complex Pi=3.1415926535897+I*0.0;

/**
* Coeficientes mu,nu para la matriz transformada de fourier de "matrix".
* si se tiene un arreglo bidimensional A[rows][col], se debe ingresar a la función como (Complex *)A
*/
Complex FT(double mu, double nu, Complex matrix[],double parity=-1.)
{
    Complex s=0.;

    for(int i=0; i<rows;i++)
    {
        for(int j=0;j<col;j++)
        {
            s+=matrix[i*col+j]*exp(parity*2.*Pi*I*(mu*i/rows+nu*j/col));
        }
    }
    return s;
}

double max(double *array)
{
    double sie;
    sie=sizeof(array)/sizeof(array[0]);
    double m=array[0];
    for(int i=0;i<sie;i++)
    {
        if(array[i]>m)
        {
            m=array[i];
        }
    }
    return m;
}

Complex filters(Complex input, mu,nu)
{
    return 
}

int main(int argc, char *argv[])
{
    string filename=argv[1];

    // leer la matriz
    ifstream file(filename);
    file >> rows >> col;

    Complex A[rows*col];

    for(int i=0; i<rows;i++)
    {
        for(int j=0;j<col;j++)
        {
            file >> A[i*col+j];
        }
    }

    file.close();

    // Calcular la transformada

    Complex B[rows*col];

    for(int a=0; a<rows;a++)
    {
        for(int b=0;b<col;b++)
        {
            B[a*col+b]= FT(a,b,A);
        }
    }
    // Calcular la transformada inversa


    double C[rows*col];

    for(int a=0; a<rows;a++)
    {
        for(int b=0;b<col;b++)
        {
            C[a*col+b]=FT(a,b,B,1.).real();
        }
    }

    cout << max(C) << endl;


    cout << A[0] << endl;
    cout << C[100] << endl;

    return 0;
}
