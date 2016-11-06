#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
FILE *fin, *fout;

int n,k;
int v[2000005];
int laser;
int x1,x2,useless,val,maxy;
int main()
{

    fin=fopen("ozn.in","r");
    fout=fopen("ozn.out","w");

    int i;

    fscanf(fin,"%d",&n);
    fscanf(fin,"%d",&k);
    for(i=1; i<=n; i++)
    {
        fscanf(fin,"%d%d%d%d%d",&x1,&useless,&x2,&useless,&val);
        maxy=max(x2,maxy);
        v[x1]+=val;
        v[x2+1]+=val-(2*val);
    }

    for(i=1; i<=maxy; i++) v[i]+=v[i-1];

    for(i=1; i<=k; i++)
    {
        fscanf(fin,"%d",&laser);
        fprintf(fout,"%d\n",v[laser]);
    }



}
