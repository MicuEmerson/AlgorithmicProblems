#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("alun.in");
ofstream fout("alun.out");

int n1,n2,x,k,y,i;
int nrAlune,mancate;
int main()
{
    fin>>n1>>n2>>x>>k>>y;
    mancate=x/k;
    x/=2;

    if(x%2==0){
            x/=2;
        nrAlune+=n1*x;
        nrAlune+=n2*x;
    }
    else{
        x/=2;
        nrAlune+=n1*x +n1;
        nrAlune+=n2*x;
    }

    nrAlune-=mancate;
    fout<<nrAlune<<endl;
   i=0;
   int nrDrum=0;
   while(y>0){

      if(i%2==0){
        y-=n1;

      }
      else{
        y-=n2;

      }
      nrDrum+=2;
      i++;

   }
   fout<<nrDrum;


}
