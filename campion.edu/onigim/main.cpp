#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin ("onigim.in");
ofstream fout("onigim.out");

typedef struct{

 int v1;
 int poz;
 int v2;

} str;


int f[1005],mn=9999999,mx,nrAcelasiPct;
int n,k,i,j=1;
int vk[1005];
str v[1005];

void sortare(str v[1005], int n){

  int i,j;
  for(i=1;i<n;i++){
    for(j=i+1;j<=n;j++){
        if(v[i].v1>v[j].v1){
            swap(v[i].v1,v[j].v1);
            swap(v[i].poz,v[j].poz);
        }
    }
  }
}

void sortare2(str v[1005], int n){

  int i,j;
  for(i=1;i<n;i++){
    for(j=i+1;j<=n;j++){
        if(v[i].poz>v[j].poz){
            swap(v[i].poz,v[j].poz);
            swap(v[i].v2,v[j].v2);
        }
    }
  }
}

int main()
{

    //citiri
    fin>>n>>k;
    for(i=1;i<=k;i++){
        fin>>vk[i];
    }

    for(i=1;i<=n;i++){
        fin>>v[i].v1;
        v[i].poz=i;
        f[v[i].v1]++;
        mn=min(mn,v[i].v1);
        mx=max(mx,v[i].v1);
    }

    sortare(v,n);

    v[1].v2=vk[1];
    for(i=2;i<=n;i++){
        if(v[i-1].v1==v[i].v1){
            v[i].v2=vk[j];
        }
        else{
            v[i].v2=vk[++j];
        }
    }
    sortare2(v,n);

    for(i=1;i<=n;i++){
        fout<<v[i].v2<<" ";
    }

    for(i=mn;i<=mx;i++){
        nrAcelasiPct=max(nrAcelasiPct,f[i]);

    }

    int cate=0;
    int contor=1;
    for(i=mx;i>=mn && contor<=3;i--){
        if(f[i]>0 && contor <=3){
            cate+=f[i];
            contor++;
        }
    }
    fout<<endl<<cate<<endl<<nrAcelasiPct;



}







