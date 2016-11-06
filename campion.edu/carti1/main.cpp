#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
FILE *fin, *fout;

typedef struct
{

    int nr;
    int poz;

} vvv;

int n;
vvv v[100002];

int cmp(vvv a, vvv b)
{

    if(a.nr<b.nr)
    {
        return 1;
    }
    return 0;

}

int main()
{

    fin=fopen("carti1.in","r");
    fout=fopen("carti1.out","w");

    int i,cate=0,actual;
    fscanf(fin,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fin,"%d",&v[i].nr);
        v[i].poz=i;
    }
    sort(v+1,v+n+1,cmp);


    actual=v[1].poz;

    for(i=2; i<=n; i++)
    {
        while(actual<v[i].poz && i<=n)
        {
            actual=v[i].poz;
            i++;
        }
        if(actual>v[i].poz && i<=n)
        {
            cate++;
        }
        actual=v[i].poz;
    }
   fprintf(fout,"%d ",cate);














}
