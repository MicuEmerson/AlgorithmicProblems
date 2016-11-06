#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

FILE *fin, *fout;

typedef struct
{
    int elem;
    long long partial;
    int poz;

} vvv;

vvv v[100005];
int n,poz1,poz2,i;
long long s=9999999999;

int cmp(vvv a, vvv b)
{
    if(a.partial<b.partial)
        return 1;
    return 0;
}

int main()
{
    fin=fopen("suma3.in","r");
    fout=fopen("suma3.out","w");

    fscanf(fin,"%i",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fin,"%i",&v[i].elem);
        v[i].partial=v[i-1].partial+v[i].elem;
        v[i].poz=i;
    }

    sort(v,v+1+n,cmp);

    for(i=0; i<n; i++)
    {
        if(abs(v[i].partial-v[i+1].partial)<s)
        {
            s=abs(v[i].partial-v[i+1].partial);
            poz1=v[i].poz;
            poz2=v[i+1].poz;
        }
    }

    if(poz1>poz2)
    {
        fprintf(fout,"%lld %d %d",s,poz2+1,poz1);

    }
    else
    {
        fprintf(fout,"%lld %d %d",s,poz1+1,poz2);
    }
}
























