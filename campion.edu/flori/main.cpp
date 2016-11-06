#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
FILE *fin, *fout;

int a[152][152];
int VIZ[151];
int n,m,nrc;

void DFS(int nod)
{

    VIZ[nod]=nrc;
    fprintf(fout,"%d ",nod);
    for(int i=0; i<=100; i++)
    {
        if(a[i][nod]==1 && VIZ[i]==0)
        {
            DFS(i);
        }
    }
}
void RW()
{
    for(int k=0; k<=150; k++)
    {
        for(int i=0; i<=150; i++)
        {
            for(int j=0; j<=150; j++)
            {
                if(k!=i && i!=j && j!=k)
                {
                    if(a[i][k]==1 && a[k][j]==1)
                    {
                        a[i][j]==1;
                    }

                }
            }
        }
    }
}




int main()
{

    fin=fopen("text.txt","r");
    fout=fopen("flori.out","w");


    fscanf(fin,"%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            int x;
            fscanf(fin,"%d",&x);
            a[i][x]=1;
        }
    }

     for(int i=1; i<=n; i++)
     {
         for(int j=0; j<=10; j++)
         {
             cout<<a[i][j]<<" ";
         }
         cout<<endl;
     }
     cout<<endl;

     RW();
     for(int i=1; i<=n; i++)
     {
         for(int j=0; j<=10; j++)
         {
             cout<<a[i][j]<<" ";
         }
         cout<<endl;
     }
     cout<<endl;
    for(int i=1; i<=n; i++)
    {
        if(VIZ[i]==0)
        {
            nrc++;
            DFS(i);
            fprintf(fout,"\n");
        }

    }











}
