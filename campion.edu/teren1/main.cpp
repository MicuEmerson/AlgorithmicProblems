#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

FILE *fin,*fout;


int n,m,t,r,c,q;
int a[185][185];

int verificare(int x11, int y11, int x22, int y22, int dim)
{
    if(x11+dim-1>n || y22+dim-1>m){
        return 0;
    }
    for(int i=x11; i<x11+dim; i++)
    {
        if(a[i][y11]!=0)
        {
            return 0;
        }
    }
    for(int j=y22; j<y22+dim; j++)
    {
        if(a[x22][j]!=0)
        {
            return 0;
        }
    }
    return 1;

}

int nrMaxPatrare()
{
    int i,j,s=0,nr,nrMax=-9999,i1,j1,i2,j2,gasit;
    for(i=1; i<n; i++)
    {
        for(j=1; j<m; j++)
        {

            if(a[i][j]==0)
            {
                i1=i;
                j1=j+1;
                i2=i+1;
                j2=j;
                nr=2;

                while(verificare(i1,j1,i2,j2,nr)==1)
                {
                    j1++;
                    i2++;
                    nr++;
                }
            }
            nr--;
            nrMax=max(nr,nrMax);


        }
    }
   return nrMax*nrMax;

}


int main()
{
    fin=fopen("teren1.in","r");
    fout=fopen("teren1.out","w");
    int i,j,k,numar,mx=-999;
    int x1,y1,x2,y2;
    fscanf(fin,"%d",&numar);
    fscanf(fin,"%d",&n);
    fscanf(fin,"%d",&m);
    fscanf(fin,"%d",&t);
    fscanf(fin,"%d",&r);
    fscanf(fin,"%d",&c);

    for(i=1; i<=t; i++)
    {

        fscanf(fin,"%d",&x1);
        fscanf(fin,"%d",&y1);
        fscanf(fin,"%d",&x2);
        fscanf(fin,"%d",&y2);
        for(j=x1; j<=x2; j++)
        {
            for(k=y1; k<=y2; k++)
            {
                a[j][k]++;
                if(a[j][k]>mx)
                {
                    mx=a[j][k];
                }
            }
        }
    }

    if(numar==1)
    {
        fprintf(fout,"%d",a[r][c]);

    }
    else if(numar==2)
    {
        fprintf(fout,"%d",mx);

    }
    else
    {
         q=nrMaxPatrare();
        fprintf(fout,"%d",q);
    }

}
