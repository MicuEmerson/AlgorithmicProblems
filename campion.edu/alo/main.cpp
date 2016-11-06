#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("alo.in");
ofstream fout("alo.out");



int primaCifra(int n){

 while(n>9){
    n=n/10;
 }
 return n;
}


int main()
{

    int e,n,numar,d;
    fin>>e>>n;
    fin.get();

    for(int i=1;i<=n;i++){

        fin>>numar>>d;
        fin.get();
        if(numar%10==5){
            if(primaCifra(numar)==1){
                e=e-(d*2);
            }
            else{
                e=e+d;
            }
        }
    }
    fout<<e;


}
