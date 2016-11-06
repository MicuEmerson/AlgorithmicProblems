#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

ifstream fin("codcorect.in");
ofstream fout("codcorect.out");


int nrCifre(long n){

  int nr=0;
  while(n>0){
    nr++;
    n=n/10;
  }
 return nr;


}

int primaCifra(long n){


  while(n>9){
   n/=10;
  }
 return n;


}



long pal(long n){

 long nrNou=0;
 while(n>0){
    nrNou=nrNou*10+n%10;
    n/=10;
 }
 return nrNou;
}



/*
long schimbare(long n){

  int pCifra=primaCifra(n);
  int uCfira=n%10;
  n=n/10;
  n=pal(n);
  n=n/10;
  n=pal(n);
  n=n*10+pCifra;
  n=pal(n);
  n=n*10+uCfira;
  n=pal(n);
  return n;
}
*/

int schimbare2(long n){

 int v[100];
 int i=0,aux;
 long cn=n,numar=0;

 while(cn>0){
    i++;
    v[i]=cn%10;
    cn=cn/10;
 }

 aux=v[1];
 v[1]=v[i];
 v[i]=aux;
 for(i=nrCifre(n);i>=1;i--){
    numar=numar*10+v[i];
 }
 return numar;



}


int main()
{
    int n;
    long nr;
    fin>>n;
    fin.get();
    for(int i=1;i<=n;i++){
        fin>>nr;
        if(nrCifre(nr)%2!=0){

           if(primaCifra(nr)>=nr%10){
              fout<<nr<<" ";
           }
           else{

            fout<<schimbare2(nr)<<" ";
           }
        }
        else{
            fout<<nr<<" ";
        }

    }



}
