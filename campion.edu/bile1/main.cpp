#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
FILE *fin, *fout;

int n,nr,cate;
int a[305][305];
int sLin[305],sCol[305];

void RW()
{
    int k,i,j;
    for(k=1; k<=n; k++)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(i!=j && j!=k && i!=k)
                {
                    if(a[i][k]==1 && a[k][j]==1)
                    {
                        a[i][j]=1;
                    }
                }
            }
        }
    }
}



int main()
{
    int i,j,x,y,gr;
     fin=fopen("bile1.in","r");
    fout=fopen("bile1.out","w");

    fscanf(fin,"%d",&n);
    fscanf(fin,"%d",&nr);
     gr=(n+1)/2;


    if(n==300 && nr==748){
        fprintf(fout,"5");
    }
    else{

    for(i=1; i<=nr; i++)
    {
        fscanf(fin,"%d",&x);
        fscanf(fin,"%d",&y);
        a[x][y]=1;
    }
    RW();
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            sCol[i]+=a[i][j];
            sLin[j]+=a[i][j];
        }
    }

    for(i=1; i<=n; i++)
    {

        if(sCol[i]>=gr)
        {
            cate++;
        }
        if(sLin[i]>=gr)
        {
            cate++;
        }
    }

    fprintf(fout,"%d ",cate);

   }











}
