#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
FILE *fin, *fout;

int n,f[9001];
pair < int , int > p[9001];

int main()
{
    fin=fopen("creioane.in","r");
    fout=fopen("creioane.out","w");

    fscanf(fin,"%d",&n);
    for(int i=1; i<=n; i++)
    {
        fscanf(fin,"%d%d",&p[i].first,&p[i].second);
        if(p[i].first==0 && p[i].second==0)
        {
            f[i]=1;
        }
    }

    int gasit=1;
    while(gasit==1)
    {
        gasit=0;
        for(int i=1; i<=n; i++)
        {
            if(f[i]==0)
            {
                if(f[p[i].first]>0 && f[p[i].second]>0)
                {
                    f[i]=f[p[i].first]+1;
                    gasit=1;
                }
            }
        }
    }

    int maxy=-1;
    for(int i=1; i<=n; i++)
    {
        maxy=max(f[i],maxy);
    }

    fprintf(fout,"%d",maxy);

}
