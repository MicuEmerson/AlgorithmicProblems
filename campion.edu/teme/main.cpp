#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("teme.in");
ofstream fout("teme.out");

int n,m,nrc;
int a[305][305];
int VIZ[305];

void FILL(int v)
{

    VIZ[v]=nrc;

    for(int i=1; i<=n; i++)
    {
        if(a[i][v]==1 && VIZ[i]==0)
        {
            FILL(i);
        }
    }



}


int main()
{   int i;
    fin>>n>>m;
    for(i=1; i<=m; i++)
    {   int x,y;
        fin>>x>>y;
        a[x][y]=a[y][x]=1;
    }
    for(i=1; i<=n; i++)
    {
        if(VIZ[i]==0)
        {
            nrc++;
            FILL(i);
        }
    }
    fout<<nrc;

}
