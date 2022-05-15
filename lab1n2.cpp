#include <iostream>
#include <stack>

using namespace std;
void wyswietl(int a[],int n)
{
    for (int i=0;i<n;i++)
    {
        cout << a[i]<<" ";
    }
    cout <<endl;
}
void zamiana(int liczba, int podstawa){
        stack <int> wynik;
        while(liczba > 0){
          wynik.push(liczba % podstawa);
          liczba /= podstawa;
        };
        while(!wynik.empty()){
            cout << wynik.top();
            wynik.pop();
        };
        cout << endl;
};

int horner(int tab[], int n, int punkt){
    int wynik = tab[0];
    int i = 1;
    while(i <= n){
      wynik = wynik*punkt + tab[i];
      i++;
    };
    return wynik;

};

int silnia(int n)
{
    int i = 1, w = 1;
    while (i <= n){
        w = w*i;
        i++;
    }
    return w;
}
int horner2(int tab[], int n, int punkt){
    int wynik = tab[0];
    int i = 1;
    while(i <= n + 1){
    wynik = wynik*punkt + tab[i];
    tab[i] = wynik;
    i++;
    };
    return wynik;

};

void pochodne(int tab[], int n, int punkt){
   int i = 1;
   int st;
   while(i <= n){
    st = horner2(tab, n - i, punkt);
    i++;
   };
   wyswietl(tab,n+1);
   for(int i = 0; i <= n;  i++){
    cout << "Wynik pochodnej("<< n - i <<") = " << tab[i] * silnia(n - i) << endl;
   };

};

/*/int horner2(int tab[], int n, int p){
    int i = 1, wynik;
    wynik = tab[0];

};/*/



int main()
{
    //zamiana(127, 2);

    int wielomian[] = {2, 0, 3, -5, 2};
    int pkt = -1;
    //cout << horner(wielomian, 4, pkt);
    int n=4,p=2;
    int a[]={-3,0,1,-2,4};
    pochodne(a, n, p);
    return 0;
}
