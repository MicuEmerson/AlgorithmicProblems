#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("bancomat.in");
ofstream fout("bancomat.out");

int main()
{

   int i=1,n;
   long suma,tranzactie;
   fin>>suma>>n;
   fin.get();
   while(i<=n){
    i++;
    fin>>tranzactie;
    fin.get();
    if(tranzactie%10==2){
        tranzactie/=10;
        suma+=tranzactie;
    }
    else{
        tranzactie/=10;
        if(suma>=tranzactie){
            suma-=tranzactie;
        }
    }
   }
   fout<<suma;

}
