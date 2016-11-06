#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
using namespace std;

ifstream fin("cabina.in");
ofstream fout("cabina.out");



int main()
{
    int n,a,b,i,statie,oameni,nrOameni=0,x,y,l=0, v[100],j=0,speciale=0;
    fin>>n;
    fin>>statie>>oameni;
    j++;
    v[j]=statie;
    nrOameni+=oameni;

    for(i=1;i<n;i++){
        fin>>x;
        fin>>y;
        j++;
        v[j]=x;
        nrOameni+=y;
        if(statie>x){
            l+=abs(statie-x)*1;
        }
        else{
            l+=abs(statie-x)*3;
        }
        statie=x;
    }
    for(i=2;i<n;i++){

        if(v[i-1]<v[i] && v[i+1]<v[i] || v[i-1]>v[i] && v[i+1]>v[i] ){
            speciale++;

        }
    }
    fout<<nrOameni<<endl;
    fout<<l<<endl;
    fout<<speciale;


}
