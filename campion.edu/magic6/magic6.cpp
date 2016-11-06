#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;

ifstream fin("magic6.in");
ofstream fout("magic6.out");

void eliminarePoz(int v[1000], int &n, int poz)
{

    for(int i=poz; i<n; i++)
    {
        v[i]=v[i+1];
    }
    n--;


}

int isInVector(int v[1000] , int n, int elem)
{

    for(int i=1; i<=n; i++)
    {
        if(v[i]==elem)
        {
            return 1;
        }
    }
    return 0;

}

int main()
{
    int n,i,v[1000],m=0,l=0,nrMin=999999,nr=0,poz;
    fin>>n;
    char x,c[1000];
    for(i=1; i<=n; i++)
    {
        fin>>x;
        if(isalpha(x))
        {
            l++;
            c[l]=x;
        }
        if(isdigit(x))
        {
            if(isInVector(v,m,(int)x-48)==0)
            {
                m++;
                v[m]=(int)x - 48;
                if(v[m]<nrMin && v[m]!=0)
                {
                    nrMin=v[m];
                    poz=m;
                }
            }
        }
    }

    nr=nr*10+nrMin;
    eliminarePoz(v,m,poz);
    sort(v+1,v+m+1);
    for(i=1; i<=l; i++)
    {
        c[i]=toupper(c[i]);
        fout<<c[i];
    }

    fout<<endl;
    for(i=1; i<=m; i++)
    {
        nr=nr*10+v[i];
    }

    fout<<nr;
}




