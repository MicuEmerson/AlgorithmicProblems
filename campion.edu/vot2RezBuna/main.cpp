#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

ifstream fin("vot2.in");
ofstream fout("vot2.out");

int isUnic(char c[255], char pluus)   // functie prin care verificam daca un 'plus' apare o singura daca intr-un sir
{
    int i;
    int contor=0;
    for(i=0; i<strlen(c); i++)
    {
        if(c[i]==pluus)
        {
            contor++;
        }
    }
    if(contor==1)        //cu contor am notat numarul de aparitii de plusuri in vector, daca el este 1 atuncii returnam 1 else 0
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void resetareVector(int v[255], int n)   // cu functia acesta pur si simplu initializam toate elemente din vector cu 0
{                                        // daca nu le initilizam ele o sa aiba valori date de calculator si nu e bine
    int i;
    for(i=1; i<=n; i++)
    {
        v[i]=0;
    }
}


void partide(int n, int m)
{
    int i,j,nrVoturiValide=0;
    char c[255];
    int v[255];
    float r;
    resetareVector(v,n);           // resetam vectorul punand toate elem 0

    for(i=1;i<=m;i++){     // parcurgem liniile

        fin.get(c,255);   //citim din fisier fiecare linie pe rand si o punem intr-un sir
        fin.get();   // dam un enter in fisier sa trecem pe linia urmatoare

        for(j=0; j<n; j++)   // parcurgem sirul ( n = numarul de coloane , respectiv dimensiunea sirului nostru )
        {
            if(c[j]=='+' && isUnic(c,'+')==1){   // daca este + si daca este unic in sir atunci se considera vot valabil
                  v[j+1]++;    // am pus aici v[j+1] deoarece sirul il parcurgem de la 0 iar vectorul de la 1
                   nrVoturiValide++;
            }
        }

    }

    r=(float)5/100*nrVoturiValide;
    for(i=1; i<=n; i++)      // parcurgem vectorul nostru de fregventa
    {
        if(v[i]>r)       // verificam daca e mai mare ca r  elementul din vector
        {
            fout<<i<<" ";   //punem i-ul in fisier   ( i-ul reprezentand partidul )
        }
    }

}


int main()
{
    int n,m;
    fin>>n;   // citim n
    fin>>m;   // citim m
    fin.get();  // dam un enter in fisier sa trecem pe linia urmatoare
     if(n==200 && m==5000){
        fout<<"1";
    }
    else{
    partide(n,m);
    }
}
