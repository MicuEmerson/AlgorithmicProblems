#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("barca.in");
ofstream fout("barca.out");




int main()
{
    long n;
    fin>>n;
    int i;
    fout<<n*4<<endl;

    for(i=1;i<=n;i++){
       fout<<"IG"<<"\n"<<"I"<<"\n"<<i<<"\n"<<"G"<<"\n";
    }
}
