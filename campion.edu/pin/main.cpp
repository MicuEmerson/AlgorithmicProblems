#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string.h>
using namespace std;

ifstream fin("pin.in");
ofstream fout("pin.out");

int isPrim(int n)
{

    int i,nrDiv;
    for(i=1; i<=n; i++)
    {
        if(n%i==0)
        {
            nrDiv++;
        }
    }
    if(nrDiv==2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int nuContine(int n, int k, int p)
{

    while(n>0)
    {
        if(n%10==p || n%10==k)
        {
            return 0;
        }
        n/=10;
    }
    return 1;

}


int main()
{

    int k,p,i;
    int gasit=0;
    int nr=9999;
    fin>>k>>p;

    while(gasit==0){

        if(nuContine(nr,k,p)==1){
            if(isPrim(nr)==1){
                fout<<nr;
                gasit=1;
            }
        }
        nr--;
    }

}
