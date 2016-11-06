#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
using namespace std;
ifstream fin("album.in");
ofstream fout("album.out");

int n,i,j,poz0V,poz0F,cateEgale=0,cate;
int v[100000];
int f[100000];

int main()
{
    fin>>n;

    for(i=1; i<=n; i++)
    {
        fin>>v[i];
        if(v[i]==0)
        {
            poz0V=i;
        }
    }

    for(i=1; i<=n; i++)
    {
        fin>>f[i];
        if(f[i]==v[i] && f[i]!=0){

            cateEgale++;
        }
        if(f[i]==0)
        {
            poz0F=i;
        }
    }


    if(poz0F==poz0V){
        cate=n-1-cateEgale;
        cate++;
    }
    else{
        cate=n-1-cateEgale;
    }
    fout<<cate;



}
