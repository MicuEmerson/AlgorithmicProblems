#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
using namespace std;
FILE *fin, *fout;

int n,h,s;
int v[250001],dim,cate;
int k[501];

int main()
{

    fin=fopen("palma.in","r");
    fout=fopen("palma.out","w");

    fscanf(fin,"%d%d%d",&n,&h,&s);

    for(int i=1;i<=n;i++){
        fscanf(fin,"%d",&k[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=h;j++){
            int x;
            fscanf(fin,"%d",&x);
            if(x<k[i]){
                v[++dim]=x;
            }
        }
    }
    sort(v+1,v+dim+1);

    for(int i=1;i<=dim;i++){
        if(s-v[i]>=0){
            s-=v[i];
            cate++;
        }
        else{
            break;
        }
    }
    fprintf(fout,"%d",cate);
}
