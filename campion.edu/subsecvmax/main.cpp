#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdlib>
using namespace std;

ifstream fin("subsecvmax.in");
ofstream fout("subsecvmax.out");




int main()
{
    int n,v[100000],seg,segMax=-999,j,i,indice;
    fin>>n;
    if(n==1){
        fout<<"1"<<" "<<"1";
    }
    else{
    for(i=1; i<=n; i++)
    {
        fin>>v[i];

    }

    for(i=1; i<n; i++)
    {

        j=i;
        seg=1;
        while(v[j]<=v[j+1] && j<n)
        {
            seg++;
            j++;
        }
        if(seg>segMax)
        {
            segMax=seg;
            indice=i;
        }

    }

fout<<indice<<" "<<segMax;
    }
}













