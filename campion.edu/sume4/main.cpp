#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("sume4.in");
ofstream fout("sume4.out");


int main()
{
    int n,numar,i;
    int p1,p2,mij;
    int s1=0,s2=0;
    fin>>n;
    fin.get();
    for(i=1;i<=n;i++){
    fin>>numar;
        p1=numar/1000;
        p2=numar%100;
        mij=(numar%1000)/100;
        s1+=p1;
        s2+=p2;
        if(p1>p2){
            s2+=mij;
        }
        else if(p2>p1){
            s1+=mij;
        }
    }
    fout<<s1<<" "<<s2;
}
