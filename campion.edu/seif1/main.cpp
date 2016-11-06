#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;

ifstream fin("seif1.in");
ofstream fout("seif1.out");

void afisare(int v[50000], int n)
{

    for(int i=1; i<=n; i++)
    {
        fout<<v[i]<<" ";
    }

}

int main()
{

    int n,k,i,j;
    int a[105][105];
    int v[50000],vect1[1005],vect2[50000];
    int dimV=0,dim2=0;
    fin>>n>>k;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            fin>>a[i][j];
        }
    }

//prima jumatate;
    i=1;
    j=n/2;
    while(j>=1)
    {
        v[++dimV]=a[i][j];
        j--;
        i++;
    }


// a doua
    j++;
    while(j<=n/2)
    {
        v[++dimV]=a[i][j];
        j++;
        i++;
    }


//a treia
    i--;
    while(j<=n)
    {
        v[++dimV]=a[i][j];
        i--;
        j++;
    }

// a patra
    j--;
    while(i>=1)
    {
        v[++dimV]=a[i][j];
        i--;
        j--;
    }


//prelucrare
    if(k==0)
    {
        afisare(v,dimV);
    }
    else
    {

        if(k>n*2)
        {
            k=k%(n*2);
        }
        for(i=1; i<=dimV; i++)
        {
            //primu vector
            while(i<=k)
            {
                vect1[i]=v[i];
                i++;
            }
            //al doilea vector
            vect2[++dim2]=v[i];

        }

        //concatenare
        for(i=1; i<=k; i++)
        {
            vect2[++dim2]=vect1[i];
        }
        afisare(vect2,dim2);
    }
    fin.close();
    fout.close();

}

















