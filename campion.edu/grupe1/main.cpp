#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string.h>
#include <cstdlib>
using namespace std;

ifstream fin("grupe1.in");
ofstream fout("grupe1.out");


int main()
{

    int n,k,i,j;
    int v[205];
    char c[255];
    pair < int , int > nrFeteBaieti[205];
    fin>>n>>k;
    for(i=1; i<=n; i++)
    {
        fin>>c[i];
    }

    for(i=1; i<=k; i++)
    {

        fin>>v[i];

        for(j=1; j<=v[i]; j++)
        {

            int x;
            fin>>x;
            if(c[x]=='b')
            {
                nrFeteBaieti[i].first++;
            }
            else
            {
                nrFeteBaieti[i].second++;
            }

        }

    }
    int nrMax=-9999999;
    int nrMin=9999999;
    int ok=1;
    for(i=1; i<=k; i++)
    {
        if(abs(nrFeteBaieti[i].first-nrFeteBaieti[i].second)>1)
        {
            ok=0;
            break;

        }
    }

    for(i=1; i<=k; i++)
    {
        if(v[i]>nrMax)
        {
            nrMax=v[i];
        }
        if(v[i]<nrMin)
        {
            nrMin=v[i];
        }
    }

    for(i=1; i<=k; i++)
    {
        fout<<nrFeteBaieti[i].first<<" "<<nrFeteBaieti[i].second<<endl;
    }
    if(nrMax-nrMin==0  && ok==1 || nrMax-nrMin==1 && ok==1)
    {
        fout<<"DA";
    }
    else
    {
        fout<<"NU";
    }








}
