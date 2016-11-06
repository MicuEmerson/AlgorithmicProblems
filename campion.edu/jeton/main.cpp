#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("jeton.in");
ofstream fout("jeton.out");
/*
int isInVector(int v[28000], int n, int elem)
{

    int i;
    for(i=1; i<=n; i++)
    {
        if(v[i]==elem)
        {
            return 1;
        }
    }
    return 0;
}

int stergij(int a[], int &n, int x,int y)//sterge din a elementele cu indicii intre x si y
{
    for(int i=1;i<=y-x+1;i++)
        for(int j=x;j<n;j++)
            a[j]=a[j+1];
    n=n-(y-x+1);
}

void elimiarePoz(int v[2800], int &n, int poz){

  int i;
  for(i=poz;i<n;i++){
    v[i]=v[i+1];
  }
  n--;


}

void eliminareSegventa(int v[28000], int &n, int st, int dr)
{

    int i,j,x;
    x=dr-st+1;
    while(x>0){
        elimiarePoz(v,n,st);
        x--;
    }

}

int pozElem(int v[28000], int n, int elem){

 int i;
 for(i=1;i<=n;i++){
    if(v[i]==elem){
        return i;
    }
 }
}


int main()
{
    int n,m,mnA,mnB,mxA,mxB,dimAux=0,i,sA=0,sB=0;
    int a[28000],b[28000],aux[28000];
    fin>>n>>m;
    for(i=1; i<=n; i++)
    {
        fin>>a[i];

    }

    for(i=1; i<=m; i++)
    {
        fin>>b[i];
     ;
    }

    sort(a+1,a+n+1);
    sort(b+1,b+m+1);

    for(i=1; i<=n; i++)
    {
        if(isInVector(b,m,a[i])==1)
        {
            dimAux++;
            aux[dimAux]=a[i];
        }
    }

    sort(aux+1,aux+dimAux+1);


    fout<<aux[1]<<" "<<aux[dimAux]<<" ";
    mnA=pozElem(a,n,aux[1]);
    mnB=pozElem(b,m,aux[1]);
    mxA=pozElem(a,n,aux[dimAux]);
    mxB=pozElem(b,m,aux[dimAux]);
    stergij(a,n,mnA,mxA);
    stergij(b,m,mnB,mxB);
    if(n>m){
        fout<<"1";
    }
    else if(n==m){
        fout<<"0";
    }
    else{
        fout<<"2";
    }
}
*/

int main(){

 int n,m,i,x,pozMin,pozMax,s1=0,s2=0;
 int v[50000];
 int nrMax=-99999;
 fin>>n>>m;
 for(i=1;i<=n;i++){
    fin>>x;
    if(nrMax<x){
        nrMax=x;
    }
    v[x]=v[x]+1;
 }
 for(i=1;i<=m;i++){
    fin>>x;
     if(nrMax<x){
        nrMax=x;
    }
    v[x]=v[x]+2;
 }
 i=1;
 while(i){
    if(v[i]==3){
        fout<<i<<" ";
        pozMin=i;
        break;
    }
    i++;
 }
 i=nrMax;
 while(i){
    if(v[i]==3){
        fout<<i<<" ";
        pozMax=i;
        break;
    }
    i--;
 }
 for(i=1;i<=pozMin;i++){
    if(v[i]==1){
        s1++;
    }
    else if(v[i]==2){
        s2++;
    }
 }
 for(i=nrMax;i>=pozMax;i--){
    if(v[i]==1){
        s1++;
    }
    else if(v[i]==2){
        s2++;
    }
 }
 if(s1>s2){
    fout<<"1";
 }
 else if(s1==s2){
    fout<<"0";
 }
 else{
    fout<<"2";
 }


}






















