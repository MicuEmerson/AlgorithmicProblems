#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("pagini.in");
ofstream fout("pagini.out");
int tip,nr,cate=1,s;

int nrCifre(int n){

 int nr=0;
 while(n>0){
    nr++;
    n/=10;
 }
 if(nr==0)return 1;
 else return nr;

}

int main()
{
    fin>>tip>>nr;
    if(tip==1){
        for(int i=1;i<=nr;i++){
            s+=nrCifre(i);
        }
        fout<<s;
    }
    else{

        while(s!=nr){
            s+=nrCifre(cate);
            cate++;
        }
        fout<<--cate;
    }

}
