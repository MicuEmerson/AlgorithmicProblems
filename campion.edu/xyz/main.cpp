#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("xyz.in");
ofstream fout("xyz.out");


int main()
{

    int x,y,z;
    long long numar=0;
    fin>>x>>y>>z;
    int i=2;
    numar=numar*10+y;
    while(i<=x){
        numar=numar*10+z;
        i++;
    }
    fout<<numar;


}
