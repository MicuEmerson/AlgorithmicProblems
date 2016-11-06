#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("vraji.in");
ofstream fout("vraji.out");

int cmmdc(int a, int b){

 while(a!=b){
    if(a>b){
        a=a-b;
    }
    else{
        b=b-a;
    }
 }
 return a;
}

int cmmdcVector(int v[100], int n){

  int i;
  int x=cmmdc(v[1],v[2]);
  for(int i=3;i<=n;i++){
    x=cmmdc(x,v[i]);
  }
  return x;



}



int main()
{
    int n,x,y,nrMax=-999,v[100];
    fin>>n;
    fin.get();
    int i;
    for(i=1;i<=n;i++){
        fin>>x>>y;
        fin.get();
        if(nrMax<x*y){
            nrMax=x*y;
        }
        v[i]=x*y;
    }
    fout<<nrMax<<endl;
    if(n==1){
        fout<<nrMax;
    }
    else{
    fout<<cmmdcVector(v,n);
    }
}
