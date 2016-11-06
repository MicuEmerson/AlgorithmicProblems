#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

FILE *fin, *fout;
int n,v[10005],c;

int main()
{

    fin=fopen("panglica.in","r");
    fout=fopen("panglica.out","w");


    int i,j,mn=9999999,x,y,st,dr;
    fscanf(fin,"%d",&n);
    fscanf(fin,"%d",&c);

    for(i=1; i<=n; i++)
    {
       fscanf(fin,"%d",&v[i]);
    }

    for(i=1; i<n; i++)
    {
        j=n;
        while(v[i]!=v[j] && j>i)
        {
            j--;
        }
        x=i-1;
        y=n-j;
        if(mn>x+y)
        {
            mn=x+y;
            st=x;
            dr=y;
        }
    }
    n-=mn;
    fprintf(fout,"%d \n",n);
    fprintf(fout,"%d \n",v[1+st]);
    fprintf(fout,"%d \n",st);
    fprintf(fout,"%d \n",dr);


}
