#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
using namespace std;
ifstream fin("nr3.in");
ofstream fout("nr3.out");
int c,v[1005],n,i,poz,copie[1005],dimC;
char s[1010];

void inserare(int poz)
{
    n++;
    for(int i=n; i>poz; i--)
    {
        v[i]=v[i-1];
    }
    v[poz]=c;
}


void inserare2(int poz)
{
    dimC++;
    for(int i=dimC; i>poz; i--)
    {
        copie[i]=copie[i-1];
    }
    copie[poz]=c;
}

int main()
{
    fin.get(s,1010);
    i=0;
    while(!isspace(s[i]))
    {
        v[++n]=(int)s[i]-48;
        copie[n]=v[n];
        i++;
    }
    dimC=n;
    c=(int)s[++i]-48;

    if(v[1]==0)
    {
        fout<<"0";
    }
    else
    {
        for(i=1; i<=n; i++)
        {
            if(v[i]<c)
            {
                poz=i;
                break;
            }
        }
        if(poz==0)
        {
            poz=n+1;
        }
        inserare(poz);

        for(i=1; i<=n; i++)
        {
            fout<<v[i];
        }
        fout<<endl;
    }

    if(c==0)
    {
        poz=2;
    }
    else
    {
        poz=0;
        for(i=1; i<=n; i++)
        {
            if(copie[i]>c)
            {
                poz=i;
                break;
            }
        }

        if(poz==0)
        {
            poz=dimC+1;
        }
    }
    inserare2(poz);

    if(copie[1]==0 && copie[2]==0)
    {
        fout<<"0";
    }
    else
    {
        for(i=1; i<=dimC; i++)
        {
            fout<<copie[i];
        }
    }























}
