#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>

using namespace std;

ifstream fin("printesa.in");
ofstream fout("printesa.out");

int isPrim(int n){

  int i,c=0;
  for(i=1;i<=n;i++){
    if(n%i==0){
        c++;
    }
  }
  if(c==2){
    return 1;
  }
  return 0;

}

int isInVector(int v[105], int n, int elem){

 for(int i=1;i<=n;i++){
    if(v[i]==elem){
            return 1;
    }
 }
 return 0;




}

void sortare(int v[105], int n){

 int i,j;
 for(i=1;i<n;i++){
    for(j=i+1;j<=n;j++){
        if(v[i]<v[j]){
            swap(v[i],v[j]);
        }
    }
 }





}



int main()
{
    int k,n,v[105],b[105],i;
    fin>>k>>n;
    if(k!=0){
    for( i=1;i<=n;i++){
        fin>>v[i];
    }
    int j,nr=2,q=0;
    j=1;
    while(j<=k){

       if(isPrim(nr)==1 && isInVector(v,n,nr)==0){
          b[++q]=nr;
          j++;
       }
       nr++;
    }

    sortare(b,q);
    for(i=1;i<=q;i++){
        fout<<b[i]<<" ";
    }
    }




}
