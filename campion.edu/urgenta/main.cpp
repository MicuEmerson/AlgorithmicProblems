#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
FILE *fin, *fout;

typedef struct
{

    int x,y,c,ok;


} vvv;

int n,m,k,suma,dim;
vvv v[32389];
int poz[280];
pair < int , int > p[280];

int cmp(vvv a, vvv b)
{

    if(a.c<b.c)
    {
        return 1;
    }
    return 0;

}

int main()
{

    fin=fopen("urgenta.in","r");
    fout=fopen("urgenta.out","w");
    int i,toate;
    fscanf(fin,"%d",&n);
    fscanf(fin,"%d",&m);
    fscanf(fin,"%d",&k);
    k--;

    for(i=1; i<=m; i++)
    {
        fscanf(fin,"%d",&v[i].x);
        fscanf(fin,"%d",&v[i].y);
        fscanf(fin,"%d",&v[i].c);

    }

    sort(v+1,v+m+1,cmp);



    toate=1;
    poz[1]=1;


    while(toate<n)
    {

        i=1;
        while(1)
        {
            if(poz[v[i].x]==1 && poz[v[i].y]==0)
            {
                break;
            }
            if(poz[v[i].x]==0 && poz[v[i].y]==1)
            {
                break;
            }
            i++;
            if(i>n)
            {
                break;
            }

        }

        poz[v[i].x]=1;
        poz[v[i].y]=1;
        v[i].ok=1;
        toate++;
    }

    for(i=n-1; i>=n-k; i--)
    {
        v[i].ok=0;
    }
    for(i=n-k; i<=m; i++)
    {
        suma+=v[i].c;
    }
    int rez=m+1-(n-k);

    fprintf(fout,"%d\n",suma);
    fprintf(fout,"%d\n",rez);
    for(i=n-k; i<=m; i++)
    {
        fprintf(fout,"%d %d\n",v[i].x,v[i].y);
    }




}
