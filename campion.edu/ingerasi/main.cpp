#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("ingerasi.in");
ofstream fout("ingerasi.out");

long cmmdc(long a, long b){

 long r=a%b;


 while(r!=0){
   a=b;
   b=r;
   r=a%b;
 }
 return b;
}

long cmmdcSir(long v[100], int n){

 int i;
 long x;
 x=cmmdc(v[1],v[2]);
 for(i=3;i<=n;i++){
    x=cmmdc(x,v[i]);
 }
 return x;
}

int main()
{
    int n;
    long v[100];
    fin>>n;
    for(int i=1;i<=n;i++){
        fin>>v[i];
    }
    if(n==1){
        fout<<v[1];
    }
    else{
        fout<<cmmdcSir(v,n);
    }
}
