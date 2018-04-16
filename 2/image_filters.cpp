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

Complex gaussian_filter(double mu, double nu, double pixel_kernel)
{
    return exp(-0.5*pow(pixel_kernel,2)*(pow(mu,2)+pow(nu,2)))/(2.*Pi);
}

double pass_filter(string mode,double umbra,Complex val)
{
    if(mode=="low")
    {
        if(norm(val)<umbra)
        {
            return 1.;
        }
        else
        {
            return  0.;
        }
    }
    if(mode=="high")
    {
        if(norm(val)>umbra)
        {
            return 1.;
        }
        else
        {
            return  0.;
        }
    }
    else
    {
        return 0.;
    }
}

int main(int argc, char *argv[])
{
    string filename=argv[1];
    double px=atof(argv[3])/60;

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

    // Calcular la transformada con el filtro.

    Complex B[rows*col];

    string met=argv[2];
    double coeff=atof(argv[3]);


    if(met=="gaussian")
    {
        for(int a=0; a<rows;a++)
        {
            for(int b=0;b<col;b++)
            {
                B[a*col+b]=FT(a,b,A)*gaussian_filter(a,b,px);
            }
        }
    }
    else if(met=="lowpass")
    {
        for(int a=0; a<rows;a++)
        {
            for(int b=0;b<col;b++)
            {
                Complex alpha=FT(a,b,A);
                B[a*col+b]=alpha*pass_filter("low",coeff,alpha);
            }
        }
    }
    else if(met=="highpass")
    {
        for(int a=0; a<rows;a++)
        {
            for(int b=0;b<col;b++)
            {
                Complex alpha=FT(a,b,A);
                B[a*col+b]=alpha*pass_filter("high",coeff,alpha);
            }
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

    double maxC=max(C);

    if(maxC>0.)
    {
        for(int a=0; a<rows;a++)
        {
            for(int b=0;b<col;b++)
            {
                C[a*col+b]=C[a*col+b]/maxC;
            }
        }
    }

    ofstream result(argv[4]);

    //result << n << " " << p << "\n";

    for(int mu=0;mu<rows;mu++)
    {
        for(int nu=0;nu<col;nu++)
        {
            result << C[mu*col+nu] << " ";
        }
        result << "\n";
    }
    return 0;



    return 0;
}
