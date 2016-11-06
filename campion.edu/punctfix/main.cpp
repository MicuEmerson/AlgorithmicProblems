#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cmath>
using namespace std;
FILE *fin, *fout;

int n,m,miny=100000001;
int x,f[100001];

int main()
{
    fin=fopen("text.txt","r");
    fout=fopen("punctfix.out","w");

    fscanf(fin,"%d",&n);
    for(int i=1; i<=n; i++)
    {
        fscanf(fin,"%d",&x);
        if(x<0)
        {
            x=(x-2*x)+i;
        }
        else if(x==i)
        {
            x=0;
        }
        else
        {

          x=i-x;

        }
      cout<<x+100000<<endl;
       f[x+100000]++;
        miny=min(x,miny);
    }



    fscanf(fin,"%d",&m);
    for(int i=1; i<=m; i++)
    {
        fscanf(fin,"%d",&x);
       // cout<<f[miny-x]<<"\n";
        fprintf(fout,"%d\n",f[miny-x]);
    }


}







