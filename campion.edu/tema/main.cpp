#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("tema.in");
ofstream fout("tema.out");

int main()
{
    int v[100],f[100];
    int i;
    int n,m;
    fin>>n;
    fin.get();
    fin>>m;
    fin.get();
    for(i=1;i<=n;i++){
        f[i]=1;
    }
    for(i=1;i<=m;i++){
        fin>>v[i];
        f[v[i]]=0;
    }
    for(i=1;i<=n;i++){
        if(f[i]!=0){
            fout<<i<<" ";
        }
    }
}
