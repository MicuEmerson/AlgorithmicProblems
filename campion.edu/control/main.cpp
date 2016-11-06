#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;

ifstream fin("control.in");
ofstream fout("control.out");

void reset(int f[201]){

 for(int i=0;i<=200;i++){
    f[i]=0;
 }

}

int isPrim(int n){

 int c=0;
 for(int i=1;i<=n;i++){
    if(n%i==0){
        c++;
    }
 }
 if(c==2){
    return 1;
 }
 return 0;

}

int main()
{
    int n,i;
    int v[100],f[201],a[100],dimA=0,b[100],dimB=0,nr1=0,nr0=0,nr=0;
    reset(f);
    fin>>n;
    for(i=1;i<=n;i++){
        fin>>v[i];
        f[v[i]]++;
    }
    sort(v+1,v+n+1);
    for(i=0;i<=200;i++){
        if(f[i]>0){
            dimA++;
            a[dimA]=f[i];
        }
    }
    dimA=dimA-(dimA%3);
    for(i=1;i<=dimA;i=i+3){
        if(a[i]%2==0 && a[i+1]%2==0 && a[i+2]%2==0){
            dimB++;
            b[dimB]=1;
        }
        else if(a[i]%2!=0 && a[i+1]%2!=0 && a[i+2]%2!=0){
            dimB++;
            b[dimB]=1;
        }
        else{
            dimB++;
            b[dimB]=0;
        }
    }
    for(i=1;i<=dimB;i++){
        if(b[i]==1){
            nr1++;
        }
        else{
            nr0++;
        }
    }
    nr=nr1;
    nr=nr*10+nr0;
    fout<<nr<<endl;
    if(isPrim(nr)==1){
        fout<<"1";
    }
    else{
        fout<<"0";
    }
}





