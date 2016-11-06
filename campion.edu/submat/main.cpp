#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdio.h>
using namespace std;
FILE *fin, *fout;

const int MAXN=550;
int n,m;
int s[MAXN][MAXN];
int aux[MAXN];
int maxim=-1;


int main()
{
    fin=fopen("submat.in","r");
    fout=fopen("submat.out","w");

    fscanf(fin,"%d%d",&n,&m);

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            fscanf(fin,"%d",&aux[j]);
        }
        for(int j=m; j>=1; j--)
        {
            if(aux[j]==0)
                s[i][j]=s[i][j+1]+1;
        }
    }


    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            aux[j]=s[j][i];
        }

        sort(aux + 1, aux + n + 1);

        int p = 1;

        for (int l = 1; l <= m - i + 1; ++l)
        {
            while (aux[p] < l && p <= n) ++p;
            int curSize = n - p + 1;
            if (curSize * l > maxim)
                maxim = curSize * l;
        }
    }
    fprintf(fout,"%d",maxim);









}
