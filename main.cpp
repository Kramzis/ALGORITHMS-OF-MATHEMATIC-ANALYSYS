#include <iostream>
#include "stdlib.h"

using namespace std;

void show(float x[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << x[i] << "";
    }
    cout << endl;
}

void calculating(float x[], float fx[], float l[], int n)
{
    float n1 = n+1;
    float wsa1 = 0;
    float wsa0;
    float wsa21 = 0;
    float y1 = 0 ;
    float y2 = 0;

    for(int i = 0; i <= n; i++)
    {
        wsa1 += x[i];
        wsa21 += x[i]*x[i];
        y1 += fx[i];
        y2 += fx[i]*x[i];
    }
    l[0] = n1;
    l[1] = wsa1;
    l[2] = wsa1;
    l[3] = wsa21;
    l[4] = y1;
    l[5] = y2;
}

void resolving(float l[], int mode)
{
    float w, wa0, wa1;
    w = l[0]*l[3]-l[2]*l[1];
    wa0 = l[4]*l[3]-l[2]*l[5];
    wa1 = l[0]*l[5]-l[4]*l[1];
    float a0 = wa0/w;
    float a1 = wa1/w;
    switch (mode){
        case 1: cout << "wzor funkcji liniowej : y = "<<a0<<" + "<<a1<<"x"<<endl;break;
        case 2: cout << "wzor funkcji liniowej : y = "<<a0<<" + "<<"1/x*"<<a1<<endl;break;
    };
}

void aryInverse(float x[], int n)
{
    for(int i = 0; i <= n; i++)
    {
        x[i] = 1/x[i];
    }
    show(x, n + 1);
}

void linearFunction(float x[], float fx[], float l[], int n)
{
    calculating(x, fx, l, n);
    resolving(l, 1);
}

void rationalFunction(float x[], float fx[], int n)
{
    aryInverse(x,n);
    float l[n+1];
    calculating(x,fx,l,n);
    resolving(l,2);
}

int main()
{
    float x[] = {1, 3, 4, 6, 8};
    float x1[] = {1,0.33333333,0.2,0.16666666,0.1428571428};
    float x2[] = {1, 2, 3, 5, 7};
    float fx[] = {-4, -8, -10, -14, -18};
    float fx1[] = {4, 8, 12, 14, 16};
    float fx2[] = {1, 1.10, 1.79, 2.48, 2.89};
    int n = 4;
    float l[n];

    linearFunction(x, fx, l, n);
    rationalFunction(x1, fx1, n);

    return 0;
}
