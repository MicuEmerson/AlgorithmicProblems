#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
FILE *fin, *fout;
const int MAXN = 1000005;
int E[MAXN];

void eratostene()
{
    int i,j;
    for(i=2; i<=MAXN; i++)
    {
        E[i]=1;
    }
    for(i=2; i<=MAXN; i++)
    {
        if(E[i]==1)
        {
            for(j=i+i; j<=MAXN; j=j+i)
            {
                E[j]=0;

            }
        }
    }

}


int main()
{
    fin=fopen("bileprime.in","r");
    fout=fopen("bileprime.out","w");

    int i,n,a,b,x;
    fscanf(fin,"%d%d%d",&n,&a,&b);
    eratostene();

    for(i=1; i<=n; i++)
    {
        fscanf(fin,"%d",&x);
        if(x<MAXN)
        {
            if(E[x]==1)
            {
                if(x<=a)
                {
                    a-=x;
                    b+=x;
                }
            }
            else
            {
                if(x<=b)
                {
                    b-=x;
                    a+=x;
                }
            }
        }
    }
    fprintf(fout,"%d",a);


}
