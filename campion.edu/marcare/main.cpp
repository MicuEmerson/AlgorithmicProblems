#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("marcare.in");
ofstream fout("marcare.out");


int main()
{
    int n,s,k,scadere,i,ck,contor=0;
    int v[255], f[255];
    fin>>n>>s>>k;
    for(i=1; i<=n; i++)
    {
        v[i]=i;
        f[i]=0;
    }

    i=s;

    while(f[i]==0)
    {
        f[i]=1;
        contor++;
        fout<<i<<" ";
        if(i+k<=n)
        {
            i=i+k;
        }
        else
        {
          i=n-i;
          i=k-i;

        }
    }
    fout<<endl;
    fout<<n-contor;

}
