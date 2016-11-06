#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>

using namespace std;

ifstream fin("text.txt");
ofstream fout("paritate.out");

int cautareBinara(int v[200000],int st, int dr, int elem){

  int gasit=0,i,j,m;
  while(st<=dr && gasit==0){
      m=(st+dr)/2;
      if(v[m]==elem){
        gasit=1;
        return m;
      }
      else{
        if(v[m]<elem){
            st=m+1;
            m=(st+dr)/2;
        }
        else{
            dr=m-1;
            m=(dr+st)/2;
        }
      }
  }
  if(gasit==0){
    return -1;
  }

}

void afisare(int v[200000], int n){

 for(int i=1;i<=n;i++){
    cout<<v[i]<<" ";
 }
 cout<<endl;


}



void update(int v[200000], int n, int poz ,int val){

     while(poz<=n){
        v[poz]+=val;
        poz=poz+(poz&(-poz));
     }

}

int  interogare(int v[200000], int k){

    int rez=0;
    while(k>0){
        rez+=v[k];
        k=k-(k&(-k));
    }
    return rez;

}







int main()
{
    int n,m,v[200000],copie[200000],i,j,nrInversiuni=0;
    fin>>n;

    for(i=1;i<=n;i++){
        fin>>m;
        for(j=1;j<=m;j++){
            fin>>v[j];
            copie[j]=v[j];
        }
        sort(copie+1,copie+m+1);

        for(j=1;j<=m;j++){
              v[j]=cautareBinara(copie,1,m,v[j]);
         }
         for(j=1;j<=m;j++){
            copie[j]=0;
         }


         for(j=m;j>=1;j--){

            //interogare
            nrInversiuni+=interogare(copie,v[j]);


            //update
            update(copie,m,v[j],1);


         }

    }
   fout<<nrInversiuni;

}









