#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("perechi2.in");
ofstream fout("perechi2.out");
int n,m,cate;
int b[1002];
int a[1002];
int f[1000002];

int main()
{
    int i,j,x;
    fin>>n>>m;
    for(i=1; i<=n; i++)
    {
        fin>>a[i];
    }
    for(i=1; i<=m; i++)
    {
        fin>>b[i];
    }

    for(i=1; i<n; i++)
    {
        for(j=i+1; j<=n; j++)
        {
            f[a[i]+a[j]]++;
        }
    }


    for(i=1; i<m; i++)
    {
        for(j=i+1; j<=m; j++)
        {
            if(f[b[i]+b[j]]>0)
            {
                cate++;
            }
        }
    }
    fout<<cate;




}
