#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;
FILE *fin, *fout;

//ifstream fin("text.txt");
//ofstream fout("politics.out");

typedef struct
{
    int x;
    int y;
} vct;
typedef struct
{
    int alCatele;
    int cati;
} vct2;

int n,m,dimV,vv[1005],dimVV,catePartide,suma;
vct perechi[50005];
vct2 v[1005];

int cmp(vct a, vct b)
{
    if(a.x<b.x)
    {
        return 1;
    }
    else if(a.x==b.x)
    {
        if(a.y<b.y)
        {
            return 1;
        }
    }
    return 0;
}
int cmp2(vct2 a, vct2 b)
{

    if(a.cati>b.cati)
    {
        return 1;
    }
    return 0;
}

int main()
{

    fin=fopen("politics.in","r");
    fout=fopen("politics.out","w");
    int i,j,nr;
    //fin>>n>>m;
    fscanf(fin,"%d",&n);
    fscanf(fin,"%d",&m);
    for(i=1; i<=m; i++)
    {
        //fin>>perechi[i].x;
       // fin>>perechi[i].y;
        fscanf(fin,"%d",&perechi[i].x);
        fscanf(fin,"%d",&perechi[i].y);
    }

    sort(perechi+1,perechi+m+1,cmp);

    for(i=1; i<=m; i++)
    {
        nr=1;
        j=i+1;
        while(perechi[i].x==perechi[j].x && j<=m)
        {
            j++;
            nr++;
        }

        dimV++;
        v[dimV].alCatele=perechi[i].x;
        v[dimV].cati=nr+1;
        i=--j;
    }

    sort(v+1,v+dimV+1,cmp2);

    for(i=1;i<=dimV;i++){
        catePartide++;
        suma+=v[i].cati;
        vv[++dimVV]=v[i].alCatele;
        if(suma>n/2){
            break;
        }
    }
    fprintf(fout,"%d\n",catePartide);

    //cout<<catePartide<<endl;
    sort(vv+1,vv+dimVV+1);
    for(i=1;i<=dimVV;i++){
            fprintf(fout,"%d ",vv[i]);
       // cout<<vv[i]<<" ";
    }

}
