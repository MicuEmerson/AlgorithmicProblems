#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("cifra1.in");
ofstream fout("cifra1.out");

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

   long m,n,s=0,i;
   int nrC,nrC2;
   int v[100];
   fin>>n>>m;

   nrC=nrCifre(n);
   nrC2=nrCifre(n);
   while(n>0){
    v[nrC]=n%10;
    nrC--;
    n/=10;
   }

   for(i=1;i<=nrC2;i++){
      s+=v[i];
     if(m<=s){
        fout<<v[i];
        break;
     }
   }



}
