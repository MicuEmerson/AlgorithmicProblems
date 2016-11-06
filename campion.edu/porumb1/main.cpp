#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;

ifstream fin("porumb1.in");
ofstream fout("porumb1.out");

int n,x,nrCulPrimu,nrAgri,peCeRand;


int main()
{
    fin>>n>>x;
    int cn=n;
    if(n%2==0)
    {
        nrCulPrimu=n/2;
    }
    else
    {
        nrCulPrimu=n/2+1;
    }
    fout<<nrCulPrimu<<endl;
    if(n==1)
    {
        fout<<"1"<<endl;
    }
    else
    {
        while(n!=1)
        {
            nrAgri++;
            n/=2;
        }
    }
    fout<<nrAgri+1<<endl;
    if(x%2==1)
    {
        fout<<"1"<<endl;
    }
    else
    {
        int ranD=1;
        while(x%2==0)
        {
            x/=2;
            ranD++;
        }
        fout<<ranD<<endl;


    }

    int ultimu=1;
    while(ultimu<cn)
    {
        ultimu*=2;
    }

    fout<<ultimu/2<<endl;





}
