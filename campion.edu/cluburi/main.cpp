#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("cluburi.in");
ofstream fout("cluburi.out");

int main()
{

    int n,v[100],dimV=0,nrActual=1,i;
    fin>>n;

    while(n>0){

        if(n%2==0){
            n/=2;
            nrActual*=2;
        }
        else{
            dimV++;
            v[dimV]=nrActual;
            nrActual*=2;
            n/=2;
        }
    }
    fout<<dimV<<endl;
    for(i=1;i<=dimV;i++){
        fout<<v[i]<<" ";
    }

}
