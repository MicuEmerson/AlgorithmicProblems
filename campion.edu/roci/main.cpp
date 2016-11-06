#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
using namespace std;
FILE *fin, *fout;

int f[10001],n,dim,a;

int main()
{

    fin=fopen("roci.in","r");
    fout=fopen("roci.out","w");
    fscanf(fin,"%d",&n);

    for(int i=1; i<=n; i++)
    {
        fscanf(fin,"%d",&a);
        if(f[a-1]==0)
        {
            dim++;
            f[a]++;
        }S
        else
        {
            f[a]++;
            f[a-1]--;
        }
    }


fprintf(fout,"%d",dim);
}
