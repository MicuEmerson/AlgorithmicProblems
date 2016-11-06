#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
ifstream fin("pepsi.in");
ofstream fout("pepsi.out");
typedef struct
{

    int elemT;
    int elem;
    int suma;
    int ok;
} vct;

vct v[105];
int n,m,k,pozitii[1000];
char c[1000];

void afisare();

int nrMin()
{
    int mn=999999;
    int poz;
    for(int i=1; i<=m; i++)
    {
        if(v[i].ok==0)
        {

            if(v[i].elem<mn)
            {
                mn=v[i].elem;
                poz=i;
            }

        }
    }
    v[poz].suma++;
    if(v[poz].suma==v[poz].elemT)
    {
        v[poz].ok=1;
    }
    return poz;
}

int nrMax()
{
    int mx=-999999;
    int poz;
    for(int i=1; i<=m; i++)
    {
        if(v[i].ok==0)
        {

            if(v[i].elem>mx)
            {
                mx=v[i].elem;
                poz=i;
            }

        }
    }
    v[poz].suma++;
    if(v[poz].suma==v[poz].elemT)
    {
        v[poz].ok=1;
    }
    return poz;
}



int main()
{
    int i;
    fin>>n>>m>>k;
    fin.get();
    fin.get(c,1000);
    fin.get();
    for(i=1; i<=m; i++)
    {
        fin>>v[i].elem;
        v[i].elemT=k;
        v[i].suma+=v[i].elem;
        if(v[i].suma==v[i].elemT)
        {
            v[i].ok=1;
        }
    }

    for(i=0; i<strlen(c); i++)
    {
        if(c[i]=='E')
        {
            pozitii[i+1]=nrMin();
        }
        else
        {
            pozitii[i+1]=nrMax();
        }

    }
    for(i=1; i<=strlen(c); i++)
    {
          fout<<pozitii[i]<<" ";
    }


}
