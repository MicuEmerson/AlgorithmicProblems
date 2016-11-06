#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;

ifstream fin("degrade.in");
ofstream fout("degrade.out");

int pozIntensitate(char intensitate[100], char x)
{

    int i;
    for(i=0; i<strlen(intensitate); i++)
    {
        if(intensitate[i]==x)
        {
            return i;
        }
    }
}



int main()
{
    char intensitate[100],x;
    int v[100001],i,j,k,nrSeg,nrSegMax=-99999,contor=0,dimV=0;

    fin.get(intensitate,100);
    fin.get();

    while(!fin.eof())
    {

        fin>>x;
        dimV++;
        v[dimV]=pozIntensitate(intensitate,x);
    }

    v[dimV]=-1;
    dimV--;

    for(i=1; i<dimV; i++)
    {
        j=i;
        nrSeg=1;
        while(v[j]<=v[j+1] && j<=dimV)
        {
            nrSeg++;
            j++;
        }
        if(nrSeg>nrSegMax)
        {
            nrSegMax=nrSeg;
        }
    }



    for(i=1; i<dimV; i++)
    {
        j=i;
        nrSeg=1;
        while(v[j]<=v[j+1] && j<=dimV)
        {
            nrSeg++;
            j++;
        }

        if(nrSeg==nrSegMax)
        {
            contor++;
        }
    }
    fout<<nrSegMax<<" "<<contor;
}
