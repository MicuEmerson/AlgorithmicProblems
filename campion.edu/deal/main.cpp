#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
using namespace std;
FILE *fin, *fout;
int n,v[100001],s;
int main()
{

    fin=fopen("deal.in","r");
    fout=fopen("deal.out","w");

    fscanf(fin,"%d",&n);
    for(int i=1;i<=n;i++){
        fscanf(fin,"%d",&v[i]);
    }
    sort(v+1,v+n+1);
    int jum=n/2;
    for(int i=1;i<=jum;i++){
        if(v[i]<v[n]){
            s+=v[n];
        }
        n--;
    }
    fprintf(fout,"%d",s);
}
