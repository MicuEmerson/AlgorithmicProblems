#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>
using namespace std;
ifstream fin("tan.in");
ofstream fout("tan.out");

char s[400];
int v[400],n,cMax=-999,poz,nrZ,cMin=999,pozMin,nrPare;
int b[400],dimB;
int c[400],dimC;
void eliminare(int poz)
{

    for(int i=poz; i<n; i++)
    {
        v[i]=v[i+1];
    }
    n--;
}

void nrZerouri()
{

    for(int i=1; i<=n; i++)
    {
        if(v[i]==0)
        {
            nrZ++;
        }
    }

}

void celMaiMicNrDifDe0()
{

    for(int i=1; i<=n; i++)
    {
        if(cMin>v[i] && v[i]!=0)
        {
            cMin=v[i];
            pozMin=i;
        }
    }

}


int main()
{
    int i;
    fin.get(s,400);
    n=strlen(s);
    for(i=0; i<strlen(s); i++)
    {
        v[i+1]=(int)s[i]-48;
    }
    nrZerouri();

    if(nrZ==0)
    {
        for(i=1; i<=n; i++)
        {
            if(v[i]>cMax && v[i]%2==0)
            {
                cMax=v[i];
                poz=i;
            }
        }
        eliminare(poz);
        sort(v+1,v+n+1);
        for(i=1; i<=n; i++)
        {
            fout<<v[i];
        }
        fout<<cMax;
    }

    else
    {
        celMaiMicNrDifDe0();
        c[++dimC]=cMin;
        eliminare(pozMin);
        for(i=1; i<=n; i++)
        {
            if(v[i]>cMax && v[i]%2==0)
            {
                cMax=v[i];
                poz=i;
            }
        }
        eliminare(poz);
        if(cMax==0)
        {

            nrZ--;
            for(i=1; i<=nrZ; i++)
            {
                c[++dimC]=0;
            }
            for(i=1; i<=n; i++)
            {
                if(v[i]!=0)
                {
                    b[++dimB]=v[i];
                }
            }
            sort(b+1,b+dimB+1);
            for(i=1; i<=dimB; i++)
            {
                c[++dimC]=b[i];
            }
            c[++dimC]=cMax;

            for(i=1; i<=dimC; i++)
            {
                fout<<c[i];
            }
        }
        else
        {

            for(i=1; i<=nrZ; i++)
            {
                c[++dimC]=0;
            }
            for(i=1; i<=n; i++)
            {
                if(v[i]!=0)
                {
                    b[++dimB]=v[i];
                }
            }
            sort(b+1,b+dimB+1);
            for(i=1; i<=dimB; i++)
            {
                c[++dimC]=b[i];
            }
            c[++dimC]=cMax;

            for(i=1; i<=dimC; i++)
            {
                fout<<c[i];
            }

        }

    }

}
