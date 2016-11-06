#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
ifstream fin("ocr.in");
ofstream fout("ocr.out");

int n,m;
float a[100][100];

float linieMax(int lin){

  int i,j;
  float s1=0.0,s2=0.0;
  if(lin==1){
    for(j=1;j<=m;j++){
        s1+=a[lin][j];
    }
  }
  else{
  for(i=1;i<lin;i++){
    for(j=1;j<=m;j++){
        s1+=a[i][j];
    }
  }
  }

  if(lin==n){
    for(j=1;j<=m;j++){
        s2+=a[lin][j];
    }
  }
  else{

    for(i=lin+1;i<=n;i++){
        for(j=1;j<=m;j++){
            s2+=a[i][j];
        }
    }
  }
  return abs(s1-s2);
}

float coloanaMax(int col){

   int i,j;
   float s1=0.0,s2=0.0;
   if(col==1){
    for(i=1;i<=n;i++){
        s1+=a[i][col];
    }
   }
   else{
    for(i=1;i<=n;i++){
        for(j=1;j<col;j++){
            s1+=a[i][j];
        }
    }
   }

   if(col==m){
      for(i=1;i<=n;i++){
        s2+=a[i][col];
      }
   }
   else{
    for(i=1;i<=n;i++){
        for(j=col+1;j<=m;j++){
            s2+=a[i][j];
        }
    }
   }
   return abs(s1-s2);


}





int main()
{
    int i,j,pozI,pozJ;
    float linMin=999999.0,colMin=999999.0,lin,col;
    fin>>n>>m;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            fin>>a[i][j];
        }
    }
    for(i=1;i<=n;i++){
        lin=linieMax(i);
        if(lin<=linMin){
            linMin=lin;
            pozI=i;
        }
    }

    for(j=1;j<=m;j++){
        col=coloanaMax(j);
        if(col<=colMin){
            colMin=col;
            pozJ=j;
        }
    }
    fout<<pozI<<" "<<pozJ;


}





















