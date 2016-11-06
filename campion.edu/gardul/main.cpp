#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("gardul.in");
ofstream fout("gardul.out");


int cmmmc(int a, int b){
 int ca=a,cb=b;
 while(a!=b){
    if(a>b){
            a=a-b;
    }
    else{
        b=b-a;
    }
 }
 return (ca*cb)/a;



}



int main()
{

    long n,p,q;
    int rosu=0,albastru=0,violet=0,nevopsite;
    fin>>n;
    fin.get();
    fin>>p>>q;
    nevopsite=n;

    violet=n/cmmmc(p,q);

    rosu=n/p-violet;

    albastru=n/q-violet;

    nevopsite=n-albastru-violet-rosu;

    fout<<nevopsite<<endl;
    fout<<rosu<<endl;
    fout<<albastru<<endl;
    fout<<violet;





}
