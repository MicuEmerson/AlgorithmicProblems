#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;

ifstream fin("cifru4.in");
ofstream fout("cifru4.out");

int nrCifre(long n){
 int nr=0;
 while(n>0){
    nr++;
    n/=10;
 }
 return nr;

}

int main()
{
    long n,cn,nrC,x=0,y=0,k;
    int v[100];
    int dimV=0,i,j;
    fin>>n;
    if(n<=9){
        if(n==1){
            fout<<"1";
        }
        else{
            fout<<"0";
        }
    }
    else{

    nrC=nrCifre(n);
    cn=n;
    while(n>0){
            dimV++;
           v[dimV]=n;
        if(n%nrC==0){
            x++;
        }
        n/=10;
    }

    for(i=1;i<dimV;i++){
        for(j=i+1;j<=dimV;j++){
            if((v[i]-v[j])%nrC==0 && v[i]%nrC!=0 && v[j]%nrC!=0){
               y++;
            }
        }
    }


    k=x+y;
    fout<<k;
    }





}
