#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("concurs3.in");
ofstream fout("concurs3.out");


int cifraZecilor(int n){

  n=n%100;
  n=n/10;
  return n;

}
int cifraSutelor(int n){

  while(n>9){
    n=n/10;
  }
  return n;

}



int main()
{
    int nr,n;
    int v[100], i, gasit=0;
    fin>>nr>>n;
    int nrOras=0,nrScoala=0;
    int elevOras, elevScoala;
    elevOras=cifraSutelor(nr);
    elevScoala=cifraZecilor(nr);
    for(i=1;i<=n;i++){

        fin>>v[i];
        if(v[i]==nr){
            gasit=1;
        }
        if(v[i]!=nr){
        if(cifraSutelor(v[i])==elevOras){
            nrOras++;
            if(cifraZecilor(v[i])==elevScoala){
                nrScoala++;
            }
        }
        }
    }
    if(gasit==1){
        nrOras++;
        nrScoala++;
        fout<<"DA"<<endl;
        fout<<nrOras<<endl;
        fout<<nrScoala;
    }
    else{
        fout<<"NU"<<endl;
        fout<<nrOras<<endl;
        fout<<nrScoala;
    }





}
