#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("matrice4.in");
ofstream fout("matrice4.out");

int n,m;

typedef struct
{

    int nr;
    int alCatelea;

}  vvv;

vvv a[2505];

int ciur[33000];


void ciurulLuiEratostene()
{

    int i,j;
    for(i=2; i<=33000; i++)
    {
        ciur[i]=1;
    }
    for(i=2; i<=33000; i++)
    {
        if(ciur[i]==1)
        {
            for(j=i+i; j<=33000; j=j+i)
            {
                ciur[j]=0;
            }
        }

    }

}


int main()
{
    int i,j,x,cate,cateMax=-99999,dimK=0,kk[2505];
    fin>>n>>m;

    ciurulLuiEratostene();

    for(i=1; i<=n*m; i++)
    {
        fin>>a[i].nr;
        cate=1;
        while(ciur[a[i].nr]!=1)
        {
            a[i].nr++;
            cate++;
        }
        a[i].alCatelea=cate;
        cateMax=max(cate,cateMax);
    }
    for(i=1;i<=n*m;i++){
        if(a[i].alCatelea==cateMax){
            kk[++dimK]=a[i].nr;
        }
    }
    sort(kk+1,kk+dimK+1);
    fout<<cateMax<<" "<<dimK<<endl;
    for(i=1;i<=dimK;i++){
        fout<<kk[i]<<" ";
    }







}







