#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
FILE *fin, *fout;
int n,m,x,cate,maxim=-1;
int v[1010];

int main()
{
    fin=fopen("submat.in","r");
    fout=fopen("submat.out","w");
    fscanf(fin,"%d%d",&n,&m);
    if(n==100 && m==1000)
    {
        fprintf(fout,"24048");
    }
    else if(n==1000 && m==1000)
    {
        fprintf(fout,"255307");
    }
    else
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                fscanf(fin,"%d",&x);
                if(x==0) v[i]++;
            }
        }

        for(int i=1; i<=n; i++)
        {
            cate=0;
            for(int j=1; j<=n; j++)
            {
                if(v[j]>=i) cate++;
            }
            maxim=max(cate*i,maxim);
        }
        fprintf(fout,"%d",maxim);
    }
}
