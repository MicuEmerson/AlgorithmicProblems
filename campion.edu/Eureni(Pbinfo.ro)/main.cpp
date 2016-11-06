#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
using namespace std;
ifstream fin("eureni.in");
ofstream fout("eureni.out");
int e;
long long laPutere(int n)
{
    long long nr=1;
    for(int i=1; i<=n; i++)
    {
        nr*=e;

    }
    return nr;
}


int main()
{
    int n,i,poz,nr,nrGlobal=0;
    long long S,bacnote[10];
    fin>>S>>n>>e;
    bacnote[1]=1;
    for(i=2; i<=n+1; i++)
    {
       bacnote[i]=laPutere(i-1);
    }
    i=1;
    while(S>=bacnote[i]){
        i++;
    }
    i--;
    while(S>0){
        nr=0;
        while(S>=bacnote[i]){
            S-=bacnote[i];
            nr++;
            nrGlobal++;
        }
        fout<<bacnote[i]<<" "<<nr<<endl;
        i--;
    }
    fout<<nrGlobal;
}
