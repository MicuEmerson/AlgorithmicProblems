#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
using namespace std;

ifstream fin("anagramabil.in");
ofstream fout("anagramabil.out");

void resetare(int f[10]){

  for(int i=0;i<=9;i++){
    f[i]=0;
  }
}

int isOk(int f1[10], int f2[10]){

 for(int i=0;i<=9;i++){
    if(f1[i]!=f2[i]){
        return 0;
    }
 }
 return 1;
}





int main()
{
    long long n,cn,cn2;


    int f1[10],f2[10],v[10],dimV=0,i;
    resetare(f1);
    fin>>n;
      cn=n;
    while(n>0){
        f1[n%10]++;
        n/=10;
    }
    for(i=2;i<=9;i++){
        cn2=cn*i;

       resetare(f2);
        while(cn2>0){
            f2[cn2%10]++;
            cn2/=10;
        }
        if(isOk(f1,f2)==1){
           v[++dimV]=i;
        }

    }
    if(dimV==0){
        fout<<"NU";
    }
    else{
        fout<<"DA"<<endl;
        for(i=1;i<=dimV;i++){
            fout<<v[i];
        }
    }



}
