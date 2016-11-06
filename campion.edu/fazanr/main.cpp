#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("fazanr.in");
ofstream fout("fazanr.out");

int primaCifra(int n){

 while(n>9){
    n/=10;
 }
 return n;

}


int main()
{
    int n,x,y,i,contor=0;
    int v[100];
    fin>>n;
    for(i=1;i<=n;i++){
        fin>>v[i];
    }
    for(i=1;i<n;i++){
        if(v[i]%10 != primaCifra(v[i+1])){
            contor++;
        }

    }
    fout<<contor;






}
