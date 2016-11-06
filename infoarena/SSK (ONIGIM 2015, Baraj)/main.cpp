#include <bits/stdc++.h>

using namespace std;

ifstream fin("ssk.in");
ofstream fout("ssk.out");

int n, m, k, x;
int s[152][152];
int v[22500000], dim;


int main()
{
    fin>>n>>m>>k;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            fin>>x;
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+x;
        }

    for(int i=1; i<=n; i++)
    {
        for(int ii=i; ii<=n; ii++)
        {
            for(int j=1; j<=m; j++)
            {
                for(int jj=j; jj<=m; jj++)
                {
                    v[++dim]= s[ii][jj] - s[i-1][jj] - s[ii][j-1] + s[i-1][j-1];

                }
            }
        }
    }
    sort(v+1,v+dim+1);
    fout<<v[k];

}
