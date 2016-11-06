#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
using namespace std;

ifstream fin("cuart.in");
ofstream fout("cuart.out");

int a[1005],b[1005];
int dimA,dimB;
int n,tip,x,nr;
int nrA,nrB;
int mx,copie;
int primuA,primuB;

void read();

int isCuart(int numar,int mod)
{

    int  s=1;
    int  alCatelea=1;
    int  i=1;
    while(s<numar)
    {
        i++;
        alCatelea=1+(i-1)*4;
        s=(i*(1+alCatelea))/2;
    }
    if(mod==1)
    {
        return s;
    }
    if(s==numar)
    {
        return 1;
    }
    else
    {
        return 0;
    }


}


int main()
{

    read();

    int i,gasit1=0,gasit2=0;
    for(i=1; i<=dimA; i++)
    {
        if(isCuart(a[i],0)==1)
        {
            nrA++;
            if(gasit1==0)
            {
                primuA=a[i];
                gasit1=1;
            }
        }
    }
    for(i=1; i<=dimB; i++)
    {
        if(isCuart(b[i],0)==1)
        {
            nrB++;
            if(gasit2==0)
            {
                primuB=b[i];
                gasit2=1;
            }
        }
    }
    if(tip==1)
    {
        fout<<mx;
    }
    else if(tip==2)
    {

        if(nrA>nrB)
        {
            fout<<1;
        }
        else if(nrA==nrB)
        {
            fout<<0;
        }
        else
        {
            fout<<2;
        }
    }
    else
    {

        if(primuA>primuB)
        {
            fout<<primuA;
        }
        else if(primuA==primuB)
        {
            fout<<0;
        }
        else
        {
            fout<<primuB;
        }

    }

}













void read()
{

    int i;
    fin>>tip>>n;

    for(i=1; i<=n; i++)
    {
        fin>>x;
        nr=0;
        copie=x;
        while(x>0)
        {
            if(x%2==0)
            {
                x/=10;
            }
            else
            {
                nr=nr*10+x%10;
                x/=10;
            }
        }
        x=0;
        while(nr>0)
        {
            x=x*10+nr%10;
            nr/=10;
        }
        if(x!=0)
        {
            a[++dimA]=x;
        }
        else
        {
            mx=max(mx,copie);
        }
    }

    for(i=1; i<=n; i++)
    {
        fin>>x;
        copie=x;
        nr=0;
        while(x>0)
        {
            if(x%2!=0)
            {
                x/=10;
            }
            else
            {
                nr=nr*10+x%10;
                x/=10;
            }
        }
        x=0;
        while(nr>0)
        {

            x=x*10+nr%10;
            nr/=10;
        }
        if(x!=0)
        {
            b[++dimB]=x;
        }
        else
        {
            mx=max(mx,copie);
        }
    }




}
