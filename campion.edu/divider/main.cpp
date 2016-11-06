#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;
ifstream fin("divider.in");
ofstream fout("divider.out");
int a,b,n;
int v[100000],dim=0;

int laPutere(int n, int p){

  int prod=1;
  for(int i=1;i<=p;i++){
    prod*=n;
  }
  return prod;
}

int main()
{
    int i,j;

    fin>>a>>b>>n;
    if(a==b){
            fout<<1<<" ";
        for(i=1;i<=n*2;i++){
            fout<<laPutere(a,i)<<" ";
        }
    }
    else{

        for(i=0;i<=n;i++){
            for(j=0;j<=n;j++){
                v[++dim]=laPutere(a,i)*laPutere(b,j);
            }
        }
       sort(v+1,v+dim+1);
    for(i=1;i<=dim;i++){
        fout<<v[i]<<" ";
    }
    }

}
