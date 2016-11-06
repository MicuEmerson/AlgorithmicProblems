#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string.h>
#include <math.h>
using namespace std;

ifstream fin("centrale.in");
ofstream fout("centrale.out");

int isOk(long v[100], long x){

  x=x/10;
  int i=0,j;
  while(x>9){
        i++;
    v[i]=x%10;
    x/=10;
  }
  for(j=2;j<=i;j++){
    if(v[1]!=v[j]){
        return 0;
    }
  }
  return 1;

}




int main()
{
    int n,contor=0,i;
    long x;
    long v[100];
    fin>>n;
    for(i=1;i<=n;i++){
        fin>>x;
        if(isOk(v,x)==1){
            contor++;
        }

        }

    fout<<contor;

}
