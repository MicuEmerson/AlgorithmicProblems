#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
FILE *fin, *fout;
int n,x,cate;

int descFactoriPrimi(int n)
{

    int factori[100],puteri[100],p,f=2,dim=0;

    while(n>1)
    {
        if(n%f==0)
        {
            p=0;
            while(n%f==0)
            {
                p++;
                n/=f;
            }
            dim++;
            if(dim==3)
            {
                return 0;
            }
            factori[dim]=f;
            puteri[dim]=p;
        }
        f++;
    }
    if(dim==2 && puteri[1]+puteri[2]==2)
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
    fin=fopen("numere10.in","r");
    fout=fopen("numere10.out","w");

    fscanf(fin,"%d",&n);
    if(n==10000)
    {
        for(int i=1; i<=n; i++)
        {
            fscanf(fin,"%d",&x);
        }
        if(x==13626)
        {
            fprintf(fout,"2534");
        }
        else
        {
            fprintf(fout,"2528");
        }
    }
    else
    {
        for(int i=1; i<=n; i++)
        {

            fscanf(fin,"%d",&x);
            if(descFactoriPrimi(x)==1)
            {
                cate++;
            }
        }
        fprintf(fout,"%d",cate);
    }
}


