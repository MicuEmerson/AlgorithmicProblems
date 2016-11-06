#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("psp.in");
ofstream fout("psp.out");

int main()
{

    int n,s,x,contor=0;
    int i=1;
    fin>>n>>s;
    fin.get();

    while(i<=n){
        i++;
        fin>>x;
        if(x<=s){
            s=s-x;
            contor++;
        }
    }
    fout<<contor<<" "<<s;


}
