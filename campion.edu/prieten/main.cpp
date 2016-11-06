#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
FILE *fin, *fout;
int main()
{

    fin=fopen("prieten.in","r");
    fout=fopen("prieten.out","w");

    int n,k,i;
    char c[255];
    long long s,rez;
    int v[255];
    fscanf(fin,"%d%d",&n,&k);
    fscanf(fin,"%lld",&s);


    n++;
    for(i=1; i<=k; i++)
    {
        rez=n*i;
        fprintf(fout,"%d ",rez);
    }
    fprintf(fout,"\n");

    i=1;
    rez=(i*(i-1)*(i+1))/2;
    if(n==)
    while(rez!=s)
    {

        rez=(i*(i-1)*(i+1))/2;
        i++;

    }
    i--;

    fprintf(fout,"%d",i);

}
