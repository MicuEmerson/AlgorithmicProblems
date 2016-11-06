#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("siruri1.in");
ofstream fout("siruri1.out");


void creareVectorY( int n){

 int y[100],x[100];
 int i,j;
 for(i=1;i<=n;i++){
    fin>>x[i];
    y[i]=1;
 }
 for(i=1;i<n;i++){
    for(j=i+1;j<=n;j++){
        if(x[i]>x[j]){
            y[i]++;
        }
        else{
            y[j]++;
        }
    }
    fout<<y[i]<<" ";
 }
 fout<<y[n];


}


int main()
{
  int n;

  fin>>n;
  fin.get();
  creareVectorY(n);

}
