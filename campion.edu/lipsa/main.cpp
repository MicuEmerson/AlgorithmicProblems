#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
FILE *fin, *fout;
int dim,n;
long long rez;
int main()
{
    fin=fopen("lipsa.in","r");
    fout=fopen("lipsa.out","w");
    int i,x,contor=1;
    fscanf(fin,"%d",&n);
    rez=n;
    for(i=1;i<n;i++){
         fscanf(fin,"%d",&x);
         rez-=x;
         rez+=contor;
         contor++;
    }
   fprintf(fout,"%lld",rez);

}
