#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("joctv.in");
ofstream fout("joctv.out");

int n,m,a[102][102],s[102][102], maxy=-((1<<31)-1);


int main()
{
    //citire
    fin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            fin>>a[i][j];

    //sume partiale coloane
    for(int j=1; j<=n; j++)
        for(int i=1; i<=n; i++)
            s[i][j]=s[i-1][j]+a[i][j];

    //solve
    for(int i=1; i<=n; i++)
        for(int j=i; j<=n; j++)
        {
            int adunam=0;
            for(int k=1; k<=n; k++)
            {
                if(adunam>0)
                    adunam+=s[j][k]-s[i-1][k];
                else
                    adunam=s[j][k]-s[i-1][k];

                maxy=max(adunam,maxy);
            }
        }

    fout<<maxy;
}
