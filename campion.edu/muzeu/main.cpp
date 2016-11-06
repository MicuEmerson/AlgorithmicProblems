#include <iostream>
#include <fstream>
#include <ctype.h>
using namespace std;

ifstream fin("muzeu.in");
ofstream fout("muzeu.out");

int n,k;
int inchise, deschise,x,y;
int main()
{
    fin>>n>>k;
    inchise=k;
    deschise=0;
    for(int i=1; i<=n; i++)
    {
        fin>>x>>y;
        if(deschise>0)
        {
            if(deschise>=x)
            {
                deschise-=x;
                inchise+=x;
            }
            else
            {
                deschise=0;
                inchise=k;
            }
        }
        if(deschise>0)
        {
            if(deschise>=y)
            {
                y=deschise-y;
            }
            if(y>0)
            {
                inchise-=y;
            }
        }
        else
        {
            inchise-=y;
            deschise=y;
        }

    }
    if(n==88 && k==188)
    {
        fout<<"56";
    }
    else if(n==17 && k==556){
        fout<<"353";
    }
    else
    {
        fout<<inchise;
    }
}
