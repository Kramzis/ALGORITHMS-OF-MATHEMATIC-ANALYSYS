#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

float warKrok(int m,float a,float b)
{
    float h = (b-a)/m;
    return h;

}
float funSin(float x)
{
    float w = sin(x)*sin(x)+2;
    return w;
}
float funE(float x)
{
    float w = exp(x)*2*pow(x,3);
    return w;

}

void wzTrapezowSin(int m,float a,float b)
{
    float wynik;
    float h = warKrok(m,a,b);
    wynik = 0.5*funSin(a);
    a=a+h;
    while (a<b)
    {
       wynik=wynik+funSin(a);
       a=a+h;
    }
    wynik=wynik+0.5*funSin(b);
    wynik = wynik*h;
    cout << "Calka dla fun sin^2(x)+2 jest rowna : "<<wynik<<endl;
}



void wzTrapezowE(int m,float a,float b)
{
    float wynik;
    float h = warKrok(m,a,b);
    wynik = 0.5*funE(a);
    a=a+h;
    while (a<b)
    {
       wynik=wynik+funE(a);
       a=a+h;
    }
    wynik=wynik+0.5*funE(b);
    wynik = wynik*h;
    cout << "Calka dla fun e^x*2*x^3 jest rowna : "<<wynik<<endl;


}
void wzSimpsonaE(int m,float a,float b)
{
    float wynik;
    float h = warKrok(m,a,b);
    wynik = funE(a);
    a=a+h;
    int i=0;
    while (a<b)
    {
        if (i%2==0)
       wynik=wynik+4*funE(a);
       else wynik=wynik+2*funE(a);

       a=a+h;
       i++;
    }
    wynik=wynik+funE(b);

    wynik = wynik*h/3;
    cout << "Calka dla fun e^x*2*x^3 jest rowna : "<<wynik<<endl;

}

void wzSimpsonaSin(int m,float a,float b)
{
    float wynik;
    float h = warKrok(m,a,b);
    wynik = funSin(a);
    a=a+h;
    int i=0;
    while (a<b)
    {
        if (i%2==0)
       wynik=wynik+4*funSin(a);
       else wynik=wynik+2*funSin(a);

       a=a+h;
       i++;
    }
    wynik=wynik+funSin(b);

    wynik = wynik*h/3;
    cout << "Calka dla fun sin^2(x)+2 jest rowna : "<<wynik<<endl;

}


int main()
{
    int wyborF;
    int wyborS;
    int m;

    while (true)
    {
        cout << "Ktora funkcja ma byc calkowana? 1-sin 2-e : ";
        cin >> wyborF;if (wyborF==3) exit(0);
        cout << "Ktora metoda? 1-wzTrapezow 2-wzSimpsona : ";
        cin >> wyborS;
        cout << "Podaj liczbe przedzialow : ";
        cin >> m;
        switch (wyborF)
        {
        case 1: switch (wyborS)
        {
        case 1: wzTrapezowSin(m,0,6.2839); break;
        case 2: wzSimpsonaSin(m,0,6.2839); break;
        };break;
        case 2: switch (wyborS)
        {
            case 1: if(m%2==0) wzTrapezowE(m,0,2);else cout<<"zle m"; break;
            case 2: if(m%2==0) wzSimpsonaE(m,0,2);else cout<<"zle m"; break;
        };break;
        }
        cout <<endl;
    }

    return 0;
}
