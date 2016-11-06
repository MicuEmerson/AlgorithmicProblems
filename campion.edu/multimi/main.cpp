#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("multimi.in");
ofstream fout("multimi.out");


int main()
{
    int n,mx,mn,x,i;
    mx=-30002;
    mn=30002;
    fin>>n;
    fin.get();
    for(i=1;i<=n;i++){
        fin>>x;
        if(mx<x){
            mx=x;
        }
        fin>>x;
        if(mn>x){
           mn=x;
        }
        fin.get();
    }
    if(mx>mn){
        fout<<"multimea vida";
    }
    else{
    for(i=mx;i<=mn;i++){
        fout<<i<<" ";
    }
    }
}
