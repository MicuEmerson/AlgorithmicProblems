#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("tort.in");
ofstream fout("tort.out");

int cmmdc(int a, int b){

 while(a!=b){
    if(a>b){
        a-=b;
    }
    else{
        b-=a;
    }
 }
 return a;
}


int main()
{
    int n,m,l,nrMin;
    fin>>m>>n;
    l=cmmdc(m,n);
    nrMin=(m/l)*(n/l);
    fout<<nrMin<<" "<<l;
}
