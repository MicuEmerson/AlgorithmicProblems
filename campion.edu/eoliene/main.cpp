#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;

ifstream fin("text.txt");
ofstream fout("eoliene.out");

typedef struct
{

    int x;
    int y;

} segment;

void sortare(segment v[1000], int n)
{

    int i,j;
    segment aux;
    for(i=1; i<n; i++)
    {
        for(j=i+1; j<=n; j++)
        {
            if(v[i].y>v[j].y)
            {
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
        }
    }
}

void afisare(segment v[1000], int n)
{

    int i;
    for(i=1; i<=n; i++)
    {
        cout<<v[i].x<<" "<<v[i].y<<endl;
    }
    cout<<endl;
}


void numarMinimEliminari(segment v[1000], int n)
{

    int i=1,j=1,nrEliminari=0;

    while(i<n)
    {
        j=i+1;
        while(v[i].y > v[j].x && j<=n)
        {
            nrEliminari++;
            j++;
        }

        i=j;

    }
    cout<<nrEliminari;

}


int main()
{
    int d[1000],l[1000];
    segment v[1000];
    int n,i;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>d[i];
    }
    for(i=1; i<=n; i++)
    {
        fin>>l[i];
    }
    for(i=1; i<=n; i++)
    {
        v[i].x=d[i]-l[i];
        v[i].y=d[i]+l[i];
    }
    afisare(v,n);
    sortare(v,n);
    cout<<endl;
    afisare(v,n);
    numarMinimEliminari(v,n);



}







