#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
FILE *fin, *fout;

int n,v[500002],contor;

int main()
{
    fin=fopen("predecesor.in","r");
    fout=fopen("predecesor.out","w");

    int i,j;
    fscanf(fin,"%d",&n);
    for(i=1;i<=n;i++){
        fscanf(fin,"%d",&v[i]);
    }
    i=1;
    for(i=1;i<=n;i++){

        j=i+1;
        while(v[i]<=v[j] && j<=n && i<n){
            i++;
            j++;
        }
        contor++;

    }

    fprintf(fout,"%d",contor);
}
