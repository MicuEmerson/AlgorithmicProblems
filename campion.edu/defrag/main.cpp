#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
FILE *fin, *fout;

int a[102][724];
int s[102][724];
int f[102],cate;
int n,m,tip,c;


int main()
{
    fin=fopen("defrag.in","r");
    fout=fopen("defrag.out","w");
    int i,j,x,y;

    fscanf(fin,"%d%d%d%d",&tip,&n,&m,&c);
    for(i=1; i<=c; i++)
    {
        fscanf(fin,"%d%d",&x,&y);
        a[x][y]=1;
        a[x][y+m]=1;
        f[x]++;
    }
    for(i=1; i<=n; i++)
    {
        if(f[i]==0)
        {
            cate++;
        }
    }

    if(tip==1)
    {
        fprintf(fout,"%d",cate);
    }
    else
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=2*m; j++)
            {
                s[i][j]=s[i][j-1]+a[i][j];
            }
        }
        for(i=1; i<=n; i++)
        {
            int smax=-9999;
            for(j=f[i]+1; j<=2*m; j++)
            {
                smax=max(smax,s[i][j]-s[i][j-f[i]]);
            }
            int rez=f[i]-smax;
            fprintf(fout,"%d ",rez);
        }
    }



}
