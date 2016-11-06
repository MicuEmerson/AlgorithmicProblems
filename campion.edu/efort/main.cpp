#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

ifstream fin("efort.in");
ofstream fout("efort.out");

int n,k,x,v[1005],copieK;
int F[45];

void fibb()
{

    F[-1]=1;
    F[0]=1;
    for (int i=1; i<=44; i++)
    {
        F[i]=F[i-1]+F[i-2];
    }

}

int sumaFib(int n){

  int s=0;
  for(int i=1;i<=n;i++){
    s+=F[i];
  }
  return s;


}


int main()
{
    int i,j,s=0;
    fin>>n>>k;
    copieK=k;
    fibb();
    for(i=1; i<=n; i++)
    {
        fin>>v[i];
    }

    for(i=1;i<=n;i++){

        if(k>v[i]){
            k-=v[i];
            s+=v[i];
        }
        else{

           s+=k;
           k=v[i]-k;
           s+=sumaFib(k);
           k=copieK;
        }
    }
    fout<<s;

}
