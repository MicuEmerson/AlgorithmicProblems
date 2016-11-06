#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("case1.in");
ofstream fout("case1.out");


int main()
{
    int n, copii=0, barbati=0, femei=0;
    int rud1=0,rud2=0,rud3=0;
    fin>>n;
    fin.get();
    int i=1,numar;
    while(i<=n){
        i++;
        fin>>numar;
        fin.get();
        copii+=numar%10;
        numar/=10;
        femei+=numar%10;
        numar/=10;
        barbati+=numar%10;
        numar/=10;
        if(numar==1){
            rud1++;
        }
        else if( numar==2){
            rud2++;
        }
        else{
            rud3++;
        }
    }
    fout<<rud1<<endl;
    fout<<rud2<<endl;
    fout<<rud3<<endl;
    fout<<barbati<<endl;
    fout<<femei<<endl;
    fout<<copii;




}
