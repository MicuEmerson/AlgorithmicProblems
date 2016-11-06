#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("conturi.in");
ofstream fout("conturi.out");



int main()
{
    int n,x;
    long numar;
    fin>>n>>x;
    fin.get();
    int sumaMax=-99999;
    for(int i=1;i<=n;i++){
        fin>>numar;
        if(numar/100000==x){
            if((numar/10000) % 10==1){
                if(numar % 10000 > sumaMax){
                    sumaMax=numar % 10000;
                }
            }
        }

    }
    fout<<sumaMax;



}
