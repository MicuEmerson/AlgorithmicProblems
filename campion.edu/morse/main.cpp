#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;

ifstream fin("morse.in");
ofstream fout("morse.out");


int nrMax1Binar(int nr){

 int x,contor=0;
 while(nr>0){
    if(nr%2==1){
        contor++;
    }
    nr=nr/2;
 }

 return contor;

}

void transfBinara(int nr){


 int aux,i,k,v[100],n=0;

 while(nr>0){
        n++;
    v[n]=nr%2;
    nr=nr/2;
 }
 k=n;
 for(i=1;i<=n/2;i++){
    aux=v[i];
    v[i]=v[k];
    v[k]=aux;
    k--;
 }
 for(i=1;i<=n;i++){
    if(v[i]==1){
        fout<<'-';
    }
    else{
        fout<<'.';
    }
 }

}


int main()
{

    int a,b,nrMax=-99999,i;
    fin>>a>>b;
    for(i=a;i<=b;i++){
        if(nrMax1Binar(i)>nrMax){
            nrMax=nrMax1Binar(i);
        }
    }

    for(i=a;i<=b;i++){
        if(nrMax1Binar(i)==nrMax){
            transfBinara(i);
            fout<<" ";
        }
    }

}
