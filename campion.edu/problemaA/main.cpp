#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <cstdlib>

using namespace std;



void citireMatrice(long long a[100][100], int lin, int col)
{

    int i,j;
    for(i=1; i<=lin; i++)
    {
        for(j=1; j<=col; j++)
        {
            cin>>a[i][j];
        }
    }
}

void afisareMatrice(long long a[100][100], int lin, int col)
{

    int i,j;
    for(i=1; i<=lin; i++)
    {
        for(j=1; j<=col; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void resetare(long long v[105], int n)
{

    for( int i=1; i<=n; i++)
    {
        v[i]=0;
    }
}



int main()
{
    int n,m;
    long long a[100][100];
    long long v[105];
    long long dimV=0,nrMax=-999999999;
    int i,j;


    cin>>n>>m;
    resetare(v,n);

    citireMatrice(a,m,n);
    for(j=1; j<=n; j++)
    {
        dimV++;
        for(i=1; i<=m; i++)
        {
            v[dimV]+=a[i][j];
        }
    }


    for(i=1; i<=dimV; i++)
    {
        if(v[i]>nrMax)
        {
            nrMax=v[i];
        }
    }

    for(i=1; i<=dimV; i++)
    {
        if(v[i]==nrMax)
        {
            cout<<i;
            break;
        }
    }


}
