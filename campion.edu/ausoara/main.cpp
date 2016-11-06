#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
FILE *fin, *fout;
int f[1000005],n,m,ap[1000005];
int elem[100005], dim;
int v[1010];

int main()
{
    fin=fopen("text.txt","r");
    fout=fopen("text1.txt","w");

    fscanf(fin,"%d",&n);
    for(int i=1; i<=n; i++)
    {
        fscanf(fin,"%d",&m);
        for(int j=1; j<=m; j++)
        {
            fscanf(fin,"%d",&v[j]);

        }
        if(i==1)
        {
            for(int j=1; j<=m; j++)
            {
                int cate=1;
                int k=j+1;
                ap[v[j]]++;
                while(v[j]==v[k])
                {
                    cate++;
                    k++;
                }
                f[v[j]]=cate;
                j=k-1;
            }
        }
        else
        {
            for(int j=1; j<=m; j++)
            {
                int cate=1;
                int k=j+1;
                ap[v[j]]++;
                while(v[j]==v[k])
                {
                    cate++;
                    k++;
                }
                f[v[j]]=min(f[v[j]],cate);
                j=k-1;
            }

        }

    }

    for(int i=1; i<=1000000; i++)
    {
        if(ap[i]==n)
        {
            int cate=f[i];
            while(cate!=0)
            {
                elem[++dim]=i;
                cate--;
            }
        }
    }
    fprintf(fout,"%d ",dim);
    for(int i=1; i<=dim; i++)
    {
        fprintf(fout,"%d ",elem[i]);
    }

}
