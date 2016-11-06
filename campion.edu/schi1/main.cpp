#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdio.h>
using namespace std;
FILE *fin, *fout;

typedef struct
{

    int nr;
    int poz;
    int val;
} vvv;

int n,m;
int v[100001];
vvv q[100001];

int cmp(vvv a, vvv b)
{
    if(a.nr<b.nr)
    {
        return 1;
    }
    return 0;
}

int cmp1(vvv a, vvv b)
{
    if(a.poz>b.poz)
    {
        return 1;
    }
    return 0;
}

int cautareBinara(int elem)
{
    int st,dr,m;
    st=1;
    dr=n;
    while(st<=dr)
    {
        m=(st+dr)/2;
        if(q[m].nr==elem)
        {
            return m;
        }
        else if(q[m].nr<elem)
        {
            st=m+1;
        }
        else
        {
            dr=m;
        }
    }
    return -1;
}

int main()
{

    fin=fopen("schi1.in","r");
    fout=fopen("schi1.out","w");
    //citiri
    fscanf(fin,"%d",&n);
    for(int i=1; i<=n; i++)
    {
        fscanf(fin,"%d",&v[i]);
    }
    fscanf(fin,"%d",&m);
    for(int i=1; i<=m; i++)
    {
        fscanf(fin,"%d ",&q[i].nr);
        q[i].poz=i;
    }
    sort(q+1,q+m+1,cmp);


    //sir crescator
    for(int i=1; i<=n; i++)
    {
        int j=i+1;
        while(v[i]>=v[j] && j<=n)
        {
            j++;
        }
        int pePoz=cautareBinara(v[i]);
        if(pePoz!=-1)
        {
            q[pePoz].val=j-i;
        }
        if(v[i]==q[m].nr){
            q[m].val=j-i;
        }
        i=--j;
    }

    sort(q+1,q+m+1,cmp1);
    //afisare
    for(int i=m; i>=1; i--)
    {
        fprintf(fout,"%d ",q[i].val);
    }























}
