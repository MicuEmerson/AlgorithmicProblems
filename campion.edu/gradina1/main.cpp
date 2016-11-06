#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
FILE *fin, *fout;

int n,p,k;
int a[1005][1005];
int s[1005][1005];
int f[1000005];

int sumaMatrice()
{

    int i,j;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        }
    }
}

void numarGradini()
{
    int i,j,rez,rezMax=-99999;
    for(i=k; i<=n; i++)
    {

        for(j=k; j<=n; j++)
        {
            rez=0;
            rez=s[i][j]- s[i-k][j] - s[i][j-k] + s[i-k][j-k];
            f[rez]++;

            if(rez>rezMax)
            {
                rezMax=rez;
            }
        }
    }

    fprintf(fout,"%d\n",rezMax);
    fprintf(fout,"%d",f[rezMax]);



}



int main()
{

    fin=fopen("gradina1.in","r");
    fout=fopen("gradina1.out","w");

    fscanf(fin,"%d%d%d",&n,&p,&k);

    int i,x,y;
    for(i=1; i<=p; i++)
    {
        fscanf(fin,"%d%d",&x,&y);
        a[x][y]=1;
    }
    sumaMatrice();
    numarGradini();



}
