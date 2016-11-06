#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
using namespace std;

ifstream fin("stele1.in");
ofstream fout("stele1.out");




int main()
{
    int n,col,contor=0;
    long long nr=1,k;
    int i,j=0;
    fin>>k>>n;
    if(k==1){
       fout<<"1"<<endl;
    }
    else{
    k=k*k-k+1;
    fout<<k<<endl;
    }

    if(n==1){
        fout<<"1"<<" "<<"1";
       }
    else{
    while(nr*nr-nr+1-contor>n || n>nr*nr-nr+1+contor)
    {
        nr++;
        contor++;
    }
    nr=nr*nr-nr+1;

    fout<<contor+1<<" ";


    col=((contor*2+1)/2)+1;



    if(nr>n)
    {
        while(nr>n)
        {
            col++;
            nr--;
        }
    }
    else
    {
        while(nr<n)
        {
            nr++;
            col--;
        }
    }
    fout<<col;
    }

}
