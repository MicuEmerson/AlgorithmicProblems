#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("prize.in");
ofstream fout("prize.out");

int main()
{
    int n;
   long long s=0;
    int nr;
    fin>>n;
    fin.get();
    for(int i=1;i<=n;i++){
        fin>>nr;
        fin.get();
        s+=nr;

    }
    s=s-n+1;
    fout<<s;

}
