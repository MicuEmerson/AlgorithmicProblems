#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
FILE *fin, *fout;

int n;
long long a[1002];
long long b[1002];
pair <int , long long > p[1002];

int main()
{

    fin=fopen("triunghi4.in","r");
    fout=fopen("triunghi4.out","w");

    fscanf(fin,"%d",&n);

    for(int i=n; i>=1; i--)
    {
        fscanf(fin,"%d%lld",&p[i].first,&p[i].second);
    }

    a[p[1].first]=p[1].second;


    for(int i=2; i<=n; i++)
    {
        b[p[i].first]=p[i].second;

        for(int j=p[i].first-1; j>=1; j--)
        {
            b[j]=a[j]-b[j+1];
        }
        for(int j=p[i].first+1; j<=n; j++)
        {
            b[j]=a[j-1]-b[j-1];
        }
        for(int j=1; j<=i; j++)
        {
            a[j]=b[j];
        }
    }
    for(int i=1; i<=n; i++)
    {
        fprintf(fout,"%lld ",a[i]);
    }

}














