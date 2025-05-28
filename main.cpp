#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
using namespace std;

int main() {
  
    srand(time(0));

    int n, i, j, t, g, c, x, indice, inizio, fine, medio;
    bool scambi(true);

    do {
        cout<<"Quanti numeri generare?"<<endl;
        cin>>n;
    } while (n<=0);

    vector<int>v(n);
    for (i=0; i<n; i++) {
        v[i]= rand() % 11;
    }

    i=0;
    while (i<n && scambi==true) {
        scambi=false;
        j=0;

        while (j<(n-1)-i) {
            if (v[j]>v[j+1]) {

                t=v[j];
                v[j]=v[j+1];
                v[j+1]=t;

                scambi=true;
            }
            j=j+1;
        }
        i=i+1;
    }

    cout<<"Qual'è il numero da cercare?"<<endl;
    cin>>x;
    
    indice=-1;
    i=0;
    c=0;
    while (i<n and indice==-1) {
        c=c+1;

        if (v[i]==x) {
            indice=i;
        }

        i=i+1;
    }
    cout<<" "<<endl;
    cout<<"Metodo sequenziale:";
    if (indice==-1) {
        cout<<"Il valore è nella posizione "<<indice;
        cout<<"; ";
        cout<<"Sono state compiute "<<c<<" operazioni";
    }
    else
    {
        cout<<"Nel vettore, il valore "<<x<<" non è presente";
        cout<<"; ";
        cout<<"Sono state compiute "<<c<<" operazioni";
    }

    indice=-1;
    inizio=0;
    fine=n-1;
    g=0;
    while (inizio<=fine and indice==-1) {
        
        g=g+1;
        medio=inizio+((fine-inizio))/2;

        if (v[medio]==x) {
            indice=medio;
        }
        else
        {
            if (v[medio]>x) {
                fine=medio-1;
            }
            else
            {
                inizio=medio+1;
            }
        }
    }

    cout<<" ";
    cout<<"Ricerca binaria: ";
    if (indice==-1) {
        cout<<"Il valore è nella posizione "<<indice;
        cout<<"; ";
        cout<<"Sono state compiute "<<g<<" operazioni";
    }
    else
    {
        cout<<"Nel vettore, il valore "<<x<<" non è presente";
        cout<<"; ";
        cout<<"Sono state compiute "<<g<<" operazioni";
    }
}

//LEGGERE LE ISTRUZIONI NEL FILE README.md
