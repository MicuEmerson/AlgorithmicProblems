#include <iostream>
#include <fstream>

using namespace std;

const int MAXN=252;

int a[MAXN][MAXN],n,m,sCol[MAXN][MAXN],sLin[MAXN][MAXN],f[1002],maxy=-((1<<31)-1),poz;



int main()
{

    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            cin>>a[i][j];
            sLin[i][j]+=sLin[i][j-1]+a[i][j];
        }

    for(int j=1; j<=m; j++)
        for(int i=1; i<=n; i++)
        {
            sCol[i][j]=sCol[i-1][j]+a[i][j];
        }

    for(int i=1; i<=n; i++)
    {
        for(int j=i; j<=n; j++)
        {
            poz=sCol[j][1]-sCol[i-1][1];
            for(int k=1; k<=m; k++)
            {



            }
        }
    }

}
